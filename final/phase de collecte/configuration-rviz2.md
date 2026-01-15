---
outline: { level: [2,3] }
outlineImage: /final/images/phase de collecte/rviz2.png
---

# Configuration RViz2

## Qu'est-ce que RViz2 ?

**RViz2** (ROS Visualization 2) est l'outil de visualisation 3D officiel de ROS2 (Robot Operating System 2). C'est un environnement graphique interactif qui permet de visualiser en temps réel l'état complet d'un robot et de son environnement.

### Utilité pour le projet TRC 2025

RViz2 sera notre outil central pour :

1. **Phase de développement** :
   - Vérifier que tous les capteurs (caméra, LIDAR) fonctionnent correctement
   - Visualiser les données en temps réel pour comprendre ce que "voit" le robot
   - Déboguer les algorithmes de perception et de navigation
   - Tester les mouvements du robot avant de les déployer sur le terrain

2. **Phase de test** :
   - Valider la détection des déchets via la caméra
   - Vérifier l'évitement d'obstacles avec le LIDAR
   - Suivre les trajectoires de navigation autonome
   - Analyser les performances du robot

3. **Phase de démonstration** :
   - Présenter visuellement le fonctionnement du robot
   - Montrer les données capteurs en direct
   - Expliquer les décisions prises par les algorithmes

### Interface RViz2

L'interface de RViz2 se compose de plusieurs panneaux :
- **Vue 3D principale** : Affichage du robot et de son environnement
- **Panneau Displays** : Configuration des éléments à visualiser
- **Panneau Time** : Contrôle de la synchronisation temporelle
- **Panneau Tool Properties** : Outils d'interaction (sélection, mesure, navigation)

### Pourquoi RViz2 est essentiel pour notre robot

Sans RViz2, nous serions "aveugles" :
- ❌ Impossible de voir ce que détecte la caméra
- ❌ Impossible de vérifier si le LIDAR fonctionne correctement
- ❌ Difficile de déboguer les problèmes de navigation
- ❌ Pas de visualisation pour comprendre les décisions du robot

C'est pourquoi la configuration correcte de RViz2 est une étape cruciale avant de commencer le développement des algorithmes autonomes pour la collecte de déchets.

## Lancement de RViz2

### Prérequis

Avant de lancer RViz2, assurez-vous que :
- Vous êtes connecté au Rosmaster X3 (SSH ou bureau à distance)
- Le workspace ROS2 est correctement compilé
- Vous êtes dans le répertoire du workspace

### ⚠️ IMPORTANT : Lancer la description du robot D'ABORD

**RViz2 a besoin de connaître la structure du robot pour fonctionner.** Vous devez TOUJOURS lancer la description du robot avant d'ouvrir RViz2.

#### ÉTAPE 1 : Lancer la description du robot (OBLIGATOIRE)

```bash
# Se placer dans le workspace ROS2
cd ~/trc_ws

# Sourcer l'environnement ROS2
source install/setup.bash

ros2 launch x3_description x3_description.launch.py
```

**Ce que fait cette commande :**
- Publie la description URDF du robot sur le topic `/robot_description`
- Lance le `robot_state_publisher` qui publie les transformations (TF)
- Lance le `joint_state_publisher` qui gère les articulations
- Rend disponibles tous les frames : `base_footprint`, `camera_link`, `lidar_link`, etc.

**Laissez ce terminal ouvert** - il doit rester actif pendant toute la session RViz2.

**Note pour la simulation Gazebo :** Si vous utilisez Gazebo pour la simulation, lancez avec `use_sim_time:=true` :
```bash
ros2 launch x3_description x3_description.launch.py use_sim_time:=true
```

**ÉTAPE 1.5 : Lancer les capteurs (recommandé pour visualisation complète)**

Pour visualiser les données des capteurs dans RViz2, lancez les drivers appropriés :

