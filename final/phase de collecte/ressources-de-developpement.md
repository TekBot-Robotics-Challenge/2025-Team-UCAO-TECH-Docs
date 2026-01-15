---
outline: { level: [2,3] }
outlineImage: /final/images/phase de collecte/OIP.webp
---

# Ressources de développement

## Présentation du dépôt

L'équipe TEKBOT Robotics Challenge (TRC) a fourni à l'équipe UCAO-TECH Bénin les ressources de base nécessaires pour programmer le fonctionnement du robot Rosmaster X3. Ce dépôt constitue l'environnement de développement officiel pour la phase finale de la compétition TRC 2025, permettant aux équipes participantes de développer leurs solutions de robotique mobile autonome.

Le dépôt est accessible à l'emplacement suivant sur le système de développement :

```
/home/trc2k25/2025-ROS-Ressources
```

Il est également possible de cloner ce dépôt depuis le référentiel officiel :

```bash
git clone https://github.com/TekBot-Robotics-Challenge/2025-ROS-Ressources.git
```

## Installation et configuration

### Compilation du workspace

Le dépôt inclut un script de configuration automatique (`configure.sh`) qui simplifie le processus d'installation. Ce script crée et compile automatiquement un workspace ROS2 nommé `trc_ws`, puis configure l'environnement pour l'utilisation.

```bash
cd 2025-ROS-Ressources
source configure.sh
```

**Ce que fait le script :**
- Crée le workspace `trc_ws` s'il n'existe pas
- Compile tous les packages ROS2 contenus dans le dépôt avec `colcon build`
- Configure les variables d'environnement ROS2 (sourcing automatique)
- Déplace le terminal à la racine du workspace pour un accès rapide

### Lancement de la simulation

Une fois l'installation terminée, vous pouvez lancer l'environnement de simulation Gazebo avec l'arène TRC 2025 et le robot Rosmaster X3.

**Sans GPU (mode CPU) :**
```bash
ros2 launch sim_trc sim_trc_no_gpu.launch.py
```

**Avec GPU (accélération matérielle) :**
```bash
ros2 launch sim_trc sim_trc.launch.py
```

Après le lancement de la simulation, vous pouvez contrôler le robot Rosmaster X3 avec une manette de jeu (joystick).

## Environnement de développement

### Workspace de travail

**Important :** Le développement se fait dans le workspace ROS2 `trc_ws` créé par le script `configure.sh`, et non directement dans le dépôt source `/home/trc2k25/2025-ROS-Ressources`.

**Structure après configuration :**
```
trc_ws/                    # Workspace de développement (créé par configure.sh)
├── src/                   # Sources des packages (liés depuis le dépôt)
├── build/                 # Fichiers de compilation
├── install/               # Packages installés et configurés
└── log/                   # Logs de compilation
```

**Pour travailler :**
```bash
# Après avoir exécuté configure.sh, vous êtes automatiquement dans trc_ws
# Le sourcing est déjà fait, vous pouvez directement utiliser ROS2

# Exemple : contrôler le robot par clavier
ros2 run x3_control yahboom_keyboard.py

# Modifier le code source
cd src/x3_control
# Éditer les fichiers Python...

# Recompiler après modifications
colcon build --symlink-install
```

**Exemples supplémentaires :**
```bash
# Lister les topics actifs
ros2 topic list

# Tester la caméra Astra (si connectée)
ros2 launch astra_camera astra.launch.xml

# Tester le LIDAR RPLidar (si connecté)
ros2 launch rplidar_ros rplidar.launch.py
```

Le workspace `trc_ws` est votre environnement de développement principal où vous pouvez :
- Modifier le code source des packages
- Tester vos modifications
- Compiler et installer les changements
- Lancer les simulations et applications

## Structure du dépôt

```
2025-ROS-Ressources/
├── README.md
├── assets
│   └── sim_trc_2025.png
├── configure.sh
├── drivers
│   ├── py_install_V3.3.9
│   │   └── py_install
│   ├── ros2_astra_camera
│   │   ├── README.MD
│   │   ├── astra_camera
│   │   └── astra_camera_msgs
│   ├── rplidar_ros
│   │   ├── CMakeLists.txt
│   │   ├── LICENSE
│   │   ├── README.md
│   │   ├── debian
│   │   ├── include
│   │   ├── launch
│   │   ├── package.xml
│   │   ├── rplidar_A1.png
│   │   ├── rplidar_A2.png
│   │   ├── rviz
│   │   ├── scripts
│   │   ├── sdk
│   │   └── src
│   └── yahboomcar_bringup
│       ├── launch
│       ├── package.xml
│       ├── param
│       ├── resource
│       ├── rviz
│       ├── setup.cfg
│       ├── setup.py
│       ├── test
│       └── yahboomcar_bringup
├── rosmaster
│   ├── x3_control
│   │   ├── CMakeLists.txt
│   │   ├── LICENSE
│   │   ├── package.xml
│   │   └── x3_control
│   └── x3_description
│       ├── CMakeLists.txt
│       ├── LICENSE
│       ├── config
│       ├── launch
│       ├── meshes
│       ├── package.xml
│       ├── rviz
│       └── urdf
├── sim_trc
│   ├── CMakeLists.txt
│   ├── LICENSE
│   ├── launch
│   │   ├── sim_trc.launch.py
│   │   └── sim_trc_no_gpu.launch.py
│   ├── models
│   │   ├── arene_base
│   │   ├── arene_frame
│   │   ├── arm
│   │   ├── convoyeur
│   │   ├── dangereux_commerciale_* (15 modèles)
│   │   ├── dangereux_industrielle_* (15 modèles)
│   │   ├── dangereux_residentielle_* (17 modèles)
│   │   ├── menagers_commerciale_* (15 modèles)
│   │   ├── menagers_industrielle_* (15 modèles)
│   │   ├── menagers_residentielle_* (15 modèles)
│   │   ├── recyclables_commerciale_* (14 modèles)
│   │   ├── recyclables_industrielle_* (15 modèles)
│   │   ├── recyclables_residentielle_* (15 modèles)
│   │   ├── pancarte_qr_code_* (10 modèles)
│   │   └── qr_code_zone* (10 modèles)
│   ├── package.xml
│   └── worlds
│       ├── trc2k25_arena.world
│       └── trc2k25_arena_no_gpu.world
└── udev rules
    ├── 56-orbbec-usb.rules
    └── usb.rules

201 directories, 28 files
```

