# Téléopération

## Qu'est-ce que la téléopération ?

La **téléopération** permet de contrôler le robot Rosmaster X3 **manuellement** à distance à l'aide d'une manette de jeu ou du clavier. C'est une étape essentielle de la phase de collecte du TRC 2025 car elle permet de :

- **Tester le robot** avant l'autonomie
- **Collecter des données** de capteurs (caméra, LIDAR, IMU)
- **Explorer l'environnement** de manière contrôlée
- **Déboguer** les systèmes de contrôle moteur

## Méthodes de contrôle

### Manette sans fil
- **Connexion** : Brancher un adaptateur Bluetooth USB sur la Raspberry Pi
- **Appairage** : Allumer la manette en mode appairage
- **Vérification** : `ls /dev/input/js*` doit afficher `/dev/input/js0`

### Clavier du PC
- **Connexion** : Utiliser le clavier de l'ordinateur qui contrôle le robot
- **Interface** : Contrôle via terminal ROS2 sur le PC

## Démarrage des moteurs : Problème initial

### Recherche du fichier de lancement
Au début du projet, nous avons trouvé le fichier de lancement pour démarrer les **noeuds moteurs** du robot X3 dans le package `yahboomcar_bringup`.

**Fichier trouvé :** `yahboomcar_bringup_X3_launch.py`

### Problèmes rencontrés
Le fichier existait mais **le package `yahboomcar_bringup` lui-même n'était pas trouvé** par ROS2.

**Erreur obtenue :** `Package 'yahboomcar_bringup' not found: "package 'yahboomcar_bringup' not found, searching: ['/opt/ros/humble']"`

Cela signifie que le package n'était pas installé dans l'environnement ROS2 ou pas dans le workspace.

### Conséquence critique
**Sans les noeuds moteurs démarrés, la téléopération ne fonctionnait pas :**
- ❌ La manette publiait sur `/joy`
- ❌ Le noeud `yahboom_joy_X3.py` recevait les commandes
- ❌ Les commandes étaient publiées sur `/cmd_vel`
- ❌ **Mais le robot ne bougeait pas** car aucun driver moteur n'écoutait `/cmd_vel`

### Solution développée
Nous avons créé notre propre **système complet** pour remplacer le système manquant :

#### x3_bringup.launch.py : Lanceur principal unifié
**Rôle :** Fichier de lancement principal qui orchestre tous les composants du robot
- Lance la description URDF du robot (géométrie 3D)
- Démarre le driver moteur Mcnamu_driver_X3
- Active le calcul d'odométrie
- Configure le filtrage IMU
- Met en place la fusion EKF
- Intègre le contrôle joystick
- Optionnellement lance RViz pour la visualisation

#### odometry_node.py : Calcul de l'odométrie
**Rôle :** Calcule la position et vitesse du robot depuis les encodeurs des roues
- S'abonne au topic `/joint_states` (positions des roues)
- Calcule la distance parcourue par chaque roue
- Estime la pose (position + orientation) du robot
- Publie sur `/odom` (odométrie brute)
- Publie les transformations TF (odom → base_footprint)

#### ekf_config.yaml : Configuration EKF
**Rôle :** Configure le filtre de Kalman étendu pour fusionner les capteurs
- Définit les sources de données (odométrie + IMU)
- Configure la fréquence de fusion (30 Hz)
- Spécifie les covariances des capteurs
- Publie sur `/odometry/filtered` (odométrie fusionnée)

#### CMakeLists.txt : Configuration de compilation
**Rôle :** Intègre les nouveaux fichiers dans le système de build ROS2
- Déclare les dépendances Python
- Configure l'installation des scripts
- Permet la compilation avec `colcon build`

## Problème des conflits de description

### Conflit identifié
Lorsque nous lancions `x3_bringup.launch.py` ET `trc_visualization.launch.py` simultanément, nous obtenions des **conflits de description URDF** :

- **Deux robot_state_publisher** actifs sur `/robot_description`
- **Deux joint_state_publisher** actifs sur `/joint_states`
- **Transformations TF dupliquées** causant des erreurs

