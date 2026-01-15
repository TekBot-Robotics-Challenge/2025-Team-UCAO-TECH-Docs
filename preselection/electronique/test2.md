# Test 2: Communication Test - La boîte noire

Système d'enregistrement et de transmission de données de mouvement en temps réel à l'aide du capteur MPU6050 dans une enceinte cubique.

**Durée:** 1 semaine



## Introduction

Dans les secteurs aérospatial, automobile et ferroviaire, les boîtes noires sont essentielles pour enregistrer les données de fonctionnement. Inspirés par ces systèmes, nous avons conçu un dispositif capable d'enregistrer et de transmettre en temps réel les données de mouvement d'un robot à l'aide d'un capteur MPU6050 (accéléromètre + gyroscope) intégré dans une boîte cubique.

---

## Objectifs du test

- Implémenter un système d'acquisition de données inertielles (MPU6050)
- Transmettre les données via le bus I2C vers une station de contrôle
- Afficher les données en temps réel sur un écran LCD
- Utiliser des microcontrôleurs ATmega328P sans cartes Arduino
- Documenter la conception du PCB et assurer une présentation professionnelle

---

## Composants utilisés

### 2 × ATmega328P

Noyau du système, ces microcontrôleurs 8 bits gèrent:
- Communication I2C entre les modules
- Traitement des données du capteur
- Contrôle de l'afficheur LCD

**Spécifications:** 32KB Flash, 2KB SRAM, 16MHz

### 1 × Module MPU6050

Capteur 6 axes (gyroscope + accéléromètre) utilisé pour:
- Détection d'orientation spatiale
- Mesure des mouvements soudains
- Référence de gravité terrestre

**Communication I2C** (adresse 0x68)

### 1 × Écran LCD 16x2

Interface de visualisation des données:
- Affiche les données en temps réel
- Contrôlé via interface I2C
- Adresse typique: 0x27 ou 0x3F
- Consommation: ~1mA

### 1 × Régulateur de tension 5V

Stabilise l'alimentation:
- Protège les composants sensibles
- Type: LM7805
- Courant max: 1A (avec dissipateur thermique)

---

## Architecture du système

Le système est distribué en deux modules:

1. **Module capteur (boîte noire):** contient l'ATmega328P maître I2C et le MPU6050
2. **Station de contrôle:** contient l'ATmega328P esclave I2C et l'écran LCD

---

## Schémas électroniques (réalisés avec KiCad)

Les circuits ont été conçus avec KiCad pour chaque sous-système du projet.

### Schéma d'alimentation

![Schéma d'alimentation](../../public/images_electronique/test2/IMG_Circuit_Alimentation.PNG)

### Schéma de la boîte noire

![Schéma boîte noire](../../public/images_electronique/test2/img_Circuit_Boite_Noire.PNG)

### Schéma de la station de contrôle

![Schéma station de contrôle](../../public/images_electronique/test2/img_Circuit_Station.PNG)

### Téléchargement des fichiers KiCad

Téléchargez tous les fichiers sources KiCad incluant les schémas et les PCB du projet:

[📥 Télécharger le dossier KiCad complet (RAR)](Schemas/Circuit_electronique_test2.rar)

---

## Circuits imprimés (PCB)

Support physique du circuit: PCB personnalisé pour chaque module: alimentation, boîte noire et station de contrôle.

### Carte d'alimentation

**Vue 2D**
![PCB alimentation 2D](../../public/images_electronique/test2/img_PCBAlimentation.PNG)

**Vue 3D**
![PCB alimentation 3D](../../public/images_electronique/test2/img_PCB_3D_Alimentation.PNG)

### Carte boîte noire

**Vue 2D**
![PCB boîte noire 2D](../../public/images_electronique/test2/img_PCB_2D_boite_noire.PNG)

**Vue 3D**
![PCB boîte noire 3D](../../public/images_electronique/test2/img_PCB_3D_boite_noire.PNG)

### Carte station de contrôle

**Vue 2D**
![PCB station 2D](../../public/images_electronique/test2/imgSC_PCB.PNG)

**Vue 3D**
![PCB station 3D](../../public/images_electronique/test2/imgSC_3D_front.PNG)

---

## Simulation Proteus

Le module **MPU6050** n'étant pas disponible dans la bibliothèque officielle Proteus, nous avons simulé son comportement en injectant directement des données constantes dans le microcontrôleur maître (ATmega328P). Cela permet de vérifier le fonctionnement du bus I2C, la transmission des données et l'afficheur LCD.

### Structure du dossier de simulation

```
📁 Simulation_Proteus_Black_Box
├── 📁 master
│   ├── master.ino
└── 📁 slave
    └── slave.ino
```

### Téléchargement du dossier de simulation

[📥 Télécharger le projet de simulation (.zip)](Codes/Code_Source_Simulation.rar)

### Vidéo de démonstration de simulation

Voir la vidéo de démonstration de la simulation Proteus

---

## Code

### Côté boîte noire (Maître I2C avec MPU6050)

````cpp
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#define MPU6050_ADDR 0x68
#define SLAVE_ADDR 0x20

// === Maître I2C ===
void I2C_Init() {
    TWSR = 0x00;
    TWBR = 72; // 100kHz à 16MHz
}

void I2C_Start() {
    TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);
    while (!(TWCR & (1 << TWINT)));
}

