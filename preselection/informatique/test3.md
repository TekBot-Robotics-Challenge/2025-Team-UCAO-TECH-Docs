---
outlineImage: /images/test3/robot_et_labyrinthe.png
---

# Test 3 : Création d'un algorithme de pathfinding

## 1. Contexte

La robotique mobile occupe aujourd'hui une place centrale dans l'industrie, la recherche et l'innovation. Les robots capables de se déplacer de façon autonome dans des environnements complexes sont au cœur de nombreux défis technologiques, qu'il s'agisse de logistique, d'exploration, d'assistance ou de recherche scientifique. Le Test 3 s'inscrit dans cette dynamique : il propose de confronter les étudiants à une problématique concrète de navigation autonome, telle qu'on la retrouve dans le monde professionnel.

Dans ce test, le robot TekBot évolue dans un environnement inconnu, simulé sous Gazebo, qui reproduit les contraintes d'un labyrinthe réel. L'étudiant doit aborder la question de la mobilité robotique comme le ferait un ingénieur ou un chercheur : comment permettre à une machine de percevoir, comprendre et traverser un espace sans intervention humaine directe ?

L'intérêt pédagogique de ce test est double :
- Plonger l'étudiant dans une situation réaliste, proche des problématiques rencontrées dans la recherche en robotique.
- Favoriser l'autonomie, la rigueur et la capacité à mobiliser des outils modernes pour résoudre un problème complexe, de la compréhension du besoin jusqu'à la validation expérimentale.

Enfin, ce test met en avant l'importance du travail reproductible et documenté : chaque étape, chaque choix technique doit pouvoir être expliqué, justifié et partagé, à l'image des pratiques professionnelles en robotique.

## 2. Objectifs

L'objectif du Test 3 est de démontrer la capacité à concevoir et mettre en œuvre une navigation autonome pour un robot mobile (ici le robot TekBot) dans un environnement inconnu et contraignant, tel qu'un labyrinthe simulé. L'étudiant doit permettre au robot d'atteindre une position cible en évitant les obstacles, sans intervention humaine directe, en s'appuyant sur les principes fondamentaux de la robotique mobile : perception, localisation, planification de trajectoire et prise de décision autonome.

- **Le robot TekBot doit explorer un environnement inconnu et en générer une carte utilisable pour la navigation.**
- **Le robot doit être capable de se localiser de façon autonome sur cette carte, même après des déplacements complexes.**
- **L'étudiant doit permettre au robot d'atteindre une position cible définie sur la carte, en évitant tous les obstacles présents.**
- **La solution doit fonctionner sans intervention humaine directe pendant la phase de navigation autonome.**
- **La démarche doit être reproductible et documentée, chaque choix technique devant être justifié.**

La réussite du test se mesure à la capacité du robot à explorer, se localiser et se déplacer de façon fiable et autonome jusqu'à l'objectif fixé, dans le respect des contraintes de l'environnement. Une attention particulière sera portée à la robustesse de la navigation, à la qualité de la cartographie produite, et à la clarté de la documentation technique fournie.

## 3. Configuration du workspace

### 3.1 Prérequis

