---
outline: { level: [2,3] }
outlineImage: ../../public/final/images/phase de collecte/remote desktop.jpeg
---

# Configuration logicielle et environnement de développement

## Installation du système d'exploitation sur Raspberry Pi 5

Après l'assemblage physique du robot Rosmaster X3, la prochaine étape cruciale consiste à configurer le système embarqué. Le kit Yahboom fourni inclut un Raspberry Pi 5 comme contrôleur principal, offrant des performances équilibrées et une excellente compatibilité avec ROS2.

### Prérequis matériels
- Raspberry Pi 5 (4GB ou 8GB RAM recommandé)
- Carte microSD de 32GB minimum (Classe 10)
- Alimentation 7.xV (fournie avec le kit Yahboom)
- Clavier, souris et écran HDMI pour la configuration initiale

### Installation d'Ubuntu 24.04 LTS (hôte) et Ubuntu 22.04 LTS (conteneur)

ROS2 Humble n'étant pas entièrement stable sur Ubuntu 24.04 LTS, nous utilisons une approche en conteneur avec Distrobox pour garantir la compatibilité et la stabilité.

#### Installation d'Ubuntu 24.04 LTS comme système hôte
1. **Téléchargement de l'image** :
   - Rendez-vous sur le site officiel d'Ubuntu : https://ubuntu.com/download/raspberry-pi
   - Téléchargez Ubuntu 24.04 LTS (64-bit) pour Raspberry Pi

2. **Flash de la carte SD** :
   - Utilisez Raspberry Pi Imager ou un outil équivalent
   - Sélectionnez l'image Ubuntu 24.04 LTS
   - Flashez sur la carte microSD

3. **Premier démarrage** :
   - Insérez la carte SD dans le Raspberry Pi 5
   - Branchez alimentation, clavier, souris et écran
   - Suivez le processus de configuration initiale

4. **Configuration système hôte** :
   ```bash
   # Mise à jour du système
   sudo apt update && sudo apt upgrade -y
   
   # Installation des outils de base
   sudo apt install -y git curl wget htop net-tools openssh-server distrobox
   
   # Configuration du hostname (nom de la compétition)
   sudo hostnamectl set-hostname trc2k25
   
   # Activation du SSH
   sudo systemctl enable ssh
   sudo systemctl start ssh
   ```

5. **Configuration avancée avec raspi-config** :
   
   `raspi-config` est un outil de configuration interactif spécifique au Raspberry Pi qui facilite la configuration de nombreux paramètres système.
   
   ```bash
   # Lancer raspi-config
   sudo raspi-config
   ```
   
   ![Interface raspi-config](/final/images/phase%20de%20collecte/raspi-config.png)
   
   **Options utiles à configurer** :
   - **Interface Options** :
     - SSH : Activer le serveur SSH
     - VNC : Activer VNC (alternative à RDP)
     - I2C/SPI : Activer pour les capteurs
   - **System Options** :
     - Hostname : Modifier le nom d'hôte
     - Password : Changer le mot de passe par défaut
     - Boot/Auto Login : Configurer le démarrage automatique
   - **Performance Options** :
     - GPU Memory : Ajuster la mémoire GPU
     - Overlay File System : Protection de la carte SD
   - **Localisation Options** :
     - Locale : Configurer la langue
     - Timezone : Définir le fuseau horaire
     - Keyboard : Configuration du clavier
   
   **Note** : `raspi-config` simplifie considérablement la configuration initiale du Raspberry Pi et est recommandé pour les utilisateurs débutants.

#### Installation d'Ubuntu 22.04 LTS dans un conteneur Distrobox
1. **Création du conteneur** :
   ```bash
   # Création d'un conteneur Ubuntu 22.04
   distrobox create --name ucao_tech --image ubuntu:22.04
   
   # Accès au conteneur
   distrobox enter ucao_tech
   ```

2. **Configuration du conteneur** :
   ```bash
   # Mise à jour du conteneur
   sudo apt update && sudo apt upgrade -y
   
   # Installation des outils essentiels
   sudo apt install -y git curl wget python3 python3-pip
   ```

### Installation de ROS2 Humble dans le conteneur Ubuntu 22.04

**Note de sécurité :** Les informations d'identification (noms d'utilisateur, mots de passe, clés SSH, identifiants de domaine ROS) utilisées dans cette configuration sont confidentielles et ne sont pas divulguées dans cette documentation publique pour des raisons de sécurité.