void I2C_Stop() {
    TWCR = (1 << TWINT) | (1 << TWSTO) | (1 << TWEN);
    _delay_us(10);
}

void I2C_Write(uint8_t data) {
    TWDR = data;
    TWCR = (1 << TWINT) | (1 << TWEN);
    while (!(TWCR & (1 << TWINT)));
}

uint8_t I2C_Read_ACK() {
    TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWEA);
    while (!(TWCR & (1 << TWINT)));
    return TWDR;
}

uint8_t I2C_Read_NACK() {
    TWCR = (1 << TWINT) | (1 << TWEN);
    while (!(TWCR & (1 << TWINT)));
    return TWDR;
}

// === MPU6050 ===
void MPU6050_Init() {
    I2C_Start();
    I2C_Write(MPU6050_ADDR << 1);  // Mode écriture
    I2C_Write(0x6B); // PWR_MGMT_1
    I2C_Write(0);    // Réveil
    I2C_Stop();
}

int16_t MPU6050_ReadAxis(uint8_t regH) {
    I2C_Start();
    I2C_Write(MPU6050_ADDR << 1);  // Écriture
    I2C_Write(regH);               // Registre à lire
    I2C_Start();
    I2C_Write((MPU6050_ADDR << 1) | 1); // Lecture
    uint8_t high = I2C_Read_ACK();
    uint8_t low = I2C_Read_NACK();
    I2C_Stop();
    return (int16_t)(high << 8 | low);
}

int main() {
    DDRB |= (1 << PB5); // LED de débogage
    I2C_Init();
    MPU6050_Init();

    while (1) {
        int16_t accX = MPU6050_ReadAxis(0x3B);
        int16_t accY = MPU6050_ReadAxis(0x3D);
        int16_t accZ = MPU6050_ReadAxis(0x3F);

        // Envoi des données à l'esclave
        I2C_Start();
        I2C_Write(SLAVE_ADDR << 1); // Esclave
        I2C_Write(accX >> 8); I2C_Write(accX & 0xFF);
        I2C_Write(accY >> 8); I2C_Write(accY & 0xFF);
        I2C_Write(accZ >> 8); I2C_Write(accZ & 0xFF);
        I2C_Stop();

        PORTB ^= (1 << PB5);
        _delay_ms(300);
    }
}
````

### Côté station de contrôle (Esclave I2C + LCD 4-bit)
````cpp
#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdio.h>

#define LCD_PORT PORTD
#define LCD_DDR DDRD
#define RS PD0
#define EN PD1

volatile int16_t accX, accY, accZ;
volatile uint8_t data_received = 0;

// === Fonctions LCD 4-bit ===
void LCD_Command(uint8_t cmd) {
    LCD_PORT = (LCD_PORT & 0x0F) | (cmd & 0xF0);
    LCD_PORT &= ~(1 << RS);
    LCD_PORT |= (1 << EN);
    _delay_us(1);
    LCD_PORT &= ~(1 << EN);
    _delay_us(200);

    LCD_PORT = (LCD_PORT & 0x0F) | (cmd << 4);
    LCD_PORT |= (1 << EN);
    _delay_us(1);
    LCD_PORT &= ~(1 << EN);
    _delay_ms(2);
}

void LCD_Char(char data) {
    LCD_PORT = (LCD_PORT & 0x0F) | (data & 0xF0);
    LCD_PORT |= (1 << RS);
    LCD_PORT |= (1 << EN);
    _delay_us(1);
    LCD_PORT &= ~(1 << EN);
    _delay_us(200);

    LCD_PORT = (LCD_PORT & 0x0F) | (data << 4);
    LCD_PORT |= (1 << RS);
    LCD_PORT |= (1 << EN);
    _delay_us(1);
    LCD_PORT &= ~(1 << EN);
    _delay_ms(2);
}

