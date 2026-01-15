# Test 1 – Classe de gestion d’un Robot autonome  
**Tekbot Robotics Challenge 2025 — Informatique**

---

## Objectifs du test

Ce projet vise à démontrer les principes de la programmation orientée objet à travers la conception d’une classe Robot abstraite et de plusieurs sous-classes spécialisées. Il s’inscrit dans le cadre du Tekbot Robotics Challenge 2024. L’objectif est de :

- Modéliser une **classe principale `Robot`** et au moins **deux sous-classes spécialisées**
- Utiliser les concepts fondamentaux de la POO :  
   **Encapsulation**, **Héritage**, **Polymorphisme**, **Abstraction**
- Implémenter et redéfinir une méthode `move()` dans les sous-classes
- Fournir une documentation claire, incluant un **diagramme UML explicatif**

---

## Concepts abordés

- UML et modélisation logicielle
- Héritage et polymorphisme (`virtual`, `override`)
- Encapsulation (attributs privés, getters/setters)
- Composition (capteurs, navigation)


---

## Technologies utilisées

- **Langages** : C++  
- **IDE utilisée** : Code::Blocks 
- **Diagramme UML** : Visual Paradigm  
- **Structure** : Projet modulaire avec séparation en `.h` / `.cpp`
     ## Organisation des fichiers
      Test1/ClasseRobot/
          ├── include/              # Fichiers d’en-tête (.h)
          ├── src/                  # Fichiers source (.cpp)
          ├── diagram/              # Diagrammes UML 
          ├── README.md             # Documentation du projet
          ├── main.cpp              # Programme de test

---

## Architecture des classes

| Classe           | Rôle                                                   | Concepts illustrés             |
|------------------|---------------------------------------------------------|-------------------------------|
| `Robot`          | Classe mère abstraite. Contient les propriétés générales. | Abstraction, Polymorphisme   |
| `RobotMobile`    | Gère les déplacements en translation (roues, direction) | Héritage, Redéfinition        |
| `BrasRobotique`  | Contrôle un bras articulé et sa pince                   | Héritage, Encapsulation       |
| `Capteur`        | Représente un capteur configurable (type, portée, etc.) | Composition                   |
| `Navigation`     | Gère la position et l’orientation spatiale du robot     | Agrégation                    |

---

## Diagramme UML

![Diagramme UML](https://github.com/TekBot-Robotics-Challenge/Team_UCAO-TECH/blob/main/Informatique/Test1/ClasseRobot/diagram/diagram.png),

Ce diagramme présente :
- les relations d’héritage (flèches),
- les attributs privés `-` et les méthodes publiques `+`,
- la composition (`Robot` possède une liste de `Capteur`),
- l’agrégation avec la classe `Navigation`.

---

---
  ## Concepts appliqués
**Encapsulation :** tous les attributs sont private, accessibles via getters/setters.

**Héritage :** RobotMobile et BrasRobotique héritent de la classe Robot.

**Polymorphisme :** la méthode move() est redéfinie dans chaque sous-classe.

**Composition :** un Robot contient des objets Navigation et un vecteur de Capteur.

---

##  Références pédagogiques
Documentation C++
OpenClassrooms.com
UML Class Diagram - Guide complet

---