**RPLIDAR (pour LaserScan)** :
```bash
# Ouvrez un nouveau terminal
ros2 launch rplidar_ros rplidar_a1_launch.py frame_id:=laser_frame
```

**Caméra Astra (pour Image)** :
```bash
# Ouvrez un nouveau terminal  
ros2 launch astra_camera astra.launch.xml
```

**Ce que font ces commandes :**
- RPLIDAR : Publie les données de scan laser sur le topic `/scan`
- Caméra Astra : Publie les flux vidéo sur `/camera/color/image_raw`, `/camera/depth/image_rect_raw`, etc.

**Note** : Si les capteurs ne sont pas connectés physiquement, RViz2 affichera des erreurs de souscription, mais la configuration du robot reste fonctionnelle.

### Commandes de lancement simplifiées

**Option 1 : Lancement automatique (recommandé)**

Lancez le robot et la caméra en une commande :

```bash
cd ~/trc_ws
source install/setup.bash
ros2 launch x3_description trc_visualization.launch.py
```

**Ce que fait cette commande :**
- Lance la description du robot (URDF, TF)
- Démarre la caméra Astra sur `/camera/...`
- Lance le RPLIDAR A1 sur `/scan` avec frame_id `laser_frame`
- Ouvre RViz2 automatiquement avec la configuration `~/.rviz2/default.rviz`

**Avantages :** Tout est lancé en une seule commande, aucune configuration supplémentaire nécessaire.

**Détails techniques :**
- **Fichier créé :** `trc_visualization.launch.py`
- **Emplacement :** `src/rosmaster/x3_description/launch/`
- **Code contenu :**
  ```python
  from launch import LaunchDescription
  from launch.actions import IncludeLaunchDescription
  from launch.launch_description_sources import PythonLaunchDescriptionSource, AnyLaunchDescriptionSource
  from launch.substitutions import PathJoinSubstitution
  from launch_ros.substitutions import FindPackageShare
  from launch_ros.actions import Node
  import os

  def generate_launch_description():
      rviz_config_path = os.path.expanduser('~/.rviz2/default.rviz')

      return LaunchDescription([
          # Description du robot
          IncludeLaunchDescription(
              PythonLaunchDescriptionSource(
                  PathJoinSubstitution([
                      FindPackageShare('x3_description'),
                      'launch/x3_description.launch.py'
                  ])
              )
          ),

          # Caméra Astra
          IncludeLaunchDescription(
              AnyLaunchDescriptionSource(
                  PathJoinSubstitution([
                      FindPackageShare('astra_camera'),
                      'launch/astra.launch.xml'
                  ])
              )
          ),

          # RPLIDAR A1
          IncludeLaunchDescription(
              PythonLaunchDescriptionSource(
                  PathJoinSubstitution([
                      FindPackageShare('rplidar_ros'),
                      'launch/rplidar_a1_launch.py'
                  ])
              ),
              launch_arguments={'frame_id': 'laser_frame'}.items()
          ),

          # RViz
          Node(
              package='rviz2',
              executable='rviz2',
              name='rviz2',
              output='screen',
              arguments=['-d', rviz_config_path],
          ),
      ])
  ```

**Option 2 : Lancement manuel (pour débogage)**

Si vous préférez contrôler chaque composant séparément :

**Terminal 1 :**
```bash
cd ~/trc_ws
source install/setup.bash
ros2 launch x3_description x3_description.launch.py  # Garde ce terminal ouvert
```

**Terminal 2 :**
```bash
cd ~/trc_ws
source install/setup.bash
ros2 launch rplidar_ros rplidar_a1_launch.py frame_id:=laser_frame
```

**Terminal 3 :**
```bash
cd ~/trc_ws
source install/setup.bash
ros2 launch astra_camera astra.launch.xml
```

**Terminal 4 :**
```bash
cd ~/trc_ws
source install/setup.bash
rviz2 -d ~/.rviz2/default.rviz
```

**Option 3 : Lancement alternatif avec interface graphique**

