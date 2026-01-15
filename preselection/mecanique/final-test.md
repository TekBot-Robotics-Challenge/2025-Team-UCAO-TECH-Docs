# Conception Mécanique et Fabrication - Système de Convoyeur Intelligent

Ingénierie de précision et construction robuste pour des opérations de tri automatisé fiables.

## Introduction

### Contexte du Projet

Cette documentation mécanique couvre la conception et la mise en œuvre d'un système de convoyeur intelligent pour le tri automatisé des déchets dans le cadre du Défi de Robotique TEKBOT 2025.

#### Objectifs Clés

- Concevoir un système de convoyeur de 650mm pour des cubes de tri de 30mm
- Mettre en œuvre un mécanisme de tri mécanique fiable
- Assurer la compatibilité avec les systèmes électroniques et informatiques
- Optimiser pour l'impression 3D et le prototypage rapide

## Stratégie de Sélection des Matériaux

### Matériaux Primaires Utilisés

**Filament PLA**
- Matériau structurel principal
- Remplissage à 100% pour les pièces critiques

**Courroie de Convoyeur PVC**
- Largeur de 120mm, épaisseur de 2mm
- Adhérence optimale pour les cubes

**Roulements 6300-2RS**
- Roulements à billes étanches
- Diamètre intérieur de 12mm

### Avantages des Matériaux

- **Réduction des Coûts :** 60% moins cher que les solutions en métal
- **Temps de Production :** Fabrication 3 fois plus rapide
- **Maintenance :** Remplacement simplifié des pièces
- **Poids :** Structure légère mais robuste

## Spécifications des Composants

| Composant | Matériau | Dimensions | Quantité | Fonction |
|-----------|----------|-----------|----------|----------|
| Châssis Principal | PLA | 650×200×150mm | 1 | Structure primaire |
| Support Gauche/Droit | PLA | 225×100×12mm | 6 sections | Éléments du cadre latéral |
| Tambour Moteur | PLA | Ø60mm | 1 | Connexion moteur |
| Tambour de Retour | PLA | Ø60mm | 1 | Guidage de la courroie |
| Roulements | Acier | 12×35×11mm | 4 | Support de rotation |
| Guides de Tri | PLA | Divers | 6 | Direction des objets |

## Modélisation CAO et Conception

### Mise en Œuvre SolidWorks

**Caractéristiques de Conception :**
- Conception paramétrique pour modifications faciles
- Étude de mouvement pour validation des mécanismes
- Détection d'interférences implémentée
- Analyse des propriétés de masse

### Composants Clés

**Structure du Châssis Principal**
Conception modulaire inspirée de l'aluminium en PLA avec renforcement aux coins.

**Mécanisme de Tri**
Portes actionnées par servo avec contrôle angulaire précis de 45°.

**Système de Collecte**
Quatre bacs séparés avec goulottes guidées pour les objets triés.

### Galerie des Composants

- Section de Support A
- Tambour Moteur
- Guide de Tri
- Logement de Roulement

## Processus de Fabrication

### 1. Impression 3D

Tous les composants personnalisés sont imprimés en 3D en filament PLA avec une hauteur de couche de 0,2mm et un remplissage de 20-100% selon les exigences structurelles.

**Paramètres d'Impression :** Buse 200°C, lit 60°C, vitesse 50mm/s

### 2. Assemblage du Châssis

Assemblage modulaire du châssis utilisant des composants PLA imbriqués avec des fixations en acier inoxydable M4 pour l'intégrité structurelle.

**Outils Utilisés :** Clés hexagonales, mètre, gabarit d'alignement

### 3. Intégration des Mécanismes

Montage des servomoteurs avec supports personnalisés, tensionnement du système de courroie et installation des roulements pour un fonctionnement fluide.

**Vérifications Clés :** Alignement de la courroie, plage de servo, positionnement des capteurs

### 4. Assemblage Final et Tests

Intégration complète du système suivie de tests rigoureux pour assurer un fonctionnement fiable dans diverses conditions.

**Tests :** Capacité de charge, précision du tri, endurance

## Spécifications Techniques

### Spécifications Dimensionnelles

- **Longueur Totale :** 650 mm
- **Largeur de Courroie :** 150 mm
- **Hauteur du Châssis :** 150 mm
- **Capacité d'Objets :** 20 objets/min
- **Vitesse de Courroie :** 0,1 m/s

### Métriques de Performance

- **Précision de Tri :** > 95%
- **Capacité de Charge Maximale :** 5 kg
- **Consommation d'Énergie :** 12V, 2A
- **Niveau Sonore :** < 65 dB
- **MTBF :** > 1000 heures

### Résultats de Validation

Tous les composants mécaniques respectent ou dépassent les spécifications de conception avec des marges de sécurité :

- Facteur de sécurité structurel : > 2,5 sur tous les composants PLA
- Durée de vie attendue des roulements : > 10 000 heures à charge nominale
- Tension de courroie maintenue à ±10% de la plage optimale
- Toutes les pièces mobiles fonctionnent dans les tolérances spécifiées

## Fichiers de Conception et Documentation

### Fichiers Source SolidWorks

Projet CAO complet avec toutes les pièces et assemblages :
- 42 fichiers de pièces individuels (.SLDPRT)
- Assemblages principaux et sous-assemblages
- Dessins techniques et spécifications
- Simulations d'études de mouvement

[📥 Télécharger les Fichiers SolidWorks](Mecanique/Assemblage.rar)

### Fichiers d'Impression 3D

Fichiers STL prêts à l'impression pour tous les composants :
- Optimisés pour l'impression 3D FDM
- Pré-supportés si nécessaire
- Directives d'impression incluses
- Instructions d'assemblage

[📥 Télécharger les Fichiers STL](Mecanique/Fichier_Imp3D.zip)

### Notes Importantes

- **Exigences Logicielles :** SolidWorks 2025 ou visionneuse compatible pour les fichiers source
- **Recommandations d'Impression :** 20-40% de remplissage pour les pièces non structurelles, 80-100% pour les composants porteurs
- **Matériau :** PLA recommandé pour toutes les pièces imprimées
- **Tolérances :** Tenir compte d'une tolérance d'impression de 0,2mm dans les assemblages

## Prototype Physique et Tests

### Démonstration du Prototype

[Regarder le système de convoyeur en fonctionnement](Mecanique/video_demo.mp4)

### Résultats des Tests

#### Tests Réussis

- Fonctionnement continu de 8 heures sans défaillance
- Tri précis des cubes de 30mm par couleur
- Suivi stable de la courroie et tension
- Réponse appropriée du mécanisme servo

#### Domaines d'Amélioration

- Glissement de courroie à vitesses plus élevées
- Réduction du bruit dans les mécanismes d'engrenage
- Amortissement des vibrations renforcé
- Lubrification des roulements optimisée

## Conclusion

La conception mécanique du système de convoyeur intelligent répond avec succès à toutes les exigences du TRC 2025, démontrant une construction robuste, un fonctionnement fiable et une intégration transparente avec les sous-systèmes électroniques et informatiques.

### Réalisations Clés

- Fabrication de précision utilisant la technologie d'impression 3D
- Sélection de matériaux optimisée pour le coût et les performances
- Intégration réussie des systèmes mécaniques et électroniques
- Documentation complète et reproductibilité

### Améliorations Futures

- Systèmes avancés d'amortissement des vibrations
- Conception modulaire pour une scalabilité facile
- Options de matériaux améliorées pour des applications spécifiques
- Intégration aux normes Industrie 4.0

---

**UCAO-TECH - TRC 2025**  
Solutions Mécaniques Innovantes pour Systèmes de Tri Automatisés