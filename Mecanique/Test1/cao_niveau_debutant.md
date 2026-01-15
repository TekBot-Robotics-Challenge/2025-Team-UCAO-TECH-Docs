# Test 1 – CAO Niveau Débutant (SolidWorks)

---

## Objectif

Ce test évalue nos compétences de base en **Conception Assistée par Ordinateur (CAO)** à travers l’usage de SolidWorks. Il s’agit de créer, à partir de croquis cotés, un ensemble de pièces 3D fonctionnelles, respectant les contraintes de matériau, de masse et de géométrie, puis de réaliser un **assemblage mécanique fonctionnel** avec calcul du centre de gravité.

---

## Pièces modélisées

Nous avons conçu quatre pièces individuelles à partir de croquis 2D, en utilisant les outils de base du logiciel.

### Méthodologie utilisée

- **Croquis 2D** : Rectangles, cercles, polygones, lignes construites.
- **Fonctions 3D** : 
  - Bossage/base extrudée
  - Enlèvement de matière
  - Congés (rayons)
  - Symétrie
- **Contraintes de croquis** : Horizontale, verticale, tangente, coïncidente, symétrie.
- **Système d’unité** : MMGS (mm, gramme, seconde)
- **Décimales** : 2 chiffres après la virgule
- **Trous** : Tous débouchants sauf mention contraire

### Détails des pièces

| Pièce   | Matériau                 | Densité (g/mm³) | Masse obtenue | 
|---------|--------------------------|------------------|----------------|
| Pièce 1 | Acier AISI 1020          | 0.0079           | 2850.16 g            |
| Pièce 2 | Aluminium 1060           | 0.0027           |  279.77 g           |
| Pièce 3 | Acier AISI 1020          | 0.0079           |  1633.25  g            | 
| Pièce 4 | Aluminium 1060           | 0.0027           |  297.29 g            | 

---

## Assemblage de la pince mécanique

L’assemblage de la pince mécanique a été réalisé sous *SolidWorks* à partir des composants fournis dans le fichier .zip. L’objectif était d’assembler correctement toutes les pièces en respectant les degrés de liberté nécessaires au fonctionnement de la pince, notamment son ouverture et sa fermeture via l’action du vérin.

---

### Pièces utilisées

- *Corps de vérin*
- *Tige de vérin*
- *Embout de vérin*
- *Biellettes (gauche et droite)*
- *Axes de biellettes*
- *Porte-mâchoires (gauche et droite)*
- *Mâchoires (gauche et droite)*
- *Circlips* (éléments de verrouillage)
- *Vis Chc M5x25*
- *Axe porte mârchoire*

---

### Étapes principales de l’assemblage

1. *Fixation de la base*  
   Le sous-ensemble contenant le vérin (corps + tige + embout) a été inséré et *fixé* en tant que référence (composant immobile).

2. *Assemblage des biellettes*  
   Les deux biellettes ont été insérées et contraintes avec :
   - Concentrique : pour aligner les axes de rotation avec les trous du vérin
   - Symétrie : pour assurer un mouvement identique et opposé des deux côtés via le *plan dessus*

3. *Ajout des portes-mâchoires et mâchoires*  
   Chaque porte-mâchoire a été assemblée avec sa biellette correspondante :
   - Concentrique : entre le trou du porte-mâchoire et la biellette
   - Coïncidence : pour fixer la position latérale  
   Les mâchoires ont été fixées sur les portes-mâchoires avec les mêmes types de contraintes.

4. *Insertion des axes de biellettes*  
   Les axes ont été utilisés à la place de vis, avec les contraintes :
   - Concentrique : pour l’axe et les trous traversés
   - Coïncidence : entre la tête de l’axe et la surface de contact

5. *Placement des circlips*  
   Les circlips ont été insérés pour verrouiller les axes mécaniquement (sans ajouter de surcontrainte inutile).

---

### Contraintes utilisées

| Type de contrainte | Utilisation                          |
|--------------------|---------------------------------------|
| Concentrique     | Alignement d’axes (trous et axes)     |
| Coïncidence      | Contact de faces planes               |
| Symétrie         | Synchronisation des mouvements         |

---

## Analyse du centre de masse

L’analyse du centre de masse permet de mieux comprendre l’équilibre de la pince mécanique dans différentes positions de fonctionnement. Elle a été effectuée depuis SolidWorks après la finalisation de l’assemblage.

---

### a) Position minimale de la tige de vérin

Dans cette position, la tige du vérin est *entièrement rentrée* dans le corps, ce qui correspond à l’état *pince fermée*.

*Étapes :*
1. Fixer la *tige du vérin* dans sa position *minimale* à l’aide d’une contrainte de distance ou de coïncidence.
2. Aller dans le menu Outils > Propriétés de masse.
3. Noter les coordonnées du *centre de masse (X, Y, Z)*.

*Coordonnées du centre de masse (en mm)* :
  ## X = -29.15
  ## Y = 0.16
  ## Z = 19.93

### b) Position maximale de la tige de vérin

La tige est *complètement sortie, ce qui correspond à l’état **pince ouverte*.

*Étapes :*
1. Déplacer la tige du vérin jusqu’à sa *position maximale*.
2. Appliquer la nouvelle *contrainte de position* (sans surcontraindre).
3. Aller de nouveau dans Outils > Propriétés de masse.
4. Noter les nouvelles coordonnées.

* Coordonnées du centre de masse (en mm)* :

 ## X = -25.78
 ## Y = 0.06
 ## Z = 19.93

