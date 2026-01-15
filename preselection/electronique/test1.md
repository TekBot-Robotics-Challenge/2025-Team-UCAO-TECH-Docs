# Test 1: Capteur d'entrée - Gyroscope et Accéléromètre

Détection d'orientation avec accéléromètre et gyroscope MPU6050 - Conversion des grandeurs physiques en signaux électriques exploitables.




## Présentation

Un capteur est un dispositif électronique conçu pour convertir des grandeurs physiques ou environnementales (mouvement, température, pression, etc.) en signaux électriques exploitables. Parmi la diversité des capteurs disponibles, ce test se concentre sur l'accéléromètre et le gyroscope, composants clés en robotique et navigation autonome.

### Caractéristiques principales

- Détection d'orientation en temps réel
- Protocole de communication I2C
- Intégration d'un afficheur LCD
- Système portable et autonome

### Objectif

Ce test vise à mesurer, interpréter et afficher en temps réel l'orientation et l'accélération d'une main à l'aide d'un capteur inertiel connecté à un microcontrôleur. Les données sont visualisées sur un écran LCD via communication I2C.

---

## Présentation du capteur

### Accéléromètre (MPU6050)

Mesure l'accélération linéaire sur trois axes (X, Y, Z), détectant les variations de vitesse et de position.

- Détection de mouvement (avant, arrière, inclinaison)
- Correction de trajectoire
- Détection de chute et d'impact

### Gyroscope (MPU6050)

Mesure la vitesse angulaire sur trois axes, déterminant la vitesse et la direction de rotation.

- Suivi d'orientation d'objet
- Stabilisation du mouvement
- Amélioration de la précision de navigation

### Identification du capteur

Nous avons sélectionné le module GY-521, basé sur le capteur MPU6050, qui intègre un accéléromètre et un gyroscope dans un seul composant.

**Fonctionnement du capteur:**
- **Accéléromètre:** Mesure l'accélération en m/s² ou en g
- **Gyroscope:** Mesure la vitesse angulaire en °/s
- **Communication I2C:** Adresse par défaut 0x68

---

## Matériel utilisé

| Composant | Référence | Quantité | Objectif |
|-----------|-----------|----------|----------|
| Microcontrôleur | Arduino UNO (ATmega328P) | 1 | Noyau du système et traitement |
| Capteur | GY-521 (MPU6050) | 1 | Détection de mouvement et orientation |
| Afficheur | LCD 16x2 + module I2C | 1 | Visualisation des données en temps réel |
| Alimentation | Batterie 9V | 1 | Source d'énergie portable |
| Câblage | Breadboard, jumpers | - | Connexions du circuit |
| Composants passifs | Résistances 10 kΩ | 2 | Résistances de tirage I2C |

---

## Présentation des composants

### Arduino UNO

Microcontrôleur ATmega328P - Cerveau du système pour le traitement des données et le contrôle.

### Écran LCD 16x2 + I2C

Affichage en temps réel des données d'orientation et d'accélération.

### Breadboard

Plateforme de prototypage pour un assemblage facile du circuit et des tests.

### Jumpers

Câblage flexible pour le prototypage rapide et les connexions.

### Résistances 10 kΩ

Stabilisation du bus I2C et fiabilité de la communication.

### Batterie 9V

Source d'énergie portable avec régulation interne de tension.

---

## Schéma électronique

Le schéma complet du système capteur MPU6050 avec Arduino UNO et affichage LCD.

---

## Fonctionnement global du système

### Étapes de fonctionnement

1. **Initialisation des composants**
   - Configuration et calibrage de l'écran LCD et du capteur MPU6050

2. **Calibrage automatique**
   - Calibrage du capteur au démarrage du système

3. **Lecture des données brutes**
   - Acquisition continue des données d'accélération et d'orientation

4. **Détection de la direction dominante**
   - Traitement par algorithme pour la direction du mouvement

5. **Affichage de la direction et de l'intensité**
   - Résultat en temps réel sur LCD des données traitées

### Spécifications techniques

- **Fréquence d'échantillonnage:** 3.3 Hz (délai de 300ms)
- **Communication:** I2C à 400kHz
- **Précision:** ±2% pour l'accélération
- **Consommation d'énergie:** ~50mA
- **Tension de fonctionnement:** 5V CC

---

## Code Arduino

### Bibliothèques utilisées

- **Wire.h** – Communication I2C
- **Adafruit_MPU6050.h** – Contrôle du capteur
- **Adafruit_Sensor.h** – Structures et abstractions
- **LiquidCrystal_I2C.h** – Gestion de l'écran LCD

### Caractéristiques du code

- Traitement des données en temps réel
- Gestion automatique des erreurs
- Algorithme de détection de direction
- Gestion de l'afficheur LCD
- Calibrage du capteur

### Code complet

````cpp
// Test 1 - GY-521 (MPU6050) avec LCD et Arduino UNO
// UCAO-TECH TRC 2025

#include <Wire.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <LiquidCrystal_I2C.h>

Adafruit_MPU6050 mpu;
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(115200);
  Wire.begin();
  lcd.begin();
  lcd.backlight();
  lcd.print("Init capteur...");

  if (!mpu.begin()) {
    lcd.clear();
    lcd.print("Erreur MPU6050");
    while (1);
  }
  lcd.clear();
  lcd.print("Capteur pret.");
  delay(1000);
}

void loop() {
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);

  float ax = a.acceleration.x;
  float ay = a.acceleration.y;
  float az = a.acceleration.z;

  lcd.clear();
  if (abs(ax) > abs(ay) && abs(ax) > abs(az)) {
    lcd.print(ax > 0 ? "Droite" : "Gauche");
  } else if (abs(ay) > abs(az)) {
    lcd.print(ay > 0 ? "Avant" : "Arriere");
  } else {
    lcd.print(az > 0 ? "Haut" : "Bas");
  }
  lcd.setCursor(0, 1);
  lcd.print("Acc: ");
  lcd.print(max(max(abs(ax), abs(ay)), abs(az)), 2);
  lcd.print(" g");
  delay(300);
}
````

## 🎥 Vidéos de démonstration

- **Démonstration principale**  
  https://www.youtube.com/watch?v=3eNkmmQ-iXk

- **Test des axes**  
  https://www.youtube.com/watch?v=REr67c1P6QY

- **Fonctionnement en temps réel**  
  https://www.youtube.com/watch?v=27L5mn_YXMU

---

## ⚠️ Problèmes rencontrés

| Problème | Cause racine | Solution appliquée |
|---------|-------------|--------------------|
| Affichage incohérent | Valeurs de seuil incorrectes | Ajustement et calibration des seuils |
| Orientation incorrecte | Erreur de calibration de l’axe Z | Calibration correcte de l’axe Z |
| LCD instable | Fluctuations de l’alimentation | Vérification et stabilisation de l’alimentation |

---

## ✅ Conclusion

### 🎯 Réalisations

- Application de compétences en électronique et en programmation  
- Utilisation d’un capteur combiné accéléromètre–gyroscope  
- Conception d’un circuit fonctionnel avec interface LCD  
- Implémentation du traitement des données en temps réel  

### 📥 Téléchargements

- `test1_input.ino`  
- Schéma KiCad

---

**UCAO-TECH TRC 2025**  
*Test électronique 1 – Accéléromètre & Gyroscope*
