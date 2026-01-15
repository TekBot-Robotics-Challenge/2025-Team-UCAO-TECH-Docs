# Test Final – Informatique

## Documentation IT – Système de Convoyeur Intelligent

Architecture logicielle avancée et système de contrôle en temps réel pour le tri automatisé des déchets.

---

## Introduction

### Contexte

Dans un monde où la gestion durable des déchets devient un enjeu majeur pour les villes industrielles, **TEKBOT CITY** ambitionne de mettre en place un système innovant afin d’optimiser le tri et la valorisation des déchets. Le tri automatisé, la traçabilité des flux et l’intégration d’outils numériques sont désormais essentiels pour répondre aux exigences environnementales, économiques et réglementaires.

### Vision et perspectives

L’ambition de ce projet est de démontrer comment l’innovation technologique peut transformer la gestion des déchets industriels. À court terme, l’objectif est de mettre en œuvre un système fiable, automatisé et connecté, capable de trier différents types de déchets en temps réel.

### Démarche de documentation

Cette documentation a été conçue afin d’assurer la transparence, la reproductibilité et l’amélioration continue du projet. Elle détaille chaque étape de la conception, depuis les choix techniques jusqu’aux méthodes de développement.

---

## Description du système

### Présentation générale

Le système de convoyeur intelligent présenté ici est une solution innovante de tri automatisé des déchets, conçue pour répondre aux défis de l’Industrie 4.0 et du développement durable.

### Diagramme de séquence – Fonctionnement du système


```
sequenceDiagram
    participant Operator as Operator
    participant Object as Waste (colored cube)
    participant PresenceSensor as Presence Sensor
    participant Conveyor as Conveyor
    participant ColorSensor as Color Sensor
    participant Microcontroller as Microcontroller
    participant WebInterface as Web Interface
    participant Collector as Collector

    Operator->>Object: Places waste on conveyor
    Object->>PresenceSensor: Passage detected
    PresenceSensor-->>Microcontroller: Presence signal
    Microcontroller->>Conveyor: Belt startup
    Conveyor->>Object: Transport to analysis zone
    Object->>ColorSensor: Arrival under sensor
    ColorSensor-->>Microcontroller: Color measurement
    Microcontroller->>WebInterface: Counter update
    Conveyor->>Object: Stop at end of path
    Collector->>Object: Collects waste
```


### Objectifs du système

- Détecter automatiquement la présence et la couleur des objets  
- Classer et trier les déchets de manière autonome  
- Assurer une traçabilité complète du fonctionnement  
- Fournir une interface web de supervision  

### Avantages du système

- Tri automatisé, rapide et fiable  
- Adaptabilité à différents types de déchets  
- Réduction des interventions manuelles  
- Collecte et analyse des données  

---

## Détection intelligente

### Détection de couleur avec le TCS34725

Le capteur TCS34725 est un composant électronique capable d’identifier la couleur d’un objet en analysant la lumière qu’il réfléchit. En décomposant cette lumière en ses composantes (rouge, vert, bleu), le capteur détermine la teinte dominante.

#### Arduino – Détection de couleur avec le TCS34725

````cpp
#include <Wire.h>
#include <Adafruit_TCS34725.h>
#include <Servo.h>

// Pin definitions
#define LASER_ENTRY_PIN 2
#define LDR_ENTRY_PIN A0
#define LASER_EXIT_PIN 3
#define LDR_EXIT_PIN A1
#define SERVO_SORT1_PIN 8
#define SERVO_SORT2_PIN 9

Adafruit_TCS34725 tcs = Adafruit_TCS34725();
Servo servoSort1;
Servo servoSort2;

void setup() {
    // Pin initialization
    pinMode(LASER_ENTRY_PIN, INPUT);
    pinMode(LDR_ENTRY_PIN, INPUT);
    pinMode(LASER_EXIT_PIN, INPUT);
    pinMode(LDR_EXIT_PIN, INPUT);
    
    // Servo initialization
    servoSort1.attach(SERVO_SORT1_PIN);
    servoSort2.attach(SERVO_SORT2_PIN);
    
    // Color sensor initialization
    if (tcs.begin()) {
        Serial.println("TCS34725 sensor detected!");
    }
    
    Serial.begin(9600);
}

void loop() {
    // Entry presence detection
    if (detectEntryPresence()) {
        activateConveyor();
        
        // Color detection
        String color = detectColor();
        sortObject(color);
        
        // Data transmission
        sendData(color, "RUNNING");
    }
    
    // Exit presence detection
    if (detectExitPresence()) {
        stopConveyor();
        sendData("NONE", "STOPPED");
    }
}

````

### Détection de présence avec KY-008 + LDR

Un capteur de présence permet de détecter si un objet se trouve dans une zone donnée. Dans notre convoyeur, nous utilisons une combinaison laser KY-008 et photorésistance (LDR) afin de détecter instantanément le passage des objets.

#### Arduino – Détection de présence

````cpp
#define LASER_PIN 8
#define LDR_PIN A0
#define THRESHOLD 400