---
### Problèmes rencontrés et solutions
Pendant l’assemblage de la pince mécanique, plusieurs problèmes techniques ont été rencontrés. Voici les principaux avec les solutions apportées :

| Problème                                                                 | Cause probable                                                                 | Solution apportée                                                                 |
|--------------------------------------------------------------------------|--------------------------------------------------------------------------------|-----------------------------------------------------------------------------------|
| *Surcontrainte* de certaines pièces                                 | Application excessive ou contradictoire de contraintes                        | Suppression des contraintes redondantes et vérification du degré de liberté     |
| *Erreur lors de l’application de contraintes de symétrie*           | Sélection incorrecte des faces ou mauvais plan de référence                   | Réapplication en sélectionnant correctement les deux faces et le *plan dessus* |
| *Mouvement bloqué de la pince*                                      | Trop de pièces fixées ou contraintes figées                                   | Reprise des contraintes essentielles uniquement (coïncidence et concentrique)    |
| *Circlips empêchant le mouvement*                                   | Circlips appliqués avec trop de contraintes (coïncidence et concentrique)     | N’ajouter qu’une seule contrainte (ex. concentrique) pour éviter le blocage      |
| *Difficulté à fixer le bon composant de base*                       | Mauvaise pièce fixée au début                                                 | Fixation du sous-assemblage vérin (corps + tige + embout) comme base             |
| *Les deux biellettes bougeaient indépendamment*                     | Contraintes insuffisantes ou symétrie absente                                 | Ajout de la contrainte symétrie entre les deux faces via le *plan dessus*    |
| *Déplacement incorrect de la tige de vérin*                         | Contraintes contradictoires ou manquantes                                     | Réglage de la distance entre la tige et le corps du vérin avec précision         |
| *Centre de masse incohérent*                                        | Mauvaise configuration de la position du vérin ou assemblage incomplet        | Vérification et verrouillage de la position du vérin avant calcul                |
---

## Ressources graphiques & fichiers SolidWorks

Les croquis techniques 2D et les modèles 3D réalisés dans SolidWorks sont disponibles pour consultation et vérification.

## Pièce 1 : ![Pièce 1 en 2D](https://github.com/ucaotech-trc/TRC25-UCAOTECH/blob/main/Mecanique/Test1/Images/Pi%C3%A8ce1_2D.PNG),  ![Pièce en 3D](https://github.com/ucaotech-trc/TRC25-UCAOTECH/blob/main/Mecanique/Test1/Images/Pi%C3%A8ce1_3D.PNG)
## Pièce 2 : ![Pièce 2 en 2D](https://github.com/ucaotech-trc/TRC25-UCAOTECH/blob/main/Mecanique/Test1/Images/Pi%C3%A8ce2_2D3.PNG)),  ![Pièce 2 en 3D](https://github.com/ucaotech-trc/TRC25-UCAOTECH/blob/main/Mecanique/Test1/Images/Pi%C3%A8ce2_3D.PNG),
## Pièce 3 : ![Pièce 3 en 2D](https://github.com/ucaotech-trc/TRC25-UCAOTECH/blob/main/Mecanique/Test1/Images/Pi%C3%A8ce3_2D1.PNG),  ![Pièce 3 en 3D](https://github.com/ucaotech-trc/TRC25-UCAOTECH/blob/main/Mecanique/Test1/Images/Pi%C3%A8ce3_3D.PNG),
## Pièce 4 : ![Pièce 4 en 2D](https://github.com/ucaotech-trc/TRC25-UCAOTECH/blob/main/Mecanique/Test1/Images/Pi%C3%A8ce4_2D2.PNG),  ![Pièce 4 en 3D](https://github.com/ucaotech-trc/TRC25-UCAOTECH/blob/main/Mecanique/Test1/Images/Pi%C3%A8ce44_3D.PNG),

## Assemblage : ![Assemblage](https://github.com/ucaotech-trc/TRC25-UCAOTECH/blob/main/Mecanique/Test1/Images/Assemblage.PNG)


Fichiers sources SolidWorks 2025 :
  - Pièces individuelles
     [Pièce 1](https://github.com/ucaotech-trc/TRC25-UCAOTECH/blob/main/Mecanique/Test1/SolidWorks/Pi%C3%A8ce_1.SLDPRT),
    [Pièce 2](https://github.com/ucaotech-trc/TRC25-UCAOTECH/blob/main/Mecanique/Test1/SolidWorks/Pi%C3%A8ce2.SLDPRT),
    [Pièce 3](https://github.com/ucaotech-trc/TRC25-UCAOTECH/blob/main/Mecanique/Test1/SolidWorks/Pi%C3%A8ce3.SLDPRT),
    [Pièce 4](https://github.com/ucaotech-trc/TRC25-UCAOTECH/blob/main/Mecanique/Test1/SolidWorks/Pi%C3%A8ce4.SLDPRT),
  - Assemblage complet (`*.sldasm`)
    [Assamblage](https://github.com/ucaotech-trc/TRC25-UCAOTECH/blob/main/Mecanique/Test1/SolidWorks/assemblage%20pince.SLDASM),


> Ces éléments visuels facilitent la lecture technique du projet et servent de preuve de modélisation dans le cadre du TRC2K25.
---

## Conclusion

Ce test a permis de valider notre capacité à :
- Modéliser des pièces mécaniques précises
- Appliquer des matériaux et contraintes fonctionnelles
- Réaliser un assemblage réaliste sous contraintes
- Évaluer des propriétés comme la masse et le centre de gravité

Ce projet constitue une base solide pour des conceptions mécaniques plus complexes dans le cadre du TRC2K25.

---