Si vous voulez une interface pour contrôler manuellement les joints du robot :

```bash
ros2 launch x3_description display_plus.launch.py
```

**Ce que fait cette commande :**
- Lance la description du robot (URDF, TF)
- Démarre la caméra Astra sur `/camera/...`
- Lance le RPLIDAR A1 sur `/scan` avec frame_id `laser_frame`
- Ouvre RViz2 automatiquement avec la configuration `~/.rviz2/default.rviz`
- Lance `joint_state_publisher_gui` pour contrôler les joints interactivement

**Avantages :**
- Interface graphique pour ajuster les positions des joints (roues, etc.) en temps réel
- Paramètre `gui` pour basculer entre interface graphique et mode simple
- Arguments pour personnaliser le modèle URDF et la config RViz
- Tout dans un seul fichier de lancement

**Détails techniques :**
- **Fichier créé :** `display_plus.launch.py`
- **Emplacement :** `src/rosmaster/x3_description/launch/`
- **Code contenu :** Basé sur `display_X3.launch.py`, inclut robot_state_publisher, joint_state_publisher_gui, RPLIDAR, caméra Astra et RViz. Utilise `rosmaster_x3.urdf.xacro` comme modèle URDF.

### Première ouverture

Lors de la première ouverture, RViz2 affiche une fenêtre avec :
- Une vue 3D vide au centre
- Le panneau **Displays** à gauche
- Les panneaux **Views** et **Time** à droite
- Une barre d'outils en haut

**Maintenant vous devriez voir** plusieurs frames disponibles dans le menu déroulant Fixed Frame (base_footprint, camera_link, etc.)

## Configuration initiale de RViz2

### Étape 2 : Configuration du référentiel fixe (Fixed Frame)

Le **Fixed Frame** est le point de référence pour toutes les visualisations. C'est comme le "centre du monde" pour RViz2.

1. Dans le panneau **Displays**, cherchez **Global Options**
2. Trouvez le paramètre **Fixed Frame**
3. Changez la valeur de `map` à `base_footprint`

**Pourquoi `base_footprint` ?**
- C'est le référentiel au sol, sous le centre du robot
- Tous les capteurs du robot sont définis par rapport à ce point
- Cela permet de visualiser le robot dans son propre référentiel

### Étape 3 : Ajout de la grille de référence

La grille aide à visualiser l'espace et les distances.

1. Cliquez sur le bouton **Add** en bas du panneau Displays
2. Dans l'onglet **By display type**, sélectionnez **Grid**
3. Cliquez **OK**

**Configuration de la grille** :
- **Reference Frame** : `base_footprint` (automatique si Fixed Frame configuré)
- **Plane Cell Count** : `10` (pour une grille 10×10)
- **Cell Size** : `1` (1 mètre par case)
- **Color** : Gris clair (160; 160; 164)

### Étape 4 : Ajout du modèle 3D du robot

1. Cliquez sur **Add**
2. Sélectionnez **RobotModel**
3. Cliquez **OK**

**Configuration RobotModel** :
- Cliquez sur le champ **Description Topic** pour afficher la liste des topics disponibles
- Sélectionnez `/robot_description` dans la liste déroulante
- **Visual Enabled** : Coché (pour voir le modèle visuel)
- **Collision Enabled** : Non coché (optionnel)

**Résultat attendu** : Le modèle 3D du Rosmaster X3 apparaît au centre de la grille.

### Étape 5 : Ajout de l'arbre des transformations (TF)

Pour visualiser la hiérarchie des transformations entre les différents frames du robot :

1. Cliquez sur **Add**
2. Sélectionnez **TF**
3. Cliquez **OK**

**Configuration TF** :
- **Show Names** : Coché (pour voir les noms des frames)
- **Show Axes** : Coché (pour voir les axes de coordonnées)
- **Show Arrows** : Coché (pour voir les relations parent-enfant)
- **Marker Scale** : `0.3` (taille des marqueurs)
- **Update Interval** : `0` (mise à jour en temps réel)