bool detectPresence(int ldrPin, int threshold, int nbValidations = 3) {
    int counter = 0;
    for (int i = 0; i < nbValidations; i++) {
        int ldrValue = analogRead(ldrPin);
        if (ldrValue < threshold) {
            counter++;
        }
        delay(20);
    }
    return (counter == nbValidations);
}

void setup() {
    pinMode(LASER_PIN, OUTPUT);
    pinMode(LDR_PIN, INPUT);
    digitalWrite(LASER_PIN, HIGH);
}

void loop() {
    if (detectPresence(LDR_PIN, THRESHOLD)) {
        Serial.println("Presence confirmed!");
        // Action to perform
    }
    delay(100);
}
````

## Automatisation du convoyeur
Architecture de l’automatisation

L’architecture du système repose sur une intelligence embarquée qui contrôle l’ensemble du processus de tri : détection, identification, orientation et suivi.

Arduino – Code principal du système automatisé

#include <Wire.h>
#include <Adafruit_TCS34725.h>
#include <Servo.h>

// Pin definitions
#define LASER_ENTRY_PIN 2
#define LDR_ENTRY_PIN A0
#define LASER_EXIT_PIN 3
#define LDR_EXIT_PIN A1
#define SERVO_SORT1_PIN 8
#define SERVO_SORT2_PIN 9

Adafruit_TCS34725 tcs = Adafruit_TCS34725();
Servo servoSort1;
Servo servoSort2;

void setup() {
    // Pin initialization
    pinMode(LASER_ENTRY_PIN, INPUT);
    pinMode(LDR_ENTRY_PIN, INPUT);
    pinMode(LASER_EXIT_PIN, INPUT);
    pinMode(LDR_EXIT_PIN, INPUT);
    
    // Servo initialization
    servoSort1.attach(SERVO_SORT1_PIN);
    servoSort2.attach(SERVO_SORT2_PIN);
    
    // Color sensor initialization
    if (tcs.begin()) {
        Serial.println("TCS34725 sensor detected!");
    }
    
    Serial.begin(9600);
}

void loop() {
    // Entry presence detection
    if (detectEntryPresence()) {
        activateConveyor();
        
        // Color detection
        String color = detectColor();
        sortObject(color);
        
        // Data transmission
        sendData(color, "RUNNING");
    }
    
    // Exit presence detection
    if (detectExitPresence()) {
        stopConveyor();
        sendData("NONE", "STOPPED");
    }
}



### Gestion des erreurs

#### Cas d’erreurs

- Aucun objet détecté
- Erreur de détection de couleur
- Objets atypiques ou non conformes
- Défaillance matérielle des capteurs

#### Solutions

- Validation sur plusieurs mesures
- Bac de tri spécial « erreur »
- Seuils de détection adaptatifs
- Arrêt d’urgence et alertes

---

## Interface web

### Présentation du tableau de bord

L’interface web développée avec HTML, CSS, JavaScript et Bootstrap offre une expérience utilisateur moderne, fluide et responsive pour la supervision en temps réel des opérations de tri.

### Technologies utilisées

- **Frontend** : HTML5, CSS3, JavaScript, Bootstrap
- **Backend:** Firebase (Realtime Database)
- **Communication:** WebSocket, REST API
- **Microcontrôleur:** ESP8266 + Arduino

### Fonctionnalités principales

- Affichage des compteurs en temps réel
- Visualisation des statistiques de tri
- Gestion des utilisateurs et des accès
- Export des données pour analyse

### Intégration Firebase

Firebase fournit une plateforme complète de synchronisation en temps réel entre le microcontrôleur et l’interface web, garantissant une mise à jour instantanée des données.

#### JavaScript – Connexion Firebase

````javascript
// Firebase Configuration
const firebaseConfig = {
    apiKey: "your-api-key",
    authDomain: "your-project.firebaseapp.com",
    databaseURL: "https://your-project.firebaseio.com",
    projectId: "your-project",
    storageBucket: "your-project.appspot.com",
    messagingSenderId: "123456789",
    appId: "your-app-id"
};

// Initialization
const app = firebase.initializeApp(firebaseConfig);
const db = firebase.database();

// Real-time change listening
db.ref('counters').on('value', (snapshot) => {
    const data = snapshot.val();
    updateDashboard(data);
});

function updateDashboard(data) {
    // Interface update
    document.getElementById('counter-red').textContent = data.red || 0;
    document.getElementById('counter-green').textContent = data.green || 0;
    document.getElementById('counter-blue').textContent = data.blue || 0;
    document.getElementById('counter-yellow').textContent = data.yellow || 0;
}
````

## Conclusion et Perspectives

### Résumé

Ce projet de convoyeur intelligent a démontré la faisabilité d’un tri des déchets automatisé, fiable et connecté. L’intégration de technologies modernes a permis la création d’une solution complète répondant aux enjeux industriels et environnementaux.

### Évolutions futures

#### Améliorations techniques
- Intégration de capteurs supplémentaires (poids, RFID)
- Intégration de capteurs supplémentaires (poids, RFID)
- Renforcement de la sécurité et de la gestion des accès
- Déploiement à grande échelle

#### Applications futures
- Extension à d’autres types de tri
- Intégration dans les réseaux urbains intelligents
- Applications logistiques et industrielles
- Contribution à l’économie circulaire