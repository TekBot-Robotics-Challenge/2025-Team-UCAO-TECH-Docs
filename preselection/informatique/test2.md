---
outlineImage: /images/test2/ros2.jpeg
---

# Test 2 : Introduction à ROS2

## 1. Introduction et objectifs

**Introduction :**  
Ce projet s'inscrit dans le cadre d'un test d'initiation à ROS2, un framework moderne et puissant pour la robotique et les systèmes distribués. L'objectif est de découvrir, à travers une mise en pratique concrète, les mécanismes fondamentaux de ROS2 : la publication, la souscription et la communication inter-nodes via les topics.

**Objectifs pédagogiques et techniques :**

- Comprendre la structure d'un package ROS2 et les bonnes pratiques d'organisation du code.
- Implémenter un **node publisher** qui génère et publie à intervalle régulier (0,5 s) des données simulées de capteurs (température, humidité, pression) sur un topic dédié.
- Implémenter un **node subscriber** qui reçoit ces données, vérifie leur validité par rapport à des plages prédéfinies, et loggue le résultat (valide/hors plage).
- Créer un **fichier de lancement** pour faciliter l'exécution simultanée des nodes.
- Acquérir une première expérience concrète de la communication asynchrone et de la gestion des messages dans ROS2.

Ce test constitue une base essentielle pour tout développement ultérieur en robotique ROS2, et permet d'acquérir les réflexes indispensables pour la conception de systèmes robustes, évolutifs et interopérables.

*Note :* Les fonctionnalités avancées (historique, statistiques, dashboard web, etc.) sont des ajouts personnels pour enrichir l'expérience, mais ne sont pas exigées dans le test de base.

## 2. Installation de ROS2 Humble sur Ubuntu 22.04 (Étape indispensable)

**Avant toute implémentation de code, il est impératif d'installer correctement ROS2 Humble sur Ubuntu 22.04.**

> **Pourquoi cette étape est-elle cruciale ?**  
> ROS2 est un framework complexe qui dépend fortement de la version du système d'exploitation et de la distribution installée. ROS2 Humble est officiellement supporté et testé sur Ubuntu 22.04. Toute tentative d'installer sur une autre version d'Ubuntu ou sur un autre OS peut entraîner des incompatibilités, des erreurs de compilation ou des dysfonctionnements des nodes et des outils ROS2.  
>  
> ::: warning
⚠️ Sans une installation propre de ROS2 Humble sur Ubuntu 22.04, il est impossible de garantir le bon fonctionnement des commandes `ros2`, de la compilation des packages, ou de la communication entre nodes.
:::  
>  
> **Cette étape conditionne la réussite de tout le projet :**
> - Les nodes publisher et subscriber ne pourront pas être lancés si ROS2 n'est pas installé ou mal configuré.
> - Le fichier de lancement ne fonctionnera pas sans l'environnement ROS2 initialisé.
> - Les outils de build (`colcon`, `ament`) et les dépendances Python/C++ sont gérés par ROS2.
> - La documentation, les tutoriels et la communauté sont centrés sur cette version.
>  
> **En résumé :** *Commencez toujours par installer ROS2 Humble sur Ubuntu 22.04, vérifiez que la commande `ros2 --version` fonctionne, et sourcez bien l'environnement avant d'écrire ou d'exécuter le moindre code.*

1. **Mettez à jour votre système :**
   ```
   sudo apt update && sudo apt upgrade -y
   ```

2. **Configurez la locale :**
   ```
   sudo apt install locales
   sudo locale-gen en_US en_US.UTF-8
   sudo update-locale LC_ALL=en_US.UTF-8 LANG=en_US.UTF-8
   export LANG=en_US.UTF-8
   ```

3. **Ajoutez les sources ROS2 :**
   ```
   sudo apt install software-properties-common
   sudo add-apt-repository universe
   sudo apt update && sudo apt install curl -y
   sudo curl -sSL https://raw.githubusercontent.com/ros/rosdistro/master/ros.key -o /usr/share/keyrings/ros-archive-keyring.gpg
   echo "deb [arch=$(dpkg --print-architecture) signed-by=/usr/share/keyrings/ros-archive-keyring.gpg] http://packages.ros.org/ros2/ubuntu $(lsb_release -cs) main" | sudo tee /etc/apt/sources.list.d/ros2.list > /dev/null
   ```

