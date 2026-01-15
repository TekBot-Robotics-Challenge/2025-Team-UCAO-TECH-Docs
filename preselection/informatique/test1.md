# Test 1 – Création d'une classe pour un robot

Ce test porte sur la conception, l'implémentation et la documentation d'une architecture orientée objet autour d'une classe **Robot** principale, socle de l'ensemble des développements robotiques du projet TEKBOT.

## 1. Contexte {#contexte-concours}

La robotique occupe aujourd'hui une place centrale dans l'innovation technologique, combinant informatique, électronique et mécanique pour concevoir des systèmes intelligents capables d'interagir avec leur environnement. Ce projet s'inscrit dans le cadre du Tekbot Robotics Challenge 2025 et constitue l'épreuve d'introduction à la partie informatique du concours.

Il s'agit de concevoir et d'implémenter une architecture orientée objet autour d'une classe **Robot** principale, qui servira de base à l'ensemble des développements robotiques à venir. La démarche vise à initier les étudiants à la modélisation logicielle, à la structuration de code et à la réflexion sur l'architecture logicielle dans un contexte robotique.

L'accent est mis sur la compréhension des concepts fondamentaux de la programmation orientée objet et leur application concrète dans un projet technique.

## 2. Objectifs {#objectifs}

Les objectifs sont :

- Concevoir une classe **Robot** respectant les principes de la programmation orientée objet : encapsulation, héritage, polymorphisme
- Implémenter au moins deux sous-classes spécialisées dérivées de la classe Robot
- Redéfinir la méthode `move()` dans les sous-classes pour illustrer le polymorphisme
- Assurer une encapsulation correcte des attributs (attributs privés, getters/setters)
- Fournir une documentation UML claire et conforme

## 3. Structure du projet {#structure-projet}

Le projet TEKBOT est organisé selon une architecture modulaire fidèle à l'arborescence réelle du dossier :

```
tekbot_classes/
├── __init__.py
├── action/
│   ├── __init__.py
│   ├── actionneur.py
│   ├── action_system.py
│   ├── bras_robotique.py
│   └── moteur.py
├── core/
│   ├── __init__.py
│   ├── position.py
│   ├── robot.py
│   └── robot_mobile.py
├── gestion_dechets/
│   ├── __init__.py
│   ├── dechet.py
│   └── gestionnaire_stockage.py
├── intelligence/
│   ├── __init__.py
│   ├── gestionnaire_energie.py
│   ├── ia.py
│   ├── intelligence_system.py
│   └── systeme_navigation.py
├── perception/
│   ├── __init__.py
│   ├── camera.py
│   ├── capteur.py
│   ├── gyroscope.py
│   ├── perception_system.py
│   └── temperature.py
└── ui/
    ├── __init__.py
    └── ihm.py
```

## 4. Programmation Orientée Objet - Implémentation Complète {#poo-principes}

Le projet TEKBOT illustre les grands principes de la POO à travers une architecture modulaire et réaliste. Voici une explication pédagogique de chaque concept, accompagnée d'exemples concrets issus du code du projet.

### 4.0 LE CONSTRUCTEUR – Initialisation des Objets

**Définition détaillée :** Le constructeur est une méthode spéciale d'une classe (en Python, `__init__`) qui est appelée automatiquement lors de la création d'un nouvel objet. Il permet d'initialiser les attributs de l'objet avec des valeurs de départ, garantissant que chaque instance commence dans un état cohérent.

**Exemple dans le projet :**

```python
class Robot:
    def __init__(self, nom: str, energie: float = 100.0):
        self._nom = nom
        self._energie = energie
        self._etat = "prêt"
```

Le constructeur `__init__` initialise ici le nom, l'énergie et l'état du robot dès sa création.

### 4.1 ENCAPSULATION – Protection et Contrôle

**Définition détaillée :** L'encapsulation est le principe qui consiste à regrouper les données (attributs) et les méthodes qui manipulent ces données au sein d'une même entité (la classe). Elle protège l'état interne de l'objet en rendant certains attributs privés (préfixe `_` ou `__`), accessibles uniquement via des méthodes publiques appelées accesseurs (getters) et mutateurs (setters). Cela permet de contrôler la modification des données et d'éviter les incohérences.

