# Test 3: Test de sortie - Afficheur 7 segments mécanique avec servomoteurs

Afficheur 7 segments mécanique réinventé à l'aide de servomoteurs - Une fusion de la logique numérique et du mouvement mécanique.




## Contexte du projet

Dans un monde dominé par les écrans numériques et les LED, le Tekbot Robotic Challenge 2025 lance un défi audacieux: réinventer l'afficheur 7 segments en lui donnant une âme mécanique.

![Concept initial](../../public/images_electronique/test3/image1.jpg)

**Origine du projet:** TEKBOT ROBOTIC CHALLENGE 2025

---

## Objectifs du projet

### Objectifs principaux

- Concevoir un afficheur 7 segments entièrement mécanique
- Contrôler précisément 7 servomoteurs avec un microcontrôleur
- Implémenter un comptage cyclique 0→9→0

### Objectifs secondaires

- Réduire le nombre de broches en utilisant des circuits intégrés
- Documenter le processus de développement
- Valider la solution par simulation

---

## Partie 1: Implémentation physique

### Composants utilisés

| Composant | Référence | Quantité | Rôle |
|-----------|-----------|----------|------|
| Microcontrôleur | ATmega328P | 1 | Cerveau du système |
| Servomoteurs | SG90 | 7 | Contrôle des segments |
| Régulateur | LM7805 | 1 | Régulation 5V |
| Batterie | Li-ion 7.4V | 1 | Alimentation |
| Condensateurs | 100nF, 1000μF, 10µF | 4 | Filtrage |
| Cristal | 16MHz | 1 | Horloge |

### Schéma électronique

![Schéma électronique complet](Images/circuit.PNG)

**Description:**
- Protection contre la surcharge
- Connexion directe des servos aux broches PWM
- Circuit de réinitialisation avec bouton poussoir

![Schéma physique 1](Images/image2.jpg)

![Schéma physique 2](Images/image3.jpg)

### Alimentation

Le système d'alimentation comprend:

- **Batterie Li-ion 7.4V 2S:** Source d'énergie principale
- **Régulateur LM7805:** Stabilisation à 5V pour les composants
- **Condensateurs de filtrage:** 100nF et 10μF pour lisser l'alimentation

### Réalisation du PCB

![PCB vue avant](Images/pcb_test3_front.PNG)

![PCB vue arrière](Images/pcb_test3_back.PNG)

**Caractéristiques:**
- Conçu avec KiCad
- Double face
- Pistes de 0.6 mm
- Espacement optimisé pour les connecteurs

[📥 Télécharger les fichiers PCB](Kicad/7seg_circuit_electronique.rar)

### Code Arduino

Extrait du code principal utilisant millis() pour un timing non-bloquant:

````cpp
// Initialisation progressive des servos
if (!initTerminee) {
  if (millis() - debutInit >= 100) { // Délai entre les servos
    debutInit = millis();
    servoEnCours++;
    
    if (servoEnCours < 7) {
      segments[servoEnCours].attach(brochesServos[servoEnCours]);
      segments[servoEnCours].write(90);
    } else {
      initTerminee = true;
      afficher(chiffreActuel); // Affichage initial 0
    }
  }
}
````

---

## Partie 2: Innovation théorique

### Concepts clés

- **Contrôle angulaire précis:** Chaque servo doit atteindre un angle spécifique pour afficher correctement chaque segment.
- **Synchronisation des servos:** Les servos doivent être synchronisés pour éviter les erreurs d'affichage.

### Défis théoriques

- Calculer les délais optimaux pour le contrôle des servos.
- Modéliser le comportement dynamique du système pour un contrôle prédictif.

---

## Comparaison et avantages

| Critère | Afficheur 7 segments traditionnel | Afficheur 7 segments avec servomoteurs |
|---------|-----------------------------------|--------------------------------------|
| Flexibilité | Faible | Élevée |
| Complexité de contrôle | Faible | Élevée |
| Coût | Faible | Élevé |
| Maintenance | Simple | Complexe |
| Innovation | Standard | Haute |

---

## Problèmes rencontrés

- **Problème:** Difficulté à synchroniser les servos pour un affichage précis.
  - **Solution:** Ajustement des délais dans le code et utilisation de la fonction millis() pour un timing non-bloquant.

---

## Références techniques

1. [Servomoteurs SG90 - Spécifications](https://www.example.com/sg90-specs)
2. [ATmega328P - Datasheet](https://www.example.com/atmega328p-datasheet)
3. [Régulateur LM7805 - Informations](https://www.example.com/lm7805-info)

---

## Conclusion

Ce projet a permis d'explorer les limites de l'afficheur 7 segments traditionnel en intégrant des éléments mécaniques. Bien que des défis subsistent, notamment en termes de coût et de complexité, les résultats obtenus ouvrent la voie à de nouvelles innovations dans le domaine des afficheurs numériques.

---