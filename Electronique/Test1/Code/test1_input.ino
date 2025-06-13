#include <Wire.h>                    // Bibliothèque pour communication I2C
#include <Adafruit_MPU6050.h>       // Bibliothèque pour le capteur MPU6050
#include <Adafruit_Sensor.h>        // Bibliothèque capteurs génériques Adafruit
#include <LiquidCrystal_I2C.h>      // Bibliothèque pour écran LCD I2C

// --- Déclaration des objets capteurs et affichage ---
Adafruit_MPU6050 mpu;                      // Objet MPU6050
LiquidCrystal_I2C lcd(0x27, 16, 2);        // LCD à l'adresse I2C 0x27, 16 colonnes, 2 lignes

// --- Variables pour les mesures d'accélération ---
float ax, ay, az;                          // Accélérations mesurées
float ax_offset = 0, ay_offset = 0, az_offset = 0;  // Offsets pour calibration

void setup() {
  Serial.begin(115200);        // Initialisation de la communication série
  Wire.begin();                // Démarre le bus I2C

  // --- Initialisation du MPU6050 ---
  if (!mpu.begin()) {
    Serial.println("Erreur : capteur MPU6050 non détecté !");
    while (1);  // Boucle bloquante si le capteur est absent
  }

  // --- Initialisation de l'écran LCD ---
  lcd.begin();              // Démarre l'écran LCD
  lcd.backlight();          // Active le rétroéclairage
  lcd.setCursor(0, 0);      // Positionne le curseur
  lcd.print("Calibration..."); 
  delay(2000);              // Pause pour laisser le temps au système de se stabiliser

  // --- Calibration du capteur ---
  float temp_x = 0, temp_y = 0, temp_z = 0;
  sensors_event_t a, g, temp;

  for (int i = 0; i < 100; i++) {   // Moyenne sur 100 lectures
    mpu.getEvent(&a, &g, &temp);
    temp_x += a.acceleration.x;
    temp_y += a.acceleration.y;
    temp_z += a.acceleration.z;
    delay(10);
  }
  ax_offset = temp_x / 100;    // Calcul des offsets
  ay_offset = temp_y / 100;
  az_offset = temp_z / 100;

  // --- Message de fin de calibration ---
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Pret !");
  delay(1000);
}

void loop() {
  // --- Lecture des données du capteur ---
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);

  ax = a.acceleration.x;
  ay = a.acceleration.y;
  az = a.acceleration.z;

  // --- Détection de la direction dominante ---
  String direction = "IMMOBILE";

  if (ax > 0 && ay < 0 && az < 0) {
    direction = "Gauche";
  } else if (ax > 0 && ay > 4 && az < 0) {
    direction = "Droite";
  } else if (ax > 0 && ay > 0 && az > 0) {
    direction = "Devant";
  } else if (ax > 0 && ay >= 0 && ay < 4 && az < -4) {
    direction = "Derrière";
  }

  // --- Calcul de la norme du vecteur accélération ---
  float accTotal = sqrt(ax * ax + ay * ay + az * az);

  // --- Affichage sur le LCD ---
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Dir: " + direction);  // Direction détectée
  lcd.setCursor(0, 1);
  lcd.print("Acc: ");
  lcd.print(accTotal, 2);          // Accélération totale en m/s²
  lcd.print(" m/s2");

  // --- Affichage des données sur le moniteur série ---
  Serial.print("ax: "); Serial.print(ax, 2);
  Serial.print(" | ay: "); Serial.print(ay, 2);
  Serial.print(" | az: "); Serial.print(az, 2);
  Serial.print(" | Dir: "); Serial.println(direction);

  delay(3000);  // Pause entre deux mesures
}