**Exemple dans le projet :**

```python
class Capteur(ABC):
    def __init__(self, id_capteur: str, type_capteur: str):
        self._id = id_capteur.strip()      # Attribut privé
        self._type = type_capteur.strip()  # Attribut privé
        self._valeur = 0.0                 # Attribut privé

    def get_valeur(self) -> float:
        return self._valeur

    def set_valeur(self, v: float):
        if v >= 0:
            self._valeur = v
        else:
            raise ValueError("Valeur invalide")
```

Ici, les attributs sont protégés et l'accès se fait via des méthodes dédiées, garantissant la cohérence des valeurs.

### 4.2 HÉRITAGE – Réutilisation et Spécialisation

**Définition détaillée :** L'héritage permet de créer une nouvelle classe (dite « fille » ou « dérivée ») à partir d'une classe existante (dite « mère » ou « de base »). La classe fille hérite des attributs et méthodes de la classe mère, ce qui favorise la réutilisation du code et la spécialisation. Elle peut aussi redéfinir ou étendre certains comportements.

**Exemple dans le projet :**

```python
class Robot(ABC):
    # Classe abstraite de base

class RobotMobile(Robot):
    def __init__(self, nom: str, vitesse: float):
        super().__init__(nom)  # Appel du constructeur parent
        self._vitesse_max = float(vitesse)
```

La classe `RobotMobile` hérite de `Robot` et ajoute des fonctionnalités spécifiques liées à la mobilité.

### 4.3 POLYMORPHISME – Flexibilité et Extensibilité

**Définition détaillée :** Le polymorphisme permet d'utiliser la même interface (méthode ou attribut) pour des objets de types différents. Chaque sous-classe peut redéfinir la méthode héritée pour adapter son comportement. Ainsi, le même appel de méthode peut produire des effets différents selon l'objet ciblé.

**Exemple dans le projet :**

```python
class Capteur(ABC):
    @abstractmethod
    def lire_valeur(self):
        pass

class Camera(Capteur):
    def lire_valeur(self):
        # Spécifique à la caméra
        pass

class Gyroscope(Capteur):
    def lire_valeur(self):
        # Spécifique au gyroscope
        pass

# Utilisation polymorphique
capteurs = [Camera(...), Gyroscope(...)]
for capteur in capteurs:
    capteur.lire_valeur()  # Appelle la méthode adaptée à chaque type
```

La même méthode (`lire_valeur`) est appelée sur chaque objet, mais le comportement dépend de la sous-classe concrète.

### 4.4 ABSTRACTION – Simplification et Modularité

**Définition détaillée :** L'abstraction consiste à définir des classes ou méthodes sans implémentation concrète (classes ou méthodes abstraites). Elle impose un contrat aux sous-classes, qui devront fournir leur propre implémentation. Cela permet de structurer le code et de clarifier les responsabilités de chaque classe.

**Exemple dans le projet :**

```python
from abc import ABC, abstractmethod

class Robot(ABC):
    @abstractmethod
    def move(self):
        pass  # Doit être redéfinie dans les sous-classes
```

La classe `Robot` impose la présence de la méthode `move()` dans ses sous-classes, sans en donner le détail.

### 4.5 COMPOSITION & AGRÉGATION – Construction d'objets complexes

**Définition détaillée :** La composition et l'agrégation sont des relations qui permettent de construire des objets complexes à partir d'autres objets. La composition implique que l'objet composé possède et gère le cycle de vie de ses composants ; l'agrégation indique une relation plus souple, où les objets peuvent exister indépendamment.

**Exemple dans le projet :**

```python
class ActionSystem:
    def __init__(self):
        self._actionneurs: Dict[str, Actionneur] = {}
        self._moteurs: List[Moteur] = []
        self._bras_robotiques: List[BrasRobotique] = []
```

La classe `ActionSystem` est composée d'objets `Moteur`, `BrasRobotique` et `Actionneur` : elle orchestre leur fonctionnement.

## 5. Technologies et Outils Utilisés {#technologies}

### 5.1 Langages et Outils de Développement

