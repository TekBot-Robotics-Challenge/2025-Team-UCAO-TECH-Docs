# Contexte de la Documentation TRC

## 📖 Vue d'ensemble
Site de documentation pour le projet Trophée de Robotique (TRC) construit avec VitePress.

## 🌍 Langues Supportées
- **Français** : Version principale (racine)
- **English** : Version anglaise (dossier `en/`)

## 📁 Structure de Navigation (Sidebar)

### Pré-sélection
- **Informatique** : Test 1, Test 2, Test 3, Test Final
- **Électronique** : Test 1, Test 2, Test 3, Test Final  
- **Mécanique** : Test 1, Test 2, Test 3, Test Final

### Phase Finale
- **Phase de collecte** : À propos du Rostmaster X3, Configuration système et accès distant (`final/phase de collecte/`)

### Version Anglaise (`en/`)
- **`index.md`** : Page d'accueil en anglais
- **`api-examples.md`** : Exemples d'API en anglais
- **`markdown-examples.md`** : Exemples Markdown en anglais

## 📝 Tests de Préselection

### Organisation
Les tests sont organisés par **département** et par **langue** :

```
preselection/
├── electronique/
│   ├── test1.md
│   ├── test2.md
│   ├── test3.md
│   └── final-test.md
├── informatique/
│   ├── test1.md
│   ├── test2.md
│   ├── test3.md
│   └── final-test.md
└── mecanique/
    ├── test1.md
    ├── test2.md
    ├── test3.md
    └── final-test.md

en/preselection/
├── electronique/
│   ├── test1.md
│   ├── test2.md
│   ├── test3.md
│   └── final-test.md
├── informatique/
│   ├── test1.md
│   ├── test2.md
│   ├── test3.md
│   └── final-test.md
└── mecanique/
    ├── test1.md
    ├── test2.md
    ├── test3.md
    └── final-test.md
```

### Départements
1. **Électronique** : Tests liés à l'électronique et aux circuits
2. **Informatique** : Tests de programmation et logiciels
3. **Mécanique** : Tests de conception mécanique

### Niveaux de Tests
- `test1.md` : Premier niveau de test
- `test2.md` : Deuxième niveau de test
- `test3.md` : Troisième niveau de test
- `final-test.md` : Test final récapitulatif

## 🏆 Phase Finale

### Structure
```
final/
├── phase de collecte/
└── phase de trie/
```

**Status** : Dossiers créés mais vides pour l'instant
**Objectif** : Documentation des phases finales de la compétition

## ⚙️ Configuration Technique

### VitePress
- **Fichier de config** : `.vitepress/config.mjs`
- **Build output** : `.vitepress/dist/`
- **Cache** : `.vitepress/cache/`
- **Thème personnalisé** : `.vitepress/theme/`

### Package Management
- **Gestionnaire** : npm
- **Fichier** : `package.json`
- **Lock file** : `package-lock.json`
- **Dépendances** : `node_modules/`

### Commandes NPM
```bash
npm run docs:dev    # Serveur de développement
npm run docs:build  # Build pour production
npm run docs:preview # Prévisualiser le build
```

## 🎨 Assets
- `public/final/images/phase de collecte/OIP.webp` : Image principale du projet TRC (disponible pour utilisation future)
- `public/final/images/phase de collecte/carte.jpg` : Caractéristiques de la carte Rosmaster (utilisée dans la page À propos du Rostmaster X3)
- `public/final/images/phase de collecte/carte1.jpg` : Vue 1 de la carte Rosmaster (disponible pour utilisation future)
- `public/images/test3/robot_et_labyrinthe.png` : Robot TekBot dans le labyrinthe (disponible pour utilisation future)

## 🔍 Conventions de Nommage

### Fichiers Markdown
- Utiliser des noms descriptifs en kebab-case
- Extensions : `.md` pour Markdown
- Les fichiers HTML (`.html`) sont des exports ou pages spéciales

### Structure des URLs
- **Français** : `/chemin/vers/page`
- **Anglais** : `/en/chemin/vers/page`

## 📋 Checklist pour Nouvelles Pages

Lors de la création d'une nouvelle page :

- [ ] Créer la version française dans le bon dossier
- [ ] Créer la version anglaise dans `en/[même-chemin]`
- [ ] Ajouter le frontmatter YAML si nécessaire
- [ ] Mettre à jour la navigation dans `.vitepress/config.mjs`
- [ ] Vérifier les liens internes
- [ ] Tester le rendu local avec `npm run docs:dev`

## 🔗 Liens Internes

### Format VitePress
```markdown
[Texte du lien](./chemin/relatif)
[Autre page](/chemin/absolu)
```

### Navigation entre langues
- De FR vers EN : `/en/chemin/page`
- De EN vers FR : `/chemin/page`

### Liens importants
- **Page d'accueil** : Bouton "Découvrir le projet" → `/preselection/informatique/test1`
- **À propos du Rostmaster X3** : `/a-propos-du-rostmaster-x3`

## 📊 Statistiques

**Total des pages créées** : 37 pages
- 6 pages principales (racine)
- 3 pages en anglais (racine)
- 12 tests français (préselection)
- 12 tests anglais (préselection)
- 4 pages de tests finaux par département
- 2 dossiers de phase finale (vides)

## 💡 Bonnes Pratiques

1. **Cohérence** : Maintenir la parité FR/EN
2. **Structure** : Respecter l'organisation par département
3. **Nommage** : Utiliser des noms clairs et descriptifs
4. **Validation** : Tester localement avant commit
5. **Documentation** : Mettre à jour ce fichier pour les changements majeurs

## 🚀 Déploiement

**Note** : La configuration de déploiement doit être vérifiée dans `.vitepress/config.mjs`

---

**Dernière mise à jour** : 9 janvier 2026
**Changements récents** :
- Correction de la commande de lancement de la caméra Astra de `astra.launch.py` à `astra.launch.xml` dans `configuration-rviz2.md`
- Renommage de `markdown-examples.md` en `a-propos-du-rostmaster-x3.md`
- Correction des liens dans la configuration VitePress
- Modification du bouton "Découvrir le projet" vers le test 1 informatique
- Réorganisation de la sidebar pour refléter les pages existantes
- Déplacement de la page "À propos du Rostmaster X3" vers `final/phase de collecte/`
- Déplacement des images vers `public/final/images/phase de collecte/`
- Mise à jour des liens d'images dans le fichier markdown
- Déplacement de "Configuration système et accès distant" vers `final/phase de collecte/`
- Réorganisation de la navigation : regroupement des pages de phase de collecte
- Suppression des sections "Phase de tri" et "Documentation générale" de la sidebar
- Correction du chemin de l'image OIP.webp pour la compatibilité VitePress
- Remplacement des deux images par une seule : carte.jpg dans la page Rostmaster