1. **Configuration des sources** :
   ```bash
   # Ajout des clés GPG
   sudo apt install -y software-properties-common
   sudo add-apt-repository universe
   
   # Ajout du dépôt ROS2
   sudo apt update && sudo apt install -y curl
   sudo curl -sSL https://raw.githubusercontent.com/ros/rosdistro/master/ros.key -o /usr/share/keyrings/ros-archive-keyring.gpg
   echo "deb [arch=$(dpkg --print-architecture) signed-by=/usr/share/keyrings/ros-archive-keyring.gpg] http://packages.ros.org/ros2/ubuntu $(source /etc/os-release && echo $UBUNTU_CODENAME) main" | sudo tee /etc/apt/sources.list.d/ros2.list > /dev/null
   ```

2. **Installation de ROS2 Humble** :
   ```bash
   sudo apt update
   sudo apt install -y ros-humble-desktop
   ```

3. **Configuration de l'environnement** :
   ```bash
   # Ajout au bashrc
   echo "source /opt/ros/humble/setup.bash" >> ~/.bashrc
   source ~/.bashrc
   
   # Installation des outils de développement
   sudo apt install -y python3-colcon-common-extensions python3-rosdep
   sudo rosdep init
   rosdep update
   ```

## Accès à distance au Rosmaster X3

### Configuration initiale (première utilisation)

Lors de la première configuration du robot Rosmaster X3, il est **obligatoire** de connecter un écran HDMI, un clavier et une souris directement au Raspberry Pi 5. Cette connexion physique est nécessaire pour :
- Terminer la configuration initiale d'Ubuntu 24.04
- Activer les services réseau (SSH, bureau à distance)
- Identifier l'adresse IP de la machine
- Configurer les paramètres de sécurité et de réseau

### Identification du robot sur le réseau

**Prérequis important** : Les deux ordinateurs (votre PC et le Raspberry Pi du robot) **doivent être connectés au même réseau local** (WiFi ou Ethernet) pour que l'accès à distance fonctionne.

Pour accéder au robot à distance, il est essentiel de connaître son adresse IP ou son nom d'hôte sur le réseau local.

#### Méthode 1 : Test de connectivité avec ping (recommandée)

Si vous connaissez le nom d'hôte du robot, utilisez la commande `ping` pour vérifier la connectivité et obtenir son adresse IP.

**Depuis votre PC** :
```bash
# Test de connectivité avec le nom d'hôte
ping trc2k25-desktop.local

# Le résultat affichera l'adresse IP du robot
# Exemple de sortie :
# PING trc2k25-desktop.local (192.168.1.10) 56(84) bytes of data.
# 64 bytes from 192.168.1.10: icmp_seq=1 ttl=64 time=2.43 ms
```

**Arrêter le ping** : Appuyez sur `Ctrl+C`

Cette méthode est simple et rapide pour :
- Vérifier que le robot est bien connecté au réseau
- Obtenir son adresse IP actuelle
- Tester la latence réseau

#### Méthode 2 : Identification de l'adresse IP depuis le Raspberry Pi

Si vous avez un accès physique au robot (écran connecté), vous pouvez récupérer l'adresse IP directement.

**Depuis le Raspberry Pi** :
```bash
# Méthode 1 : ip command
ip addr show wlan0  # Pour WiFi
ip addr show eth0   # Pour Ethernet

# Méthode 2 : hostname command
hostname -I

# Méthode 3 : ifconfig (si installé)
ifconfig
```

#### Méthode 3 : Recherche via l'interface web du routeur

Si vous ne connaissez ni l'IP ni le nom d'hôte, accédez à l'interface d'administration de votre routeur.

**Étapes** :
1. Ouvrez un navigateur web
2. Accédez à l'adresse de votre routeur (généralement `192.168.1.1` ou `192.168.0.1`)
3. Connectez-vous avec vos identifiants administrateur
4. Recherchez la section "Appareils connectés" ou "DHCP clients"
5. Identifiez le robot par :
   - Son **hostname** : `trc2k25-desktop`
   - Son **adresse MAC** (si connue)
6. Notez l'adresse IP attribuée

#### Méthode 4 : Scan du réseau (si le hostname est inconnu)

Si vous ne connaissez pas le nom d'hôte du robot, utilisez des outils de scan réseau.

**Option 1 : Avec nmap** (sur votre PC) :
```bash
# Installation de nmap
sudo apt install -y nmap

# Scan du réseau local (adaptez la plage IP)
sudo nmap -sn 192.168.1.0/24

# Recherchez les appareils actifs et identifiez le Raspberry Pi
```