### Solution mise en place
Nous avons ajouté une **option conditionnelle** dans `trc_visualization.launch.py` :

```python
# Argument pour contrôler la description
include_description_arg = DeclareLaunchArgument(
    'include_description',
    default_value='true',
    description='Inclure la description du robot (désactiver si déjà lancé ailleurs)'
)

# Inclusion conditionnelle
IncludeLaunchDescription(
    PythonLaunchDescriptionSource(...),
    condition=conditions.IfCondition(LaunchConfiguration('include_description'))
)
```

### Utilisation résolue
**Lancement combiné sans conflit :**
```bash
# Terminal 1 : Contrôle complet (avec description)
ros2 launch x3_control x3_bringup.launch.py use_joystick:=true

# Terminal 2 : Visualisation seule (sans description dupliquée)
ros2 launch x3_description trc_visualization.launch.py include_description:=false
```

Cette solution permet de **lancer contrôle + visualisation** sans conflits de description URDF.

## Choix de l'approche conditionnelle

Nous avons considéré deux approches pour résoudre les conflits de description :

### Option 1 : Unification complète
**Intégrer `trc_visualization` directement dans `x3_bringup`** :
- ✅ Un seul fichier à lancer pour tout
- ✅ Pas de risque de conflit
- ⚠️ RViz toujours lancé (consomme des ressources)
- ⚠️ Moins modulaire pour les tests

### Option 2 : Séparation conditionnelle (choisie)
**Garder deux fichiers avec option conditionnelle** :
- ✅ **Modularité** : Chaque fichier a un rôle clair
- ✅ **Flexibilité** : Lanceur visualisation réutilisable seul
- ✅ **Tests faciles** : Contrôle ou visualisation indépendants
- ⚠️ Nécessite de spécifier `include_description:=false`

**Choix justifié :** L'approche conditionnelle offre plus de **flexibilité pour le développement** et permet de lancer les composants séparément pour les tests et le débogage.

## Lancement de la téléopération

### Avec manette
```bash
# Lancement complet : moteurs + odométrie + IMU + EKF + joystick
ros2 launch x3_control x3_bringup.launch.py use_joystick:=true
```

### Avec clavier
```bash
# Terminal 1 : Lancement des moteurs et odométrie (joystick désactivé)
ros2 launch x3_control x3_bringup.launch.py use_joystick:=false

# Terminal 2 : Contrôle clavier
ros2 run x3_control yahboom_keyboard.py
```

**Note :** `use_joystick:=false` est la valeur par défaut, donc `ros2 launch x3_control x3_bringup.launch.py` suffit.

## Commandes de lancement principales

### Téléopération complète (recommandé)
```bash
cd ~/trc_ws
source install/setup.bash

# Lancement unique : moteurs + odométrie + IMU + EKF + joystick
ros2 launch x3_control x3_bringup.launch.py use_joystick:=true
```

### Téléopération + Visualisation
```bash
# Terminal 1 : Contrôle du robot
ros2 launch x3_control x3_bringup.launch.py use_joystick:=true

# Terminal 2 : Visualisation (caméra + LIDAR + RViz)
ros2 launch x3_description trc_visualization.launch.py include_description:=false
```

### Mode débogage séparé
```bash
# Terminal 1 : Description du robot seulement
ros2 launch x3_description x3_description.launch.py

# Terminal 2 : Moteurs + odométrie + IMU + EKF
ros2 launch x3_control x3_bringup.launch.py use_joystick:=false

# Terminal 3 : Contrôle clavier
ros2 run x3_control yahboom_keyboard.py

# Terminal 4 : Visualisation
ros2 launch x3_description trc_visualization.launch.py include_description:=false
```

### Compilation après modification
```bash
cd ~/trc_ws
colcon build --packages-select x3_control
source install/setup.bash
```

### Avec visualisation
```bash
# Terminal 1 : Contrôle + visualisation
ros2 launch x3_control x3_bringup.launch.py use_joystick:=true

# Terminal 2 : Visualisation capteurs (sans conflit description)
ros2 launch x3_description trc_visualization.launch.py include_description:=false
```

<!-- Suite à rédiger : commandes, lancement, débogage -->