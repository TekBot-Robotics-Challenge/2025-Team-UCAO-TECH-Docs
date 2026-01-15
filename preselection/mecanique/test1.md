# Test 1 : CAO SolidWorks – Niveau Débutant

Évaluation des compétences fondamentales en **Conception Assistée par Ordinateur (CAO)** à travers la modélisation de pièces 3D et l’assemblage mécanique sous SolidWorks.

---

## Objectif

Ce test évalue nos compétences fondamentales en **CAO** à l’aide du logiciel SolidWorks. L’objectif est de créer, à partir de croquis cotés, un ensemble de pièces 3D fonctionnelles en respectant les contraintes de matériau, de masse et de géométrie, puis de réaliser un **assemblage mécanique fonctionnel** avec calcul du centre de gravité.

---

## Pièces modélisées

Nous avons conçu quatre pièces individuelles à partir de plans 2D, en utilisant les outils de base du logiciel.

### Méthodologie utilisée

- **Esquisses 2D** : rectangles, cercles, polygones, lignes de construction  
- **Fonctions 3D** :
  - Bossage/Base par extrusion  
  - Enlèvement de matière par extrusion  
  - Congés (rayons)  
  - Symétrie  
- **Contraintes d’esquisse** : horizontale, verticale, tangente, coïncidente, symétrique  
- **Système d’unités** : MMGS (mm, gramme, seconde)  
- **Décimales** : 2 chiffres après la virgule  
- **Perçages** : tous débouchants sauf indication contraire  

### Détails des pièces

| Pièce | Matériau | Densité (g/mm³) | Masse obtenue |
|------|----------|------------------|---------------|
| Pièce 1 | Acier AISI 1020 | 0,0079 | 2850,16 g |
| Pièce 2 | Aluminium 1060 | 0,0027 | 279,77 g |
| Pièce 3 | Acier AISI 1020 | 0,0079 | 1633,25 g |
| Pièce 4 | Aluminium 1060 | 0,0027 | 297,29 g |

---

## Assemblage de la pince mécanique

L’assemblage de la pince mécanique a été réalisé sous **SolidWorks** à partir des composants fournis dans le fichier .zip. L’objectif était d’assembler correctement toutes les pièces tout en respectant les degrés de liberté nécessaires au fonctionnement de la pince, notamment son ouverture et sa fermeture via l’action du vérin.

### Pièces utilisées

- Corps de vérin  
- Tige de vérin  
- Embout de vérin  
- Bielles (gauche et droite)  
- Axes de bielles  
- Supports de mâchoires (gauche et droite)  
- Mâchoires (gauche et droite)  
- Circlips (éléments de verrouillage)  
- Vis CHC M5x25  
- Axe de support de mâchoire  

### Principales étapes d’assemblage

1. **Fixation de la base**  
   - Le sous-ensemble contenant le vérin (corps + tige + embout) a été inséré et **fixé** comme référence (composant immobile).

2. **Assemblage des bielles**  
   - Les deux bielles ont été insérées et contraintes avec :  
     - Contrainte concentrique : alignement des axes de rotation avec les trous du vérin  
     - Contrainte de symétrie : mouvement identique et opposé des deux côtés via le **plan supérieur**

3. **Ajout des supports et des mâchoires**  
   - Chaque support de mâchoire a été assemblé avec sa bielle correspondante :  
     - Concentrique : entre le trou du support et la bielle  
     - Coïncidente : pour fixer la position latérale  
   - Les mâchoires ont été fixées sur les supports avec les mêmes types de contraintes.

4. **Insertion des axes de bielles**  
   - Les axes ont été utilisés à la place de vis, avec les contraintes suivantes :  
     - Concentrique : entre l’axe et les trous traversés  
     - Coïncidente : entre la tête de l’axe et la surface de contact  

5. **Mise en place des circlips**  
   - Les circlips ont été insérés pour bloquer mécaniquement les axes, sans ajouter de surcontraintes inutiles.

### Contraintes utilisées

| Type de contrainte | Utilisation |
|--------------------|-------------|
| Concentrique | Alignement des axes (trous et axes) |
| Coïncidente | Contact entre faces planes |
| Symétrie | Synchronisation des mouvements |

---

## Analyse du centre de gravité

L’analyse du centre de gravité permet de mieux comprendre l’équilibrage de la pince dans différentes positions de fonctionnement. Elle a été réalisée sous SolidWorks après la finalisation de l’assemblage.

### a) Position minimale de la tige du vérin

Dans cette position, la tige du vérin est **totalement rentrée** dans le corps, correspondant à l’état **pince fermée**.

**Coordonnées du centre de gravité (en mm)** :
- X = -29,15  
- Y = 0,16  
- Z = 19,93  

### b) Position maximale de la tige du vérin

La tige est **complètement sortie**, correspondant à l’état **pince ouverte**.

**Coordonnées du centre de gravité (en mm)** :
- X = -25,78  
- Y = 0,06  
- Z = 19,93  

---

## Problèmes rencontrés et solutions

| Problème | Cause probable | Solution appliquée |
|--------|----------------|-------------------|
| **Surcontraintes** de certaines pièces | Contraintes excessives ou contradictoires | Suppression des contraintes redondantes et vérification des degrés de liberté |
| **Erreur lors de l’application de la symétrie** | Mauvaise sélection des faces ou du plan de référence | Réapplication correcte avec sélection des deux faces et du **plan supérieur** |
| **Blocage du mouvement de la pince** | Trop de pièces fixées ou contraintes verrouillées | Application uniquement des contraintes essentielles (coïncidentes et concentriques) |
| **Circlips bloquant le mouvement** | Trop de contraintes appliquées aux circlips | Ajout d’une seule contrainte (ex. concentrique) pour éviter le blocage |

---

## Ressources graphiques et fichiers SolidWorks

### Pièce 1

| Vue 2D | Vue 3D |
|-------|--------|
| ![Pièce 1 2D](Images/Pièce1_2D.PNG) | ![Pièce 1 3D](Images/Pièce1_3D.PNG) |

### Pièce 2

| Vue 2D | Vue 3D |
|-------|--------|
| ![Pièce 2 2D](Images/Pièce2_2D3.PNG) | ![Pièce 2 3D](Images/Pièce2_3D.PNG) |

### Pièce 3

| Vue 2D | Vue 3D |
|-------|--------|
| ![Pièce 3 2D](Images/Pièce3_2D1.PNG) | ![Pièce 3 3D](Images/Pièce3_3D.PNG) |

### Pièce 4

| Vue 2D | Vue 3D |
|-------|--------|
| ![Pièce 4 2D](Images/Pièce4_2D2.PNG) | ![Pièce 4 3D](Images/Pièce44_3D.PNG) |

### Assemblage final

![Assemblage complet](Images/Assemblage.PNG)

### Fichiers source SolidWorks 2025

- [Télécharger les fichiers source](SolidWorks/Test1.rar)

> Ces éléments visuels facilitent la lecture technique du projet et servent de preuve de modélisation dans le cadre du TRC2K25.

---

## Conclusion

Ce test a permis de valider notre capacité à :

- Modéliser des pièces mécaniques précises  
- Appliquer des matériaux et contraintes fonctionnels  
- Réaliser un assemblage réaliste sous contraintes  
- Évaluer des propriétés telles que la masse et le centre de gravité  

Ce projet constitue une base solide pour des conceptions mécaniques plus complexes dans le cadre du TRC2K25.

---