**Option 2 : Avec arp-scan** :
```bash
# Installation
sudo apt install -y arp-scan

# Scan du réseau
sudo arp-scan --localnet

# Recherchez l'adresse MAC commençant par "DC:A6:32" ou "E4:5F:01" (Raspberry Pi)
```

**Recommandation** : Pour éviter de chercher l'adresse IP à chaque connexion, configurez une **IP statique** sur votre routeur (réservation DHCP) ou directement sur le Raspberry Pi pour que l'adresse reste constante.

### Méthodes d'accès à distance (utilisations suivantes)

Une fois le robot identifié sur le réseau (IP ou hostname connu), vous pouvez vous connecter à distance depuis votre ordinateur personnel. Deux méthodes principales sont disponibles.

#### Méthode 1 : SSH (ligne de commande)

SSH permet un accès en ligne de commande au Raspberry Pi.

**Activation du service SSH** (lors de la première configuration avec écran) :

**Option 1 : Via raspi-config (recommandée)** :
```bash
# Lancer raspi-config
sudo raspi-config

# Navigation dans l'interface :
# 1. Sélectionnez "Interface Options"
# 2. Sélectionnez "SSH"
# 3. Choisissez "Yes" pour activer SSH
# 4. Sélectionnez "Finish" et redémarrez si demandé
```

**Option 2 : Via ligne de commande** :
```bash
# Installation du serveur SSH
sudo apt install -y openssh-server

# Activation du service
sudo systemctl enable ssh
sudo systemctl start ssh

# Vérification du statut
sudo systemctl status ssh
```

**Connexion SSH depuis votre PC** :
```bash
# Connexion SSH (remplacez <IP_DU_ROBOT> par l'adresse IP réelle)
ssh utilisateur@<IP_DU_ROBOT>

# Exemple :
# ssh trc2k25-desktop@192.168.1.10
```

**Limites** : SSH ne fournit qu'une interface en ligne de commande sans environnement graphique. Cette méthode est rarement utilisée dans notre cas car nous avons besoin d'une vue graphique pour les outils ROS2 (RViz, Gazebo, etc.).

<video controls width="100%">
  <source src="/final/images/phase%20de%20collecte/ssh.webm" type="video/webm">
  Votre navigateur ne supporte pas la balise vidéo.
</video>

#### Méthode 2 : Bureau à distance avec Remmina et RDP (recommandée)

**Remmina** avec le protocole **RDP (Remote Desktop Protocol)** est notre méthode privilégiée car elle offre un accès graphique complet au bureau Ubuntu.

##### Activation du bureau à distance sur le Raspberry Pi (première fois)

1. **Installation de xrdp** (serveur RDP) :
   ```bash
   # Installation du serveur RDP
   sudo apt install -y xrdp
   
   # Activation du service
   sudo systemctl enable xrdp
   sudo systemctl start xrdp
   
   # Vérification du statut
   sudo systemctl status xrdp
   ```

2. **Configuration du pare-feu** (si activé) :
   ```bash
   # Autoriser le port RDP (3389)
   sudo ufw allow 3389/tcp
   ```

##### Connexion depuis votre PC avec Remmina

1. **Installation de Remmina** (sur votre PC Linux) :
   ```bash
   sudo apt install -y remmina remmina-plugin-rdp
   ```

2. **Configuration de la connexion** :
   - Ouvrez Remmina
   - Cliquez sur "Nouvelle connexion"
   - Configurez les paramètres :
     - **Protocole** : RDP - Remote Desktop Protocol
     - **Serveur** : `<IP_DU_ROBOT>` (exemple : `192.168.1.100`)
     - **Nom d'utilisateur** : (confidentiel - votre utilisateur système)
     - **Mot de passe** : (confidentiel)
     - **Résolution** : Utilisez la résolution initiale du client
     - **Qualité** : Meilleure (compromise avec la vitesse réseau)

   ![Configuration Remmina](/final/images/phase%20de%20collecte/remmina.jpeg)

3. **Connexion** :
   - Sauvegardez la configuration
   - Cliquez sur "Connecter"
   - Vous accédez maintenant au bureau graphique du Rosmaster X3

##### Avantages du bureau à distance RDP
- Interface graphique complète
- Accès à tous les outils ROS2 (RViz, Gazebo, rqt, etc.)
- Possibilité de lancer plusieurs terminaux
- Visualisation en temps réel des données capteurs

![Interface Pi bureau à distance](/final/images/phase%20de%20collecte/interface%20pi.jpeg)