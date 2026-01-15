# Test 2 : CAO SolidWorks – Niveau Intermédiaire

Conception mécanique avancée et modélisation paramétrique sous SolidWorks dans le cadre du **Tekbot Robotics Challenge 2025**.

---

## 🔹 Introduction

Ce test de niveau intermédiaire en CAO sous **SOLIDWORKS**, réalisé dans le cadre du Tekbot Robotics Challenge 2025, nous a permis de mettre en pratique plusieurs compétences clés :

- Création de pièces paramétriques et adaptables  
- Modification de géométries existantes à l’aide de techniques avancées  
- Ajout de fonctions 3D telles que des poches  
- Réalisation d’un assemblage complet avec contrôle de la masse et du centre de gravité  

Le test est divisé en quatre phases : trois étapes de modélisation de pièces, suivies d’un exercice d’assemblage final.

Toute la modélisation est effectuée dans l’environnement **MMGS** (millimètre, gramme, seconde) avec une précision de deux décimales. Le matériau utilisé est l’**acier AISI 1020**, de densité 0,0079 g/mm³.

---

## 🔧 Partie I – Conception d’une pièce paramétrique

### a) Paramètres : A = 81,00 ; B = 57,00 ; C = 43,00

- **Fichier :** Part1(a).SLDPRT  
- **Masse obtenue :** 977,95 g  

**🖼️ Visualisation de la pièce**

![Partie 1(a)](Images/partie1(a).png)

### b) Paramètres : A = 84,00 ; B = 59,00 ; C = 45,00

- **Fichier :** Part1(b).SLDPRT  
- **Masse obtenue :** 1068,75 g  

**🖼️ Visualisation de la pièce**

![Partie 1(b)](Images/partie1(b).png)

### Fonctions utilisées

- **2D (Esquisse) :** ligne, arc, cercle, cotation intelligente, relations géométriques  
- **3D (Fonctions) :** bossage/base par extrusion, enlèvement de matière par extrusion, congé, assistant de perçage à partir d’esquisse  

---

## ✂️ Partie II – Modification de la pièce

- **Paramètres mis à jour :** A = 86,00 ; B = 58,00 ; C = 44,00  
- **Modification directe des cotes** dans l’arbre de création  
- **Ajout d’un enlèvement de matière par extrusion**  
- **Fichier :** Partie 2.SLDPRT  
- **Masse obtenue :** 628,18 g  

**🖼️ Visualisation de la pièce**

![Partie 2](Images/partie\ 2.png)

---

## 🧩 Partie III – Ajout d’une poche

- **Ajout d’une poche latérale** afin de rendre la pièce asymétrique  
- **Création d’une esquisse rectangulaire** sur une face latérale puis enlèvement de matière par extrusion  
- **Fichier :** Partie 3.SLDPRT  
- **Masse obtenue :** 432,58 g  

**🖼️ Visualisation de la pièce**

![Partie 3](Images/partie\ 3.png)

---

## 🛠️ Assemblage – Maillons de chaîne

- Téléchargement et extraction du fichier ZIP contenant les pièces  
- Importation des pièces dans SOLIDWORKS  
- Application des contraintes nécessaires : concentricité, coïncidence et alignement sur l’origine  

### Cas a)

- **Paramètres :** A = 25° ; B = 125° ; C = 130°  
- **Fichier :** Assem3.SLDASM question (a).SLDASM  
- **Centre de gravité (en mm) :**
  - X = 348,66  
  - Y = -88,48  
  - Z = -91,40  

**🖼️ Visualisation de l’assemblage**

![Assemblage A](Images/assemblage\ capture\ .png)

### Cas b)

- **Paramètres :** A = 30° ; B = 115° ; C = 135°  
- **Fichier :** Assem3.SLDASM question (b).SLDASM  
- **Centre de gravité (en mm) :**
  - X = 327,67  
  - Y = -98,39  
  - Z = -102,91  

**🖼️ Visualisation de l’assemblage**

![Assemblage B](Images/assemblage\ capture\ b\ .png)

---

## 📥 Téléchargement des fichiers source

Tous les fichiers SOLIDWORKS de ce projet sont regroupés dans une archive ZIP prête à être téléchargée.

### Archive complète

Contient toutes les pièces et tous les assemblages.

[📦 Télécharger les fichiers SOLIDWORKS](SolidWorks/test2.zip)

### 📁 Contenu de l’archive

| | |
|---|---|
| • Part1(a).SLDPRT | • Partie3.SLDPRT |
| • Part1(b).SLDPRT | • Assem3(a).SLDASM |
| • Partie2.SLDPRT | • Assem3(b).SLDASM |

---

## 🏆 Défi optionnel

Nous présentons ici la modélisation complète du défi optionnel.

Pour ce défi, la pièce a été modélisée en utilisant des fonctions de base ainsi que des fonctions avancées de SolidWorks telles que bossage, nervure, enlèvement de matière par extrusion, etc., tout en respectant le système MMGS et le matériau spécifié (acier AISI 1020).

### Vue 3D de la pièce

**🖼️ Vue 3D de la pièce du défi**

![Pièce du défi](Images/pièce.jpg)

---

## ✅ Conclusion

- Maîtrise de la modélisation paramétrique  
- Capacité à modifier et enrichir des fonctions 3D  
- Gestion précise des relations d’assemblage  
- Contrôle rigoureux de la masse et du centre de gravité  

Toutes les étapes ont été soigneusement documentées et sauvegardées dans des fichiers distincts (.SLDPRT et .SLDASM).

---