### Étape 6 : Ajout de la visualisation LIDAR

Pour visualiser les données du RPLIDAR :

1. Cliquez sur **Add**
2. Sélectionnez **LaserScan**
3. Cliquez **OK**

**Configuration LaserScan** :
- **Topic** : `/scan` (topic des données LIDAR)
- **Size (m)** : `0.1` (taille des points)
- **Color Transformer** : `FlatColor` (couleur uniforme)
- **Color** : Bleu (0; 0; 255)

### Étape 7 : Ajout de la visualisation caméra

Pour visualiser le flux de la caméra Astra :

1. Cliquez sur **Add**
2. Sélectionnez **Image**
3. Cliquez **OK**

**Configuration Image** :
- **Topic** : `/camera/color/image_raw` (flux couleur de la caméra)
- **Transport Hint** : `raw` (transport brut)

**Note** : Si vous voulez voir la profondeur, ajoutez un autre display Image avec le topic `/camera/depth/image_rect_raw`.

### Étape 8 : Configuration de la vue

Pour ajuster et configurer la vue du robot :

1. **Ajustement manuel** :
   - Utilisez la **molette de la souris** pour zoomer/dézoomer
   - **Clic gauche maintenu** + déplacer : tourner autour du robot
   - **Clic milieu maintenu** + déplacer : déplacer la vue
   - **Shift + clic gauche** : déplacer la caméra

2. **Configuration dans le panneau Views** :
   - Allez dans **Views** → **Current View**
   - **Type** : Orbit (vue orbitale autour du robot)
   - **Target Frame** : `base_footprint`
   - **Distance** : `3` à `5` mètres
   - **Pitch** : `0.785` (45° vers le bas)
   - **Yaw** : `0.785` (45° de rotation)

**Vue recommandée** :
- Distance : ~2-3 mètres
- Angle : Vue en perspective à 45° (pour voir le robot en 3D)
- Position : Le robot au centre de l'écran

## Sauvegarde de la configuration

**RViz2 sauvegarde automatiquement votre configuration** dans `~/.rviz2/default.rviz` à chaque fermeture propre. Cela permet de :
- Retrouver exactement la même configuration au prochain lancement
- Gagner du temps lors des sessions suivantes
- Avoir une config par défaut fonctionnelle

**Note** : Si vous voulez sauvegarder une config personnalisée, utilisez **File** → **Save Config As** et choisissez un nom spécifique.

### Chargement de la configuration sauvegardée

**Méthode 1 : Depuis RViz2 (chargement automatique)**
- RViz2 charge automatiquement `~/.rviz2/default.rviz` au lancement
- Si vous avez une config personnalisée : **File** → **Open Config** → sélectionnez votre fichier

**Méthode 2 : Directement au lancement (recommandé)**

```bash
# Lancer RViz2 avec la configuration par défaut
rviz2 -d ~/.rviz2/default.rviz
```

**Méthode 3 : Créer un alias pour faciliter le lancement**

```bash
# Ajouter au fichier ~/.bashrc
echo 'alias rviz-robot="source ~/trc_ws/install/setup.bash && rviz2 -d ~/.rviz2/default.rviz"' >> ~/.bashrc

# Recharger le fichier
source ~/.bashrc

# Maintenant, lancez simplement avec :
rviz-robot
```

### Vérification de la configuration

Après la sauvegarde et le rechargement, vérifiez que :
- ✅ Le Fixed Frame est bien `base_footprint`
- ✅ La grille est visible
- ✅ Le modèle du robot s'affiche
- ✅ La vue est positionnée comme vous l'aviez configurée

**Configuration de base terminée !** Vous avez maintenant une visualisation fonctionnelle du robot. Dans les sections suivantes, nous ajouterons les displays pour les capteurs (caméra, LIDAR).
