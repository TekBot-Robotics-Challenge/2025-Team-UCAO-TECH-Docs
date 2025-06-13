# Test Final – Système de Convoyeur Intelligent

## 🎯 Objectif

Concevoir un convoyeur mécanique intelligent capable de trier 4 types de déchets (représentés par des cubes de couleur) et d’envoyer en temps réel les données de tri à une interface web de suivi.

---

## 🧠 Fonctionnement attendu

1. Le tapis reste immobile jusqu’à détection de la présence d’un déchet.
2. Le capteur de couleur identifie la couleur du cube.
3. Le système indique manuellement où déposer le déchet trié.
4. L’interface web affiche les quantités triées en temps réel (par couleur).
5. L’administrateur peut suivre le tout sur une page claire avec les logos **TEKBOT** et **TRC2025**.

---

## 🔧 Matériel utilisé

| Composant | Référence | Rôle |
|-----------|-----------|------|
| Microcontrôleur | ATmega328P ou Arduino Nano | Traitement |
| Capteur couleur | TCS34725 / autre | Détection couleur |
| Capteur présence | Laser KY-008 + photorésistance | Détection présence |
| Interface web | HTML/JS/ESP Wi-Fi | Suivi en temps réel |
| Tapis roulant | Mécanisme conçu sur SolidWorks | Transport des déchets |
| Alimentation | Batterie lithium | Source d’énergie |

---

## 🗂️ Organisation des fichiers

- `Code/` : Fichiers `.ino`, scripts web embarqués
- `PCB_KiCad/` : Schémas, PCB, rendu 3D
- `Design3D/` : Modèles SolidWorks du convoyeur
- `Interface_Web/` : HTML, CSS, JS pour l’interface
- `Video/` : Démo du système en fonctionnement

---

## 🖼️ Aperçu du système

![Convoyeur 3D](../Design3D/convoyeur_preview.png)

---

## 📚 Ressources utiles

- [Datasheet TCS34725](lien)
- [ESPAsyncWebServer](https://github.com/me-no-dev/ESPAsyncWebServer)

---

## 👥 Membres contributeurs

- Nom 1 – Électronique
- Nom 2 – IT / Web
- Nom 3 – Mécanique