void LCD_Init() {
    LCD_DDR = 0xFF;
    _delay_ms(50);
    LCD_Command(0x02);
    LCD_Command(0x28);
    LCD_Command(0x0C);
    LCD_Command(0x06);
    LCD_Command(0x01);
}

void LCD_Print(char *str) {
    while (*str) {
        LCD_Char(*str++);
    }
}

// === ISR pour réception I2C ===
ISR(TWI_vect) {
    static uint8_t buffer[6];
    static uint8_t index = 0;

    switch (TWSR & 0xF8) {
        case 0x60: // Adresse esclave reçue (Écriture)
            index = 0;
            TWCR |= (1 << TWEA) | (1 << TWINT);
            break;
        case 0x80: // Données reçues
            buffer[index++] = TWDR;
            if (index >= 6) {
                accX = (buffer[0] << 8) | buffer[1];
                accY = (buffer[2] << 8) | buffer[3];
                accZ = (buffer[4] << 8) | buffer[5];
                data_received = 1;
                index = 0; // Réinitialiser après réception
            }
            TWCR |= (1 << TWEA) | (1 << TWINT);
            break;
        default:
            TWCR |= (1 << TWEA) | (1 << TWINT);
            break;
    }
}

int main() {
    DDRB |= (1 << PB1); // LED de débogage pour signal de réception
    LCD_Init();

    // I2C comme esclave
    TWAR = (0x20 << 1);  // Adresse esclave 0x20
    TWCR = (1 << TWEA) | (1 << TWEN) | (1 << TWIE);
    sei(); // Interruptions globales

    char text[16];

    while (1) {
        if (data_received) {
            LCD_Command(0x80); // Ligne 1
            sprintf(text, "X:%4d Y:%4d", accX, accY);
            LCD_Print(text);

            LCD_Command(0xC0); // Ligne 2
            sprintf(text, "Z:%4d", accZ);
            LCD_Print(text);

            PORTB ^= (1 << PB1);  // Clignoter la LED pour débogage
            data_received = 0;
        }
    }
}
````

---

## Explication: Simulation vs Réalité

Bien que la simulation dans Proteus soit proche de la réalité, certaines différences peuvent exister en raison de:
- Modèles de composants idéalisés dans Proteus
- Absence de bruit électrique et d'autres interférences
- Comportement légèrement différent des microcontrôleurs dans un environnement simulé

---

## Vidéo de démonstration

Une vidéo montrant le fonctionnement du système dans la réalité est disponible ici:

[📹 Voir la vidéo de démonstration](Videos/Demo_Test2.mp4)

---

## Contraintes et recommandations

- Assurez-vous que tous les composants sont correctement alimentés.
- Vérifiez les connexions I2C (SDA, SCL) entre les modules.
- Utilisez des résistances de tirage appropriées pour le bus I2C.
- Pour des tests prolongés, envisagez un boîtier pour protéger l'électronique.

---

## Critères d'évaluation

- Fonctionnalité du système (acquisition et transmission des données)
- Précision des données affichées
- Robustesse de la communication I2C
- Qualité de la documentation et du PCB

---

## Références techniques

Liens vers les documents techniques (fiches techniques) utilisés dans ce projet :

- [ATmega328P – Datasheet (Microchip)](https://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-8271-8-bit-AVR-Microcontroller-ATmega328-328P_datasheet.pdf)
- [MPU6050 – Datasheet (TDK InvenSense)](https://invensense.tdk.com/download-pdf/mpu-6000-datasheet/)
- [Écran LCD HD44780 – Datasheet](https://www.sparkfun.com/datasheets/LCD/HD44780.pdf)
- [LM7805 – Datasheet (STMicroelectronics)](https://www.st.com/resource/en/datasheet/l7805cv.pdf)


---

## Conclusion

Ce projet a permis de:
- Comprendre et utiliser le protocole I2C pour la communication entre microcontrôleurs et capteurs.
- Concevoir des circuits imprimés (PCB) pour des applications embarquées.
- Intégrer des capteurs inertiels dans des systèmes robotiques pour la détection de mouvement et d'orientation.

Des améliorations futures pourraient inclure:
- L'ajout d'une mémoire externe pour l'enregistrement des données.
- L'utilisation d'une batterie avec gestion de l'alimentation pour une plus grande autonomie.
- L'implémentation d'un système de calibration automatique pour le MPU6050.