4. **Installez ROS2 Humble :**
   ```
   sudo apt update
   sudo apt install ros-humble-desktop python3-argcomplete -y
   ```

5. **Initialisez l'environnement :**
   ```
   echo "source /opt/ros/humble/setup.bash" >> ~/.bashrc
   source ~/.bashrc
   ```

6. **Vérifiez l'installation :**
   ```
   ros2 --version
   ```

> **Astuce :** Pour plus de détails, consultez la [documentation officielle ROS2 Humble](https://docs.ros.org/en/humble/Installation/Ubuntu-Install-Debians.html).  
> **En cas de problème :** Consultez les forums ROS Answers, la documentation Ubuntu, ou demandez de l'aide à la communauté avant d'aller plus loin dans le développement.

## 3. Structure du dossier `sensor_data_evaluation` (exemple réel du projet)

Voici la structure réelle du dossier `sensor_data_evaluation` dans ce projet, qui contient le package ROS2 et tous les fichiers associés :

```
sensor_data_evaluation/
├── build/                         # Dossiers de build générés par colcon
├── install/                       # Dossiers d'installation générés par colcon
├── log/                           # Logs de build colcon
├── logs/                          # Fichiers CSV de données et statistiques
│   ├── sensor_data_received.csv
│   └── sensor_stats_python.csv
├── sensor_data_evaluation/        # Package ROS2 principal
│   ├── package.xml
│   ├── setup.py / setup.cfg
│   ├── TEST.md                    # Documentation de test
│   ├── web_monitor.py             # Backend Flask pour dashboard
│   ├── launch/
│   │   └── sensor_data_launch.py  # Fichier de lancement ROS2
│   ├── resource/
│   │   └── sensor_data_evaluation # Fichier ressource ROS2
│   ├── sensor_data_evaluation/
│   │   ├── __init__.py
│   │   ├── sensor_data_publisher.py   # Node publisher
│   │   ├── sensor_data_subscriber.py  # Node subscriber
│   │   └── sensor_stats_node.py       # Node statistiques
│   ├── templates/
│   │   └── monitor.html               # Dashboard web
└── ... (autres dossiers générés automatiquement)
```

- **logs/** : contient les fichiers CSV générés par les nodes (historique, statistiques).
- **sensor_data_evaluation/** : package ROS2 complet avec code source, launch, ressources, templates, documentation de test et backend web.
- **build/, install/, log/** : générés automatiquement lors de la compilation avec `colcon build`.

**Pourquoi cette structure ?**  
Cette organisation respecte les standards ROS2 : chaque package doit contenir un fichier `package.xml`, un `setup.py` (pour Python), un dossier `resource/` (pour l'enregistrement du package), et éventuellement `launch/` pour les fichiers de lancement. Cela garantit la compatibilité avec les outils ROS2 (`colcon build`, `ros2 run`, etc.), la portabilité et la maintenabilité du projet. Les dossiers `logs/` et `templates/` facilitent la traçabilité et l'interface web.

## 4. Fonctionnalités détaillées

### 4.1 Node publisher
**Rôle :** Ce node simule un capteur en générant toutes les 0,5 s des valeurs aléatoires de température (14,8–35,2°C), humidité (29,8–70,2%) et pression (949,5–1050,5hPa), couvrant légèrement au-delà des plages normales pour tester la robustesse du système. Les valeurs sont publiées sur le topic `/sensor_data` sous forme de tableau de trois flottants.  
**Utilité :** Tester la chaîne ROS2 sans matériel réel, valider la détection d'anomalies et la réactivité du système.  
**Points clés :** Publication régulière, génération réaliste, extension volontaire des plages pour simuler des cas limites.

### 4.2 Node subscriber
**Rôle :** Reçoit chaque message, vérifie si chaque valeur est dans la plage attendue (15–35°C, 30–70%, 950–1050hPa), log « Valide » ou « Hors plage » dans la console, et enregistre chaque mesure dans `logs/sensor_data_received.csv` avec la date et l'heure.  
**Utilité :** Traçabilité, détection immédiate d'anomalies, constitution d'un historique exploitable.  
**Points clés :** Vérification automatique, log détaillé, enregistrement CSV, plages facilement modifiables dans le code.

### 4.3 Node statistiques
**Rôle :** Calcule en temps réel la moyenne, le min et le max pour chaque capteur à chaque nouvelle donnée reçue, et met à jour `logs/sensor_stats_python.csv`.  
**Utilité :** Vue synthétique de l'état du système, détection de dérives ou d'anomalies sur la durée.  
**Points clés :** Calculs automatiques, stockage CSV, stats séparées par capteur, facile à étendre.

### 4.4 Dashboard web Flask
**Rôle :** Interface web moderne affichant en temps réel les courbes, histogrammes, tableaux, statistiques et alertes (valeurs hors plage) à partir des CSV générés.  
**Utilité :** Visualisation à distance, identification rapide des anomalies, export des graphes, expérience utilisateur professionnelle.  
**Points clés :** Rafraîchissement automatique (WebSocket), mode sombre, responsive, signalement visuel, export PNG, facile à personnaliser.

## 5. Schéma de fonctionnement global

```
+-------------------+        +---------------------+
| sensor_data_      |        | sensor_data_        |
| publisher (Node)  |----->  | subscriber (Node)   |
|  (données aléa)   |        |  (vérif, log, CSV)  |
+-------------------+        +---------------------+
         |                           |
         |                           |
         |                           v
         |                 +---------------------+
         |                 | sensor_stats_node   |
         |                 | (stats, log, CSV)   |
         |                 +---------------------+
         |                           |
         |                           v
         v                           v
+-----------------------------------------------+
|         Fichiers CSV (logs/)                  |
+-----------------------------------------------+
         |
         v
+-------------------+
|  Flask server     |
|  (web_monitor.py) |
+-------------------+
         |
         v
+-------------------+
| Dashboard Web     |
| (monitor.html)    |
+-------------------+
```

## 6. Aperçu du code des nodes principaux

### Code du node publisher (sensor_data_publisher.py)

```python
import rclpy
from rclpy.node import Node
from std_msgs.msg import Float32MultiArray
import random

class SensorDataPublisher(Node):
    def __init__(self):
        super().__init__('sensor_data_publisher')
        self.publisher_ = self.create_publisher(Float32MultiArray, '/sensor_data', 10)
        self.timer = self.create_timer(0.5, self.publish_sensor_data)
        self.get_logger().info('SensorDataPublisher node started.')

    def publish_sensor_data(self):
        temperature = round(random.uniform(14.8, 35.2), 2)
        humidity = round(random.uniform(29.8, 70.2), 2)
        pressure = round(random.uniform(949.5, 1050.5), 2)
        msg = Float32MultiArray()
        msg.data = [temperature, humidity, pressure]
        self.publisher_.publish(msg)
        self.get_logger().info(f'Publié: Temp={temperature:.2f}°C, Hum={humidity:.2f}%, Press={pressure:.2f}hPa')

def main(args=None):
    rclpy.init(args=args)
    node = SensorDataPublisher()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
```

### Code du node subscriber (sensor_data_subscriber.py)

```python
import rclpy
from rclpy.node import Node
from std_msgs.msg import Float32MultiArray
import os
import csv
from datetime import datetime

class SensorDataSubscriber(Node):
    def __init__(self):
        super().__init__('sensor_data_subscriber')
        self.subscription = self.create_subscription(
            Float32MultiArray,
            '/sensor_data',
            self.listener_callback,
            10)
        self.get_logger().info('SensorDataSubscriber node started.')
        self.csv_file = 'logs/sensor_data_received.csv'
        os.makedirs('logs', exist_ok=True)
        if not os.path.exists(self.csv_file):
            with open(self.csv_file, 'w', newline='', encoding='utf-8') as f:
                writer = csv.writer(f)
                writer.writerow(['Date', 'Heure', 'Temperature', 'Humidity', 'Pressure'])

    def listener_callback(self, msg):
        temperature, humidity, pressure = msg.data
        temperature = float(f"{temperature:.2f}")
        humidity = float(f"{humidity:.2f}")
        pressure = float(f"{pressure:.2f}")
        now = datetime.now()
        date_str = now.strftime('%Y-%m-%d');
        time_str = now.strftime('%H:%M:%S');
        temp_ok = 15.0 <= temperature <= 35.0
        hum_ok = 30.0 <= humidity <= 70.0
        press_ok = 950.0 <= pressure <= 1050.0
        if temp_ok and hum_ok and press_ok:
            self.get_logger().info(f'Valide: Temp={temperature:.2f}°C, Hum={humidity:.2f}%, Press={pressure:.2f}hPa')
        else:
            self.get_logger().warn(f'Valeur hors plage! Temp={temperature:.2f}°C, Hum={humidity:.2f}%, Press={pressure:.2f}hPa')
        # Sauvegarde dans le CSV
        with open(self.csv_file, 'a', newline='', encoding='utf-8') as f:
            writer = csv.writer(f)
            writer.writerow([date_str, time_str, temperature, humidity, pressure])
```

### Code du node statistiques (sensor_stats_node.py)

```python
import rclpy
from rclpy.node import Node
from std_msgs.msg import Float32MultiArray
import os
import csv
from datetime import datetime

class SensorStatsNode(Node):
    def __init__(self):
        super().__init__('sensor_stats_node')
        self.subscription = self.create_subscription(
            Float32MultiArray,
            '/sensor_data',
            self.listener_callback,
            10)
        self.count = 0
        self.temp_sum = 0.0
        self.hum_sum = 0.0
        self.press_sum = 0.0
        self.temp_min = None
        self.temp_max = None
        self.hum_min = None
        self.hum_max = None
        self.press_min = None
        self.press_max = None
        self.csv_file = 'logs/sensor_stats_python.csv'
        os.makedirs('logs', exist_ok=True)
        if not os.path.exists(self.csv_file):
            with open(self.csv_file, 'w', newline='', encoding='utf-8') as f:
                writer = csv.writer(f)
                writer.writerow(['Date', 'Heure', 'Nb valeurs', 'Temp Moy', 'Temp Min', 'Temp Max', 'Hum Moy', 'Hum Min', 'Hum Max', 'Press Moy', 'Press Min', 'Press Max'])

    def listener_callback(self, msg):
        temperature, humidity, pressure = msg.data
        self.count += 1
        self.temp_sum += temperature
        self.hum_sum += humidity
        self.press_sum += pressure
        self.temp_min = temperature if self.temp_min is None else min(self.temp_min, temperature)
        self.temp_max = temperature if self.temp_max is None else max(self.temp_max, temperature)
        self.hum_min = humidity if self.hum_min is None else min(self.hum_min, humidity)
        self.hum_max = humidity if self.hum_max is None else max(self.hum_max, humidity)
        self.press_min = pressure if self.press_min is None else min(self.press_min, pressure)
        self.press_max = pressure if self.press_max is None else max(self.press_max, pressure)
        now = datetime.now()
        date_str = now.strftime('%Y-%m-%d');
        time_str = now.strftime('%H:%M:%S');
        with open(self.csv_file, 'a', newline='', encoding='utf-8') as f:
            writer = csv.writer(f)
            writer.writerow([
                date_str, time_str, self.count,
                round(self.temp_sum/self.count,2), round(self.temp_min,2), round(self.temp_max,2),
                round(self.hum_sum/self.count,2), round(self.hum_min,2), round(self.hum_max,2),
                round(self.press_sum/self.count,2), round(self.press_min,2), round(self.press_max,2)
            ])
```

### Code du dashboard web (web_monitor.py)

```python
from flask import Flask, render_template, jsonify
from flask_socketio import SocketIO, emit
import pandas as pd
import os

app = Flask(__name__)
socketio = SocketIO(app, cors_allowed_origins="*")

@app.route('/')
def index():
    return render_template('monitor.html')

@app.route('/data')
def data():
    # Lecture de la dernière ligne du CSV sensor_data_received.csv
    csv_path = os.path.join(os.path.dirname(__file__), '..', 'logs', 'sensor_data_received.csv')
    try:
        with open(csv_path, 'r') as f:
            lines = f.readlines()
            if len(lines) < 2:
                return jsonify({'temperature': None, 'humidity': None, 'pressure': None})
            last = lines[-1].strip().split(',')
            # Format: date,heure,temp,hum,pres
            return jsonify({
                'temperature': float(last[2]),
                'humidity': float(last[3]),
                'pressure': float(last[4])
            })
    except Exception as e:
        return jsonify({'temperature': None, 'humidity': None, 'pressure': None})

@socketio.on('request_data')
def handle_request_data():
    csv_path = os.path.join(os.path.dirname(__file__), '..', 'logs', 'sensor_data_received.csv')
    try:
        with open(csv_path, 'r') as f:
            lines = f.readlines()
            if len(lines) < 2:
                emit('sensor_data', {'temperature': None, 'humidity': None, 'pressure': None})
                return
            last = lines[-1].strip().split(',')
            emit('sensor_data', {
                'temperature': float(last[2]),
                'humidity': float(last[3]),
                'pressure': float(last[4])
            })
    except Exception as e:
        emit('sensor_data', {'temperature': None, 'humidity': None, 'pressure': None})
```

## 7. Interface web (dashboard)

L'**interface web** du projet, accessible via `web_monitor.py`, offre un tableau de bord moderne et interactif pour la visualisation en temps réel des données capteurs et des statistiques. Elle a été conçue pour une expérience utilisateur professionnelle, accessible sur PC, tablette ou smartphone.

- **Visualisation temps réel :** courbes, histogrammes et tableaux se mettent à jour automatiquement grâce à WebSocket (SocketIO).
- **Alertes visuelles :** toute valeur hors plage est signalée par un code couleur et une animation.
- **Statistiques dynamiques :** affichage des moyennes, min, max, nombre de mesures, etc.
- **Export :** possibilité d'exporter les graphiques au format PNG et de télécharger les CSV.
- **Responsive :** affichage optimisé pour tous les écrans.
- **Personnalisation facile :** couleurs, seuils, types de graphiques modifiables dans le code.

![Dashboard des données capteurs](/images/test2/donneeCapteur.jpg)

> **Astuce :** Pour personnaliser l'interface, modifiez `templates/monitor.html` (HTML/JS) et `web_monitor.py` (Flask backend).

## 8. Serveur Flask (backend)

Le **serveur Flask** (`web_monitor.py`) fait le lien entre les fichiers CSV générés par les nodes ROS2 et l'interface web. Pour démarrer le serveur et accéder au dashboard en temps réel, utilisez la commande suivante dans un terminal :

```
python3 web_monitor.py
```

Une fois le serveur lancé, ouvrez `http://localhost:5000` dans votre navigateur pour accéder à l'interface de supervision.

- **Lecture des CSV :** le backend lit les fichiers `logs/sensor_data_received.csv` et `logs/sensor_stats_python.csv` pour fournir les données à l'interface.
- **API REST :** des routes comme `/data` ou `/stats` renvoient les dernières valeurs ou statistiques au format JSON.
- **WebSocket (SocketIO) :** permet la mise à jour instantanée des graphiques sans recharger la page.
- **Sécurité :** par défaut, l'accès est ouvert en local. Pour un usage distant, il est recommandé d'ajouter une authentification et de passer en HTTPS.
- **Extensibilité :** il est facile d'ajouter de nouvelles routes (API, téléchargement CSV, etc.) ou de connecter d'autres sources de données.
- **Démarrage :** lancer le serveur avec `python3 web_monitor.py` puis ouvrir `http://localhost:5000` dans un navigateur.

> **Bonnes pratiques :** Séparez bien la logique backend (Flask) de la présentation (HTML/JS). Utilisez des environnements virtuels Python pour isoler les dépendances.

## 9. Illustrations clés du projet

### 9.1 Lancement des nodes ROS2

<video controls style="width: 100%; max-width: 600px; border-radius: 8px; background: #000;">
  <source src="/images/test2/publish.webm" type="video/webm">
  Votre navigateur ne supporte pas les vidéos HTML5.
</video>

### 9.2 Fichiers CSV générés

![Photo du CSV](/images/test2/ros2.jpeg)

### 9.3 Interface web (dashboard)

<video controls style="width: 100%; max-width: 600px; border-radius: 8px; background: #000;">
  <source src="/images/test2/dashboard.webm" type="video/webm">
  Votre navigateur ne supporte pas les vidéos HTML5.
</video>

## 10. FAQ & Cas d'usage

**FAQ :**

- **Q : Puis-je ajouter d'autres capteurs ?**  
  A : Oui, modifiez le publisher et adaptez le message/CSV.
- **Q : Comment changer les plages de validité ?**  
  A : Utilisez `ros2 param set` sur le node subscriber.
- **Q : Peut-on visualiser l'historique complet ?**  
  A : Oui, ouvrez le CSV dans Excel ou développez une page web dédiée.
- **Q : Comment exporter les données ?**  
  A : Utilisez l'export PNG du dashboard ou téléchargez le CSV via Flask.

**Cas d'usage :**

- Démo pédagogique ROS2 (université, formation, MOOC)
- Tests de robustesse d'algorithmes de monitoring
- Prototype de supervision IoT/industrielle
- Base pour projet d'analyse prédictive ou IA

## 11. Annexes & références

- [Documentation officielle ROS2 Humble](https://docs.ros.org/en/humble/index.html)
- [Documentation Flask](https://flask.palletsprojects.com/)
- [Documentation Flask-SocketIO](https://socket.io/docs/v4/)
- [Documentation Chart.js](https://www.chartjs.org/docs/latest/)
- [GitHub ROS2](https://github.com/ros2/ros2)
- **Annexes :** Fichiers CSV (`logs/`), code source Python, schémas et exemples de configuration dans le dépôt.

## 12. Limites et perspectives

- **Limites techniques :** Ce projet est conçu pour un usage pédagogique et une démonstration locale. Il n'est pas optimisé pour la haute disponibilité, la sécurité réseau, ni la gestion de très grands volumes de données.
- **Scalabilité :** L'architecture actuelle fonctionne pour quelques capteurs et un usage mono-machine. Pour un déploiement industriel ou multi-capteurs, il faudrait adapter la gestion des topics, la persistance des données et la supervision.
- **Sécurité :** L'accès distant via Flask/ngrok n'est pas sécurisé par défaut. Pour un usage en production, il est recommandé d'ajouter une authentification, du chiffrement (HTTPS), et des restrictions d'accès.
- **Perspectives :** Possibilité d'ajouter d'autres types de capteurs, d'intégrer une base de données, d'exporter vers le cloud, ou d'ajouter des modules d'analyse avancée (IA, détection d'anomalies, alertes automatiques, etc.).
- **Améliorations possibles :** Ajout de tests automatisés, interface d'administration, gestion multi-utilisateurs, internationalisation, monitoring distribué, etc.

### Pour aller plus loin
- **Sécurité :** Ajouter une authentification, passer en HTTPS, restreindre l'accès distant.
- **Déploiement :** Tester sur Raspberry Pi, conteneuriser avec Docker, héberger sur un cloud.
- **Scalabilité :** Gérer plusieurs capteurs, topics dynamiques, base de données pour l'historique.
- **Analyse avancée :** Intégrer des modules IA, détection d'anomalies, alertes automatiques.
- **Interface :** Ajouter des graphiques avancés, exporter vers Excel, internationaliser la documentation.
- **Tests :** Mettre en place des tests automatisés, CI/CD, monitoring distribué.

## Tableau récapitulatif des commandes principales

| Commande | Description |
|----------|-------------|
| `colcon build --packages-select sensor_data_evaluation` | Compiler le package ROS2 |
| `source install/setup.bash` | Activer l'environnement ROS2 |
| `ros2 launch sensor_data_evaluation sensor_data_launch.py` | Lancer tous les nodes via le fichier de lancement |
| `ros2 run sensor_data_evaluation sensor_data_publisher` | Lancer le node publisher seul |
| `ros2 run sensor_data_evaluation sensor_data_subscriber` | Lancer le node subscriber seul |
| `ros2 run sensor_data_evaluation sensor_stats_node` | Lancer le node statistiques seul |
| `python3 web_monitor.py` | Lancer le serveur web Flask (dashboard) |