## Description des dossiers

### drivers/

Ce dossier regroupe tous les drivers et pilotes nécessaires pour interfacer les différents capteurs et périphériques du robot Rosmaster X3 avec ROS2.

**Contenu :**

- **py_install_V3.3.9/** : Installation Python pour les dépendances du système
  
- **ros2_astra_camera/** : Driver ROS2 pour les caméras Orbbec Astra
  - `astra_camera/` : Package principal du driver caméra
  - `astra_camera_msgs/` : Messages ROS2 personnalisés pour la caméra Astra
  - Permet l'acquisition d'images RGB-D (couleur + profondeur) pour la perception visuelle du robot

- **rplidar_ros/** : Driver ROS2 pour le LIDAR RPLidar
  - Compatible avec les modèles RPLidar A1, A2 et A3
  - Fournit les données de scan laser 360° pour la navigation et l'évitement d'obstacles
  - Inclut les fichiers de lancement, configuration et visualisation RViz

- **yahboomcar_bringup/** : Package de lancement et configuration du robot Yahboom
  - Scripts de démarrage pour initialiser tous les composants du robot
  - Fichiers de paramètres de configuration
  - Fichiers RViz pour la visualisation
  - Gère le démarrage coordonné de tous les drivers et nœuds ROS2

### rosmaster/

Dossier contenant les packages spécifiques au robot Rosmaster X3, incluant sa description mécanique et ses contrôleurs.

**Contenu :**

- **x3_control/** : Package de contrôle du robot Rosmaster X3
  - Contrôleurs pour la base mobile (moteurs, roues)
  - Interface de commande des mouvements (vitesse linéaire/angulaire)
  - Gestion des actionneurs du bras manipulateur
  - Nœuds ROS2 pour le contrôle bas niveau

- **x3_description/** : Description URDF du robot Rosmaster X3
  - Fichiers URDF (Unified Robot Description Format) définissant la structure du robot
  - Modèles 3D (meshes) pour la visualisation
  - Configurations des liens cinématiques et des joints
  - Fichiers de lancement pour afficher le modèle dans RViz
  - Paramètres physiques (masses, inerties, limites de mouvement)

### sim_trc/

Package principal de simulation Gazebo pour la compétition TRC 2025. Contient l'environnement virtuel complet de l'arène et tous les modèles 3D de déchets.

**Contenu :**

- **launch/** : Fichiers de lancement de la simulation
  - `sim_trc.launch.py` : Lancement avec accélération GPU
  - `sim_trc_no_gpu.launch.py` : Lancement sans GPU (mode CPU uniquement)

- **models/** : Collection complète de modèles 3D pour la simulation
  - **Éléments d'arène** : `arene_base`, `arene_frame`, `convoyeur`, `arm`
  - **Déchets dangereux** (~47 modèles) :
    - Commerciaux : batteries, cartouches, écrans cassés, produits chimiques
    - Industriels : acides, amiante, déchets médicaux, radioactifs, mercure
    - Résidentiels : piles, médicaments expirés, tubes néons, thermomètres
  - **Déchets ménagers** (~45 modèles) :
    - Commerciaux : emballages sandwich, gobelets, barquettes
    - Industriels : big bags, palettes, fûts métalliques, jerrycans
    - Résidentiels : bouteilles, canettes, restes alimentaires
  - **Déchets recyclables** (~44 modèles) :
    - Commerciaux : bouteilles propres, cartons pizza, papier bureau
    - Industriels : aluminium, cuivre, ferraille, plastiques industriels
    - Résidentiels : verre, papier, plastique, textile
  - **Signalétique** : Pancartes et QR codes pour les différentes zones

- **worlds/** : Environnements de simulation Gazebo
  - `trc2k25_arena.world` : Arène complète avec rendu GPU
  - `trc2k25_arena_no_gpu.world` : Arène optimisée sans GPU

Chaque modèle 3D inclut sa géométrie, ses textures, ses propriétés physiques et ses scripts de comportement pour une simulation réaliste.

### udev rules/

Règles udev pour la configuration automatique des périphériques USB du robot sous Linux.

**Contenu :**

- **56-orbbec-usb.rules** : Règles spécifiques pour les caméras Orbbec Astra
  - Permet la détection automatique de la caméra au branchement
  - Configure les permissions d'accès pour les utilisateurs non-root
  - Assure la stabilité de la connexion USB

### udev rules/

Règles udev pour la configuration automatique des périphériques USB du robot sous Linux.

**Contenu :**

- **56-orbbec-usb.rules** : Règles spécifiques pour les caméras Orbbec Astra
  - Permet la détection automatique de la caméra au branchement
  - Configure les permissions d'accès pour les utilisateurs non-root
  - Assure la stabilité de la connexion USB

- **usb.rules** : Règles USB générales pour les autres périphériques
  - Configuration pour le LIDAR RPLidar
  - Gestion des contrôleurs et interfaces série
  - Attribution de noms de périphériques cohérents

Ces règles doivent être copiées dans `/etc/udev/rules.d/` et les services udev rechargés pour que les périphériques soient correctement reconnus par le système.