- **Python 3.11+** — Langage principal pour l'architecture orientée objet et la logique métier
- **Pygame 2.6+** — Simulation graphique interactive et visualisation robotique
- **VS Code** — Environnement de développement moderne et modulaire

### 5.2 Architecture, Modélisation et Organisation

- **PlantUML** — Génération de diagrammes UML (classes, séquence, activités, cas d'utilisation)
- **Design Patterns** — Singleton, Observer, Strategy, State pour la robustesse logicielle
- **Architecture modulaire** — Séparation claire des responsabilités en packages Python

## 6. Collection Complète des Diagrammes UML {#diagrammes}

La modélisation UML du projet TEKBOT s'appuie sur plusieurs types de diagrammes, chacun ayant un objectif précis dans la compréhension et la documentation du système.

### 6.1 Diagramme de Classes Principal (avec packages)

**Définition :** Le diagramme de classes UML représente la structure statique du système : il montre les classes, leurs attributs, méthodes, ainsi que les relations (héritage, composition, agrégation, associations) entre elles.

**Objectif :** Offrir une vue d'ensemble de l'architecture logicielle, faciliter la compréhension des interactions entre modules et guider l'implémentation du code.

[![Diagramme de Classes TEKBOT](/images/test1/diagramme_simple.svg)](/images/test1/diagramme_simple.svg)

*<small>💡 Cliquez sur l'image pour zoomer • Utilisez le bouton retour ou fermez l'onglet pour revenir</small>*

**Points clés illustrés :**
- **Héritage** : Robot → RobotMobile, BrasRobotique
- **Composition** : Robot contient PerceptionSystem, ActionSystem
- **Agrégation** : Robot utilise Navigation, GestionnaireStockage
- **Polymorphisme** : Méthodes virtuelles redéfinies
- **Encapsulation** : Attributs privés + méthodes publiques

### 6.2 Diagramme de Classes (sans packages)

**Définition :** Ce diagramme de classes simplifié présente uniquement les classes principales et leurs relations, sans la structure de packages.

**Objectif :** Permettre une compréhension rapide des relations d'héritage, de composition et d'agrégation entre les classes majeures du projet.

[![Diagramme de Classes simplifié](/images/test1/diagramme_simple_sans_package.svg)](/images/test1/diagramme_simple_sans_package.svg)

*<small>💡 Cliquez sur l'image pour zoomer • Utilisez le bouton retour ou fermez l'onglet pour revenir</small>*

### 6.3 Diagramme de Séquence - Interaction Dynamique

**Définition :** Le diagramme de séquence UML décrit l'enchaînement temporel des messages échangés entre objets lors d'un scénario précis.

**Objectif :** Illustrer le déroulement dynamique d'un cas d'utilisation, clarifier la logique d'exécution et détecter d'éventuels problèmes de synchronisation ou de conception.

[![Diagramme de Séquence](/images/test1/diagramme_sequence.svg)](/images/test1/diagramme_sequence.svg)

*<small>💡 Cliquez sur l'image pour zoomer • Utilisez le bouton retour ou fermez l'onglet pour revenir</small>*

**Séquence illustrée :**

Le diagramme présente l'enchaînement complet d'une mission de collecte : **initialisation** du robot et de ses systèmes, **perception** de l'environnement via les capteurs, **analyse IA** et prise de décision, **navigation** vers le déchet détecté, **collecte** via le bras robotique, puis **stockage** et tri automatique.

### 6.4 Diagramme d'Activités - Flux de Traitement

**Définition :** Le diagramme d'activités UML modélise les flux de contrôle et de données d'un processus métier ou d'un algorithme.

**Objectif :** Comprendre et optimiser les processus, identifier les points de décision et les alternatives, et documenter les scénarios complexes.

[![Diagramme d'Activités](/images/test1/diagramme_activites.svg)](/images/test1/diagramme_activites.svg)

*<small>💡 Cliquez sur l'image pour zoomer • Utilisez le bouton retour ou fermez l'onglet pour revenir</small>*

Ce diagramme illustre le déroulement complet d'une mission TEKBOT : démarrage, exploration, gestion de l'énergie, collecte priorisée et conditions d'arrêt. Les branches conditionnelles et boucles de traitement permettent d'anticiper les cas particuliers et d'optimiser les processus avant implémentation.

### 6.5 Diagramme de Cas d'Utilisation - Interactions Utilisateur

**Définition :** Le diagramme de cas d'utilisation UML présente les différents acteurs (utilisateurs ou systèmes externes) et les fonctionnalités principales auxquelles ils ont accès.

**Objectif :** Identifier les besoins fonctionnels, clarifier le périmètre du système et faciliter la communication entre les parties prenantes.

[![Diagramme de Cas d'Utilisation](/images/test1/diagramme_cas_utilisation.svg)](/images/test1/diagramme_cas_utilisation.svg)

*<small>💡 Cliquez sur l'image pour zoomer • Utilisez le bouton retour ou fermez l'onglet pour revenir</small>*

**Acteurs et cas d'usage :**
- **Opérateur** : Lancer mission, surveiller état, arrêter robot
- **Technicien** : Configurer paramètres, maintenance, diagnostics
- **Superviseur** : Analyser performances, générer rapports
- **Robot (Acteur système)** : Exécution autonome des tâches

### 6.6 Diagramme de Déploiement - Architecture Physique

**Définition :** Le diagramme de déploiement UML décrit l'architecture physique du système, montrant comment les composants logiciels sont déployés sur l'infrastructure matérielle.

**Objectif :** Visualiser la distribution géographique des composants, identifier les dépendances matérielles et faciliter la planification du déploiement.

[![Diagramme de Déploiement](/images/test1/deploiment.png)](/images/test1/deploiment.png)

*<small>💡 Cliquez sur l'image pour zoomer • Utilisez le bouton retour ou fermez l'onglet pour revenir</small>*

**Éléments représentés :**
- **Nœuds physiques :** Serveurs, ordinateurs, appareils mobiles, capteurs
- **Composants déployés :** Applications, bases de données, services web
- **Connexions :** Réseaux, protocoles de communication, dépendances

**Architecture TEKBOT :**
- **Nœud central :** Raspberry Pi avec système de contrôle principal
- **Nœuds périphériques :** Capteurs, actionneurs, caméras
- **Communication :** Bus I2C, SPI, interfaces série
- **Alimentation :** Gestion centralisée de l'énergie

## 7. Justification détaillée et rôle stratégique des 19 classes du projet {#architecture}

La conception du projet TEKBOT repose sur une architecture orientée objet rigoureuse, où chaque classe joue un rôle précis et indispensable dans la robustesse, la modularité et l'intelligence du système.

<style scoped>
.class-cards {
  display: grid;
  grid-template-columns: repeat(auto-fit, minmax(280px, 1fr));
  gap: 1.5rem;
  margin: 2rem 0;
}
.class-card {
  background: var(--vp-c-bg-soft);
  border: 2px solid var(--vp-c-brand-1);
  border-radius: 8px;
  padding: 1.2rem;
  transition: all 0.3s ease;
}
.class-card:hover {
  transform: translateY(-2px);
  box-shadow: 0 4px 12px rgba(16, 185, 129, 0.2);
}
.class-card h5 {
  color: var(--vp-c-brand-1);
  margin: 0 0 0.8rem 0;
  font-size: 1.1em;
  font-weight: 600;
}
.class-card p {
  margin: 0;
  line-height: 1.6;
  color: var(--vp-c-text-2);
}
</style>

<div class="class-cards">
  <div class="class-card">
    <h5>Robot (Abstraite)</h5>
    <p>Sert de socle à toute l'architecture : elle définit les attributs et méthodes essentiels (identité, énergie, état, interface de mouvement) et impose un contrat commun à toutes les variantes de robots. Elle garantit la cohérence, la sécurité et la possibilité d'extension par héritage, tout en favorisant le polymorphisme et la factorisation du code.</p>
  </div>

  <div class="class-card">
    <h5>RobotMobile</h5>
    <p>Spécialise la classe Robot pour la mobilité : elle gère la navigation autonome, la planification de chemin, l'orientation et la gestion dynamique de la vitesse. Elle illustre l'héritage, la redéfinition de méthodes et permet d'intégrer des algorithmes avancés de déplacement (A*, évitement d'obstacles, etc.).</p>
  </div>

  <div class="class-card">
    <h5>BrasRobotique</h5>
    <p>Représente le sous-système de manipulation : elle encapsule la logique de préhension, de collecte et de tri des objets. Sa séparation permet d'ajouter ou de modifier les capacités de manipulation sans impacter le cœur du robot, illustrant la composition et l'extensibilité matérielle.</p>
  </div>

  <div class="class-card">
    <h5>Actionneur</h5>
    <p>Abstraction de tout dispositif effectuant une action physique (moteur, pince, bras, etc.). Elle favorise la réutilisation, la maintenance et l'ajout de nouveaux actionneurs, tout en garantissant une interface commune pour le contrôle des éléments matériels.</p>
  </div>

  <div class="class-card">
    <h5>Moteur</h5>
    <p>Spécialise l'actionneur pour la propulsion : elle gère la vitesse, le sens de rotation et la puissance. Elle permet d'isoler la logique de déplacement mécanique et d'optimiser la gestion énergétique du robot.</p>
  </div>

  <div class="class-card">
    <h5>ActionSystem</h5>
    <p>Centralise et orchestre tous les actionneurs : elle applique le pattern façade pour simplifier l'interface de contrôle, permet de coordonner plusieurs dispositifs physiques et d'assurer la cohérence des actions du robot.</p>
  </div>

  <div class="class-card">
    <h5>PerceptionSystem</h5>
    <p>Système central de gestion des capteurs : il réalise la fusion des données, la détection d'événements et l'analyse de l'environnement. Il permet d'ajouter facilement de nouveaux capteurs et d'optimiser la perception globale du robot.</p>
  </div>

  <div class="class-card">
    <h5>Camera</h5>
    <p>Capteur spécialisé pour la vision : elle gère la capture d'images, la détection d'objets et l'analyse visuelle. Elle est essentielle pour la navigation intelligente et la reconnaissance de l'environnement.</p>
  </div>

  <div class="class-card">
    <h5>Gyroscope</h5>
    <p>Capteur d'orientation : il mesure les rotations, stabilise la navigation et permet au robot de s'adapter aux changements de direction ou de terrain.</p>
  </div>

  <div class="class-card">
    <h5>Temperature</h5>
    <p>Capteur thermique : il surveille la température de l'environnement ou des composants internes, permettant la détection de surchauffe ou d'anomalies, et contribue à la sécurité du robot.</p>
  </div>

  <div class="class-card">
    <h5>Capteur</h5>
    <p>Classe abstraite pour tous les capteurs : elle impose une interface commune, garantit la cohérence des lectures et facilite l'ajout de nouveaux types de capteurs sans modifier le reste du système.</p>
  </div>

  <div class="class-card">
    <h5>IntelligenceSystem</h5>
    <p>Cerveau décisionnel du robot : il analyse les données, planifie les missions, applique des stratégies d'IA et prend des décisions en temps réel pour optimiser le comportement du robot.</p>
  </div>

  <div class="class-card">
    <h5>IA</h5>
    <p>Module d'intelligence artificielle : il permet d'expérimenter différentes approches (systèmes experts, apprentissage, adaptation) et d'implémenter des comportements évolués pour le robot.</p>
  </div>

  <div class="class-card">
    <h5>SystemeNavigation</h5>
    <p>Système dédié à la planification de chemin, à l'évitement d'obstacles et à la gestion des déplacements complexes. Il rend la navigation autonome, fiable et optimisée.</p>
  </div>

  <div class="class-card">
    <h5>GestionnaireEnergie</h5>
    <p>Supervise la consommation, la recharge et l'optimisation de l'autonomie énergétique : il permet au robot d'adapter son comportement en fonction de son niveau d'énergie et d'éviter les pannes.</p>
  </div>

  <div class="class-card">
    <h5>Dechet</h5>
    <p>Modélise chaque déchet détecté : elle stocke ses propriétés (type, position, état), permet le tri, la gestion intelligente et la traçabilité des déchets collectés par le robot.</p>
  </div>

  <div class="class-card">
    <h5>GestionnaireStockage</h5>
    <p>Gère le stockage, le tri et la capacité des déchets collectés : elle optimise la logistique embarquée, prévient les débordements et assure la bonne organisation des déchets.</p>
  </div>

  <div class="class-card">
    <h5>IHM</h5>
    <p>Interface Homme-Machine : elle permet l'interaction utilisateur, la visualisation en temps réel et le contrôle du robot, rendant le système accessible et pilotable.</p>
  </div>

  <div class="class-card">
    <h5>Position</h5>
    <p>Représente la position spatiale : elle est utilisée pour la navigation, la détection, la gestion des déplacements et la simulation graphique. Elle constitue la base de toute logique spatiale dans le projet.</p>
  </div>
</div>

## 8. Extraits de code des classes principales {#implementation}

Le code complet de ces classes est disponible dans le dossier `tekbot_classes/` du projet. Voici un aperçu de la classe Robot de base :

```python
class Robot(ABC):
    """
    Classe abstraite Robot - Classe mère pour tous les types de robots.
    
    Énumération intégrée EtatRobot selon le diagramme UML.
    Utilise les principes d'abstraction et de composition.
    """
    class EtatRobot(Enum):
        """
        Énumération des états possibles du robot intégrée dans la classe Robot.
        """
        ARRET = auto()
        ACTIF = auto()
        COLLECTE = auto()
        TRI = auto()
        LIVRAISON = auto()
        MAINTENANCE = auto()
        ECONOMIE_ENERGIE = auto()
        
    def __init__(self, nom: str):
        if not nom or not isinstance(nom, str):
            raise ValueError("Le nom du robot doit être une chaîne non vide")
        self._nom = nom.strip()
        self._etat = Robot.EtatRobot.ARRET
        self._energie = 100.0
        self._mode_manuelle = False
        
    # === MÉTHODES SELON LE DIAGRAMME UML ===
    def demarrer(self) -> None:
        if self._etat == Robot.EtatRobot.ARRET:
            self._etat = Robot.EtatRobot.ACTIF
        else:
            raise RuntimeError(f"Impossible de démarrer le robot - état actuel: {self._etat}")
    
    def arreter(self) -> None:
        self._etat = Robot.EtatRobot.ARRET
    
    @abstractmethod
    def move(self) -> None:
        pass
```

::: tip Code complet
Le code source complet avec tous les getters/setters, la gestion des systèmes et la documentation détaillée est disponible dans le dépôt du projet.
:::

## 9. Simulation visuelle et prise en main {#simulation}

### Objectif pédagogique

La simulation TEKBOT permet d'expérimenter et de visualiser le comportement du robot dans un environnement virtuel interactif. Elle favorise la compréhension concrète des algorithmes de navigation, de collecte et de gestion d'énergie.

### Comment lancer la simulation

1. Assurez-vous d'avoir **Python 3.11+** et **Pygame** installés
2. Ouvrez un terminal dans le dossier du projet
3. Lancez la simulation avec la commande suivante :

   ```bash
   python main_tekbot_simulation.py
   ```

Observez l'évolution de la mission, la collecte des déchets et la gestion de l'énergie en temps réel.

### Vidéos de démonstration

<video controls style="width: 100%; max-width: 600px; border-radius: 8px; background: #000;">
  <source src="/images/test1/Simulation.mp4" type="video/mp4">
  Votre navigateur ne supporte pas les vidéos HTML5.
</video>

## 10. Références et Ressources {#references}

### Documentation Technique

- [Documentation Python 3](https://docs.python.org/3/) - Référence officielle du langage
- [Documentation Pygame](https://www.pygame.org/docs/) - Bibliothèque graphique utilisée
- [PlantUML Guide](https://plantuml.com/) - Outil de génération des diagrammes UML

### Ressources Pédagogiques

- [POO avec Python - OpenClassrooms](https://openclassrooms.com/fr/courses/7150616-apprenez-la-programmation-orientee-objet-avec-python)
- [UML Diagrams Reference](https://www.uml-diagrams.org/) - Guide complet UML
- [Real Python - OOP Guide](https://realpython.com/python3-object-oriented-programming/)