- **Système d'exploitation** : Ubuntu 22.04 LTS (recommandé pour la compatibilité ROS 2 Humble)
- **ROS 2 Humble** installé ([guide officiel](https://docs.ros.org/en/humble/Installation.html))
- **Droits administrateur** (sudo) pour l'installation des paquets nécessaires

::: tip
Ubuntu 22.04 LTS est la plateforme de référence pour ROS 2 Humble. Elle garantit une compatibilité optimale avec les outils, une documentation à jour et un support communautaire étendu.
:::

### 3.2 Installation du projet TekBot

1. **Cloner le dépôt du projet**
   ```
   git clone https://github.com/charif-tekbot/tekbot_sim.git
   ```
   Cette commande télécharge l'ensemble du code source dans un dossier `tekbot_sim`.

2. **Se placer dans le dossier du projet**
   ```
   cd tekbot_sim
   ```

3. **Rendre le script de configuration exécutable** *(optionnel si déjà exécutable)*
   ```
   chmod +x configure.sh
   ```

4. **Lancer le script de configuration**
   ```
   source configure.sh
   ```
   Ce script :
   - Crée le workspace `~/tekbot_ws`
   - Place le code source dans le workspace
   - Supprime le dossier `bin` inutile
   - Source l'environnement ROS 2 Humble
   - Compile tous les paquets avec `colcon build`
   - Source l'environnement du workspace compilé

### 3.3 Arborescence du dossier `tekbot_ws`

```
tekbot_ws/
├── build/                      ← Fichiers temporaires de compilation colcon
│   └── [maze_solving, tekbot, tekbot_description...]
├── install/                    ← Résultat de l'installation des packages ROS 2
│   ├── local_setup.bash
│   ├── setup.bash              ← ⚠ à sourcer pour activer l'environnement
│   └── lib, share, ...         ← exécutables, ressources de chaque package
├── log/                        ← Logs de compilation
│   └── latest_build/
├── src/
│   └── tekbot_sim/
│       ├── configure.sh
│       ├── README.md
│       ├── maze_solving/
│       │   ├── launch/
│       │   │   └── maze.launch.py
│       │   ├── maps/
│       │   │   ├── maze.yaml
│       │   │   └── maze.pgm
│       │   ├── scripts/
│       │   │   └── generate_maze.py
│       │   ├── maze_solving/
│       │   │   └── _init_.py
│       │   ├── package.xml
│       │   └── setup.py
│       ├── tekbot/
│       │   ├── src/
│       │   │   ├── control_node.cpp
│       │   │   └── main.cpp
│       │   ├── CMakeLists.txt
│       │   └── package.xml
│       └── tekbot_description/
│           ├── urdf/
│           │   └── tekbot.urdf.xacro
│           ├── meshes/
│           │   ├── base_link.dae
│           │   └── wheel.dae
│           ├── launch/
│           │   └── display.launch.py
│           ├── gazebo/
│           │   ├── tekbot.world
│           │   └── model.sdf
│           └── package.xml
```

## 4. Outils et logiciels

### 4.1 Gazebo Classic

Gazebo Classic est le simulateur 3D de référence pour la robotique mobile sous ROS 2. Il permet de tester, valider et optimiser le comportement du robot TekBot dans des environnements virtuels réalistes, sans risque matériel. Grâce à son intégration native avec ROS 2, il facilite le prototypage, la validation logicielle et l'expérimentation de scénarios complexes (navigation, SLAM, interactions capteurs/environnement) avant tout déploiement réel.

**Pourquoi choisir Gazebo Classic ?**
Gazebo Classic reste le simulateur 3D de référence pour la robotique mobile sous ROS 2, notamment pour la version Humble. Il est reconnu pour sa stabilité, sa compatibilité éprouvée avec ROS 2, la richesse de sa documentation et la taille de sa communauté. Classic est idéal pour l'enseignement, la recherche et les projets nécessitant un environnement robuste et bien documenté.
Remarque : Les versions plus récentes (Ignition/Fortress) existent, mais Classic est le choix recommandé pour la majorité des projets ROS 2 Humble.

**Fonctionnalités principales**
- Simulation physique (collisions, gravité, dynamique…)
- Capteurs variés (LiDAR, IMU, GPS…)
- Création/import de mondes personnalisés
- Tests automatisés et reproductibles

**Outils disponibles**
- Interface graphique interactive (ajout/suppression d'objets, manipulation de la scène)
- Bibliothèque de modèles (robots, capteurs, obstacles…)
- Plugins et ressources communautaires

**Installation de Gazebo**
- Exécute : `sudo apt update && sudo apt install gazebo11 libgazebo11-dev`
- Pour l'intégration ROS2 : `sudo apt install ros-humble-gazebo-ros-pkgs ros-humble-gazebo-ros-control`

### Méthodes de lancement dans Gazebo

Plusieurs méthodes sont possibles pour lancer la simulation TekBot sous Gazebo, selon le scénario que vous souhaitez tester (robot seul, labyrinthe seul, ou robot dans le labyrinthe). Chaque méthode permet de valider une étape clé du développement : installation, configuration de l'environnement, ou navigation autonome complète. Choisissez la méthode adaptée à votre besoin : test d'installation, exploration de l'environnement, ou validation de la navigation et du SLAM.

::: warning
**Rappel important :** Avant de lancer **Gazebo** ou tout fichier **launch** ROS 2, assurez-vous d'avoir bien **sourcé l'environnement ROS 2** `source /opt/ros/humble/setup.bash` **et** **sourcé le workspace** `source ~/tekbot_ws/install/setup.bash` dans chaque terminal utilisé. Sans cela, les commandes `ros2` et les packages du projet ne seront pas reconnus. Pour de meilleures performances, fermez les applications lourdes (navigateur, IDE, etc.) avant de lancer Gazebo Classic, surtout sur un PC portable.
:::

**Simulation de base (robot seul) :** Lance le robot TekBot dans un environnement Gazebo vide.
```
ros2 launch tekbot_description gazebo.launch.py
```

**Visualisation du labyrinthe (sans robot) :** Affiche uniquement l'environnement maze dans Gazebo.
```
ros2 launch maze_solving maze.launch.py
```

**Simulation complète (robot + labyrinthe) :** Lance TekBot directement dans le labyrinthe
```
ros2 launch maze_solving tekbot_maze.launch.py
```

![Robot TekBot dans Gazebo](/images/test3/robot.png)

![Robot TekBot dans le labyrinthe Gazebo](/images/test3/labyrinthe.png)

![Robot TekBot dans le labyrinthe Gazebo](/images/test3/robot_et_labyrinthe.png)

Documentation officielle : [gazebosim.org/docs](https://gazebosim.org/docs)

### 4.2 RQt

**RQt** est une application graphique modulaire basée sur Qt, conçue pour ROS/ROS2. Elle permet d'agréger de nombreux outils de monitoring, de visualisation et de configuration sous forme de plugins : graphe des nœuds, topics, logs, paramètres dynamiques, etc. RQt facilite le diagnostic, le debug et l'analyse du système robotique TekBot.

**Pourquoi utiliser RQt ?**
RQt centralise tous les outils de supervision et de debug ROS2 dans une seule interface graphique : vous gagnez du temps, visualisez l'état du système en temps réel et pouvez diagnostiquer rapidement les problèmes de communication ou de configuration.

**Installation rapide :** `sudo apt install ros-humble-rqt`
Cette commande installe RQt ainsi que la majorité des plugins indispensables pour superviser, visualiser et diagnostiquer un système ROS2.

**Lancement :** `rqt` (à lancer dans un terminal après avoir démarré le robot et le labyrinthe) ou `ros2 launch maze_solving tekbot_maze.launch.py` (cette commande lance le robot, le labyrinthe et ouvre automatiquement RQt pour le monitoring graphique).

**Astuce :** Superpose ou organise les fenêtres de plugins selon tes besoins : RQt permet une interface totalement personnalisable.

::: danger FAQ / Problèmes fréquents
**RQt ne détecte pas les topics ou nœuds** : vérifiez que vous avez bien sourcé l'environnement ROS2 et le workspace dans ce terminal. | **Interface vide au lancement** : ajoutez les plugins nécessaires via le menu **Plugins**. | **Problèmes d'affichage ou de lenteur** : fermez les applications lourdes, réduisez la taille de la fenêtre ou relancez RQt. | **RQt ne démarre pas** : vérifiez l'installation de Qt et des dépendances graphiques (`sudo apt install qtbase5-dev`).
:::

**Plugins recommandés pour le debug ROS2**

| Plugin | Utilité | Menu d'accès |
|--------|---------|--------------|
| **Node Graph** | Visualise la structure des nœuds et leurs connexions | Plugins → Introspection → Node Graph |
| **Topic Monitor** | Affiche la liste des topics actifs, leur fréquence et la structure des messages | Plugins → Topics → Topic Monitor |
| **TF Tree** | Visualise en temps réel l'arbre des transformations (TF) | Plugins → Visualization → TF Tree |

Documentation officielle : [wiki.ros.org/rqt](https://wiki.ros.org/rqt)

<video controls style="width: 100%; max-width: 600px; border-radius: 8px; background: #000;">
  <source src="/images/test3/rqt.mp4" type="video/mp4">
  Votre navigateur ne supporte pas la lecture vidéo.
</video>

### 4.3 RViz2

**RViz2** est l'outil de visualisation 3D incontournable de ROS2. Il permet d'afficher en temps réel l'état du robot, les données capteurs (LiDAR, caméras…), la carte générée, les trajectoires, les frames de coordonnées, etc. RViz2 est indispensable pour le debug, la validation et l'interaction avec le système TekBot.

**Tableau des displays principaux**

| Display | Utilité | Ajout |
|---------|---------|-------|
| Map | Affiche la carte générée (SLAM, navigation) | Displays → Map |
| LaserScan | Visualise les données LiDAR | Displays → LaserScan |
| TF | Affiche l'arbre des frames (repères) | Displays → TF |
| Path | Affiche la trajectoire planifiée | Displays → Path |
| Image | Affiche le flux caméra | Displays → Image |
| RobotModel | Affiche le modèle 3D du robot | Displays → RobotModel |

**Procédure pas à pas**
1. Lance RViz2 dans un terminal : `rviz2`
2. Ajoute un display via le bouton **Add** (en bas à gauche), puis choisis le type (ex : Map, LaserScan…)
3. Personnalise les paramètres du display dans le panneau latéral
4. Sauvegarde ta configuration : **File → Save Config As…**
5. Pour recharger une configuration : **File → Open Config**

**Bonnes pratiques & astuces avancées**
- Sauvegarde une configuration différente pour chaque scénario (SLAM, navigation, debug…)
- Utilise les raccourcis clavier pour naviguer dans la vue 3D (Maj + clic, molette…)
- Ferme les displays inutiles pour améliorer les performances
- Personnalise les couleurs et styles d'affichage selon tes besoins
- Utilise les outils d'interaction (2D Pose Estimate, 2D Nav Goal…)

**Installation :** `sudo apt install ros-humble-rviz2`
*Installe RViz2 sur Ubuntu/ROS2 Humble.*

**Lancement rapide :** `rviz2`
*Lance RViz2 après avoir démarré la simulation ou les nœuds ROS2.*

::: danger Problèmes fréquents
- **RViz2 plante au lancement** : mets à jour tes pilotes graphiques, essaie `rviz2 --opengl`.
- **Le robot n'apparaît pas** : vérifie le display RobotModel et les topics associés.
- **Les axes ou repères sont décalés** : vérifie la configuration des TF (transforms) et la synchronisation des horloges ROS2.
- **Impossible d'ajouter un affichage** : assure-toi que le bon type de message est publié sur le topic (ex : « LaserScan », « Image », « PointCloud2 »).
:::

![Aperçu RViz2](/images/test3/rviz2.jpg)

Documentation officielle : [index.ros.org/p/rviz2/](https://index.ros.org/p/rviz2/)

## 5. Télé-opération

La **télé-opération** est une étape clé du cycle de développement robotique : elle permet de prendre le contrôle manuel du robot TekBot pour valider chaque sous-système (moteurs, capteurs, communication ROS2, sécurité) avant toute expérimentation autonome.

**Pourquoi télé-opérer ?**
- **Vérification initiale :** S'assurer que le robot réagit bien aux commandes, que les moteurs tournent dans le bon sens, que les capteurs publient des données cohérentes.
- **Diagnostic et debug :** Identifier rapidement les problèmes de configuration (topics, permissions, drivers, etc.) en observant la réponse du robot en temps réel.
- **Calibration :** Ajuster les paramètres (vitesses, sensibilité, limites) en situation réelle ou simulée.
- **Prise de main d'urgence :** Intervenir manuellement en cas de bug, de danger ou de test critique.
- **Formation et démonstration :** Permettre à un utilisateur novice de piloter le robot pour comprendre son fonctionnement.

::: tip Principe technique
La télé-opération consiste à publier des messages `geometry_msgs/Twist` sur le topic `/cmd_vel` du robot. Ces messages sont interprétés par le contrôleur de mouvement (diff_drive, ackermann, etc.) pour générer les déplacements.
:::

**Comparatif des modes de télé-opération**

| Mode | Avantages | Limites | Cas d'usage | Commande d'installation |
|------|-----------|---------|-------------|-------------------------|
| **Clavier** | Simple, rapide, pas de matériel supplémentaire | Contrôle peu précis, pas d'analogique | Debug, tests unitaires, prise en main rapide | `sudo apt install ros-humble-teleop-twist-keyboard` |
| **Manette** | Contrôle analogique précis, ergonomique | Configuration parfois nécessaire, dépend du matériel | Conduite fine, formation, démonstration | `sudo apt install ros-humble-teleop-twist-joy` |
| **Interface graphique (RQt)** | Accessible à tous, visuel, sliders intuitifs | Moins réactif, nécessite un environnement graphique | Démonstration, pédagogie, prise en main par débutant | `sudo apt install ros-humble-rqt-robot-steering` |
| **Web / Mobile** | Contrôle à distance, multiplateforme | Installation de ROSBridge, sécurité réseau à gérer | Contrôle à distance, démo publique, accès mobile | `sudo apt install ros-humble-rosbridge-server` |

![Schéma télé-opération ROS2](https://raw.githubusercontent.com/ros-visualization/rqt_robot_steering/master/doc/teleop_schema.png)
*Chaîne logicielle : PC/Manette/Web → ROS2 → /cmd_vel → Robot*

**Téléopération Web avancée (WebSocket & navigateur)**

1. **Installer rosbridge_server** :
   ```
   cd ~/tekbot_ws/src && git clone https://github.com/RobotWebTools/rosbridge_suite.git
   ```

2. **Résoudre les dépendances** :
   ```
   sudo apt install ros-humble-ament-cmake-mypy
   ```
   *(ou cloner `ament_cmake` si besoin)*

3. **Recompiler le workspace** :
   ```
   cd ~/tekbot_ws && colcon build && source install/setup.bash
   ```

4. **Lancer le serveur WebSocket** :
   ```
   ros2 launch rosbridge_server rosbridge_websocket_launch.xml
   ```
   *(Le serveur écoute sur `ws://localhost:9090`)*

5. **Créer une interface web de téléopération** :
   ```
   git clone https://github.com/RobotWebTools/roslibjs.git
   ```

6. **Accès direct à la téléopération web moderne** :
   *(Interface à développer - voir documentation ROS2 pour les exemples)*

7. **Lancer un serveur web local** :
   ```
   python3 -m http.server 8000
   ```
   puis ouvrir `http://localhost:8000/teleop.html`

<video controls style="width: 100%; max-width: 600px; border-radius: 8px; background: #000;">
  <source src="/images/test3/teleop_clavier.mp4" type="video/mp4">
  Votre navigateur ne supporte pas la lecture vidéo.
</video>

<video controls style="width: 100%; max-width: 600px; border-radius: 8px; background: #000;">
  <source src="/images/test3/teleop_web.mp4" type="video/mp4">
  Votre navigateur ne supporte pas la lecture vidéo.
</video>

## 6. SLAM (cartographie)

Le **SLAM (Simultaneous Localization and Mapping)** est une technique fondamentale en robotique mobile qui permet à un robot d'explorer un environnement inconnu tout en construisant simultanément une carte de cet environnement et en se localisant sur cette carte.

**Pourquoi SLAM ?**
- **Exploration autonome :** Le robot peut découvrir et cartographier des espaces inconnus sans intervention humaine.
- **Base de navigation :** La carte générée sert de fondement pour la planification de trajectoires et la navigation autonome.
- **Localisation précise :** Le robot sait toujours où il se trouve sur la carte qu'il construit.

**Principe technique :**
Le SLAM résout le problème de la "boucle fermée" : quand le robot revient à un endroit déjà visité, il doit reconnaître cet endroit et corriger les erreurs accumulées dans la carte et la localisation.

**SLAM Toolbox dans ROS2 :**
SLAM Toolbox est l'implémentation de référence pour ROS2 Humble. Il utilise l'algorithme Karto pour créer des cartes 2D à partir des données LiDAR.

**Installation :**
```
sudo apt install ros-humble-slam-toolbox
```

**Lancement :**
```
ros2 launch slam_toolbox online_async_launch.py
```

**Fonctionnement :**
1. Le robot explore l'environnement en se déplaçant
2. Le LiDAR scanne l'environnement et publie sur `/scan`
3. SLAM Toolbox traite les données et publie la carte sur `/map`
4. La carte s'affine au fur et à mesure de l'exploration

**Sauvegarde de la carte :**
```
ros2 run nav2_map_server map_saver_cli -f ~/map
```

![Carte générée par SLAM](/images/test3/carte.jpg)

<video controls style="width: 100%; max-width: 600px; border-radius: 8px; background: #000;">
  <source src="/images/test3/carte.mp4" type="video/mp4">
  Votre navigateur ne supporte pas la lecture vidéo.
</video>

Documentation officielle : [github.com/SteveMacenski/slam_toolbox](https://github.com/SteveMacenski/slam_toolbox)

## 7. Nav2 (Navigation)

**Nav2** est la stack de navigation de ROS2, qui permet la navigation autonome des robots mobiles. Elle intègre tous les composants nécessaires : localisation, planification globale, planification locale et contrôle.

**Composants principaux :**
- **AMCL (Adaptive Monte Carlo Localization) :** Localisation du robot sur une carte connue
- **Global Planner :** Planification de trajectoire à long terme (utilise A*)
- **Local Planner :** Évitement d'obstacles en temps réel
- **Controller :** Contrôle précis du mouvement du robot

**Installation :**
```
sudo apt install ros-humble-navigation2
sudo apt install ros-humble-nav2-bringup
```

**Lancement :**
```
ros2 launch nav2_bringup navigation_launch.py
```

**Configuration :**
Nav2 utilise des fichiers YAML pour la configuration :
- `nav2_params.yaml` : paramètres généraux
- `bt_navigator.yaml` : comportement tree
- `costmaps` : configuration des cartes de coût

**Workflow complet :**
1. Charger une carte pré-enregistrée ou utiliser SLAM
2. Initialiser AMCL pour la localisation
3. Définir un goal dans RViz2
4. Nav2 planifie et exécute la trajectoire

![Interface Nav2](/images/test3/nav2.jpg)

<video controls style="width: 100%; max-width: 600px; border-radius: 8px; background: #000;">
  <source src="/images/test3/nav2.mp4" type="video/mp4">
  Votre navigateur ne supporte pas la lecture vidéo.
</video>

Documentation officielle : [navigation.ros.org](https://navigation.ros.org/)

## 8. Algorithme A*

L'**algorithme A*** est l'algorithme de pathfinding le plus utilisé en robotique mobile. Il trouve le chemin optimal entre un point de départ et un point d'arrivée en évitant les obstacles.

**Principe :**
A* utilise une fonction heuristique pour guider la recherche vers la solution optimale. La fonction f(n) = g(n) + h(n) où :
- g(n) : coût réel pour atteindre le nœud n depuis le départ
- h(n) : estimation heuristique du coût pour aller de n au but
- f(n) : estimation totale du coût du chemin passant par n

**Avantages :**
- Trouve toujours le chemin optimal si l'heuristique est admissible
- Plus efficace que Dijkstra grâce à l'heuristique
- Facilement extensible et configurable

**Utilisation dans ROS2 :**
A* est utilisé par le global planner de Nav2. Il peut être configuré via les paramètres du planner.

::: tip Astuce TekBot
Dans ROS2, A* est utilisé par le planificateur global de **Nav2** pour générer des trajectoires sûres et efficaces, en tenant compte de la carte d'occupation générée par SLAM ou fournie par l'utilisateur.
:::

**Fonctionnement étape par étape**
1. Initialiser la liste ouverte (open list) avec le point de départ.
2. Répéter jusqu'à atteindre la cible ou épuisement :
   - Sélectionner le nœud avec le plus petit `f(n)`.
   - Si c'est la cible, reconstruire le chemin.
   - Sinon, déplacer ce nœud dans la liste fermée (closed list).
   - Pour chaque voisin accessible :
     - Calculer `g(n)`, `h(n)`, `f(n)`.
     - Si meilleur chemin trouvé, mettre à jour et ajouter à la liste ouverte.

**Limites et améliorations :**

| Limites | Améliorations possibles |
|---------|-------------------------|
| Lent sur de grandes cartes ou en présence de nombreux obstacles | Utiliser des variantes (Theta*, Jump Point Search), optimiser l'heuristique |
| Ne gère pas les environnements dynamiques (obstacles mobiles) | Combiner avec D* Lite, ou des algorithmes réactifs |
| Chemins parfois non naturels (angles droits) | Post-traitement (lissage, courbes de Bézier) |

**Pour aller plus loin :**
- [Documentation officielle Nav2 - Global Planner](https://navigation.ros.org/concepts/index.html#global-planner)
- [Wikipédia : Algorithme A*](https://fr.wikipedia.org/wiki/Algorithme_A*)
- [A* in Robotics (article scientifique, anglais)](https://www.roboticsproceedings.org/rss07/p10.pdf)

![Algorithme A* illustration](/images/test3/Astar.png)

## 9. Défis & solutions

::: tip Note
Les défis et solutions présentés ici sont ceux que nous avons réellement rencontrés lors de l'élaboration du projet TekBot. Pour chaque défi, une solution concrète a été apportée et explicitée dans les sections précédentes (SLAM, Nav2, A*, FAQ, etc.). Vous pouvez vous y référer pour retrouver nos retours d'expérience et les méthodes qui ont permis de résoudre chaque difficulté.
:::

**Cartographie incomplète :** Vérifier la couverture du robot, ajuster la vitesse et la stratégie d'exploration.

**Localisation instable :** Bien initialiser AMCL, éviter de lancer SLAM et AMCL en même temps.

**Navigation bloquée :** Surveiller les costmaps, ajuster les paramètres du planner et du contrôleur.

**Problèmes de performance :** Limiter les displays RViz2, fermer les applications lourdes, optimiser la configuration du PC.

**Sauvegarde de la carte :** Des difficultés pour enregistrer la carte générée par SLAM, nécessitant de vérifier les permissions et le format du fichier.

**Planification du chemin (A*) :** L'algorithme planifiait parfois le chemin à partir de l'origine du repère au lieu de la position réelle du robot ; il a fallu corriger la prise en compte de la localisation dans le code.

**Cas pratiques divers :** Problèmes de synchronisation entre les nœuds ROS2, erreurs de configuration des topics, et ajustements des paramètres pour obtenir un comportement optimal.

::: danger Bonnes pratiques
- Documenter chaque étape et chaque choix technique.
- Tester régulièrement chaque brique (SLAM, Nav2, A*…)
- Collaborer et demander de l'aide sur les forums ROS2.
:::

::: tip FAQ
- **Le robot tourne en rond ?** Vérifie la calibration des capteurs et la configuration du contrôleur.
- **La carte ne se sauvegarde pas ?** Vérifie les permissions d'écriture et le chemin du dossier.
:::

## 10. Annexes & références

- **Documentation ROS2 :** [docs.ros.org/en/humble](https://docs.ros.org/en/humble/index.html)
- **SLAM Toolbox :** [github.com/SteveMacenski/slam_toolbox](https://github.com/SteveMacenski/slam_toolbox)
- **Nav2 :** [navigation.ros.org](https://navigation.ros.org/)
- **Gazebo Classic :** [classic.gazebosim.org](https://classic.gazebosim.org/)
- **RQt :** [wiki.ros.org/rqt](https://wiki.ros.org/rqt)
- **RViz2 :** [index.ros.org/p/rviz2/](https://index.ros.org/p/rviz2/)
- **Forum ROS2 :** [answers.ros.org](https://answers.ros.org/questions/)
- **Exemples de cartes :** [tekbot_sim/maps](https://github.com/charif-tekbot/tekbot_sim/tree/main/maze_solving/maps)

Pour toute question ou suggestion, consultez la documentation officielle ou contactez l'équipe pédagogique.

## 11. Conclusion

Ce projet TekBot a permis d'explorer concrètement les principaux outils et méthodes de la robotique mobile sous ROS2 : simulation dans Gazebo, SLAM, navigation autonome, planification de trajectoire (A*), et téléopération. Les défis rencontrés ont été surmontés grâce à une démarche expérimentale et collaborative, chaque solution étant explicitée dans la documentation. Ce travail constitue une base solide pour aller plus loin : optimisation des algorithmes, intégration de nouveaux capteurs, ou déploiement sur robot réel. N'hésitez pas à vous inspirer de cette expérience pour vos propres projets !
