import { defineConfig } from 'vitepress'

// https://vitepress.dev/reference/site-config
export default defineConfig({
  base: '/trc2k25/',
  locales: {
    root: {
      label: 'Français',
      lang: 'fr',
      title: 'UCAO-TECH',
      description: 'Documentation du projet TRC 2025 - Équipe UCAO-TECH Bénin',
      themeConfig: {
        nav: [
          { text: 'Accueil', link: '/' }
        ],
        sidebar: [
          {
            text: 'Pre-selection',
            items: [
              { 
                text: 'Informatique', 
                collapsed: false,
                items: [
                  { text: 'Test 1 : Création d’une classe pour un Robot', link: '/preselection/informatique/test1' },
                  { text: 'Test 2 : Introduction à ROS2', link: '/preselection/informatique/test2' },
                  { text: 'Test 3 : Création d’un Algorithme de Pathfinding', link: '/preselection/informatique/test3' },
                  { text: 'Test Final : Système de convoyeur', link: '/preselection/informatique/final-test' },
                ]
              },
              { 
                text: 'Électronique', 
                collapsed: false,
                items: [
                  { text: 'Test 1 : Gyroscope et accéléromètre', link: '/preselection/electronique/test1' },
                  { text: 'Test 2 : La boîte noire', link: '/preselection/electronique/test2' },
                  { text: 'Test 3 : Afficheur 7 segments', link: '/preselection/electronique/test3' },
                  { text: 'Test Final : Système de convoyeur', link: '/preselection/electronique/final-test' },
                ]
              },
              { 
                text: 'Mécanique', 
                collapsed: false,
                items: [
                  { text: 'Test 1 : Niveau Débutant', link: '/preselection/mecanique/test1' },
                  { text: 'Test 2 : Niveau Intermédiaire', link: '/preselection/mecanique/test2' },
                  { text: 'Test 3 : Niveau Avancé', link: '/preselection/mecanique/test3' },
                  { text: 'Test Final : Système de convoyeur', link: '/preselection/mecanique/final-test' },
                ]
              }
            ]
          },
          {
            text: 'Final',
            items: [
              {
                text: 'Phase de collecte',
                collapsed: false,
                items: [
                  { text: 'À propos du Rostmaster X3', link: '/final/phase de collecte/a-propos-du-rostmaster-x3' },
                  { text: 'Configuration système et accès distant', link: '/final/phase de collecte/configuration-logicielle' },
                  { text: 'Ressources de développement', link: '/final/phase de collecte/ressources-de-developpement' },
                  { text: 'Configuration RViz2', link: '/final/phase de collecte/configuration-rviz2' },
                  { text: 'Téléopération et Cartographie', link: '/final/phase de collecte/teleoperation-cartographie' }
                ]
              }
            ]
          }
        ],
        socialLinks: [
          { icon: 'github', link: 'https://github.com/TekBot-Robotics-Challenge/2025-Team-UCAO-TECH-Docs' }
        ],
        docFooter: {
          prev: 'Page précédente',
          next: 'Page suivante'
        },
        outline: {
          label: 'Sur cette page'
        },
        returnToTopLabel: 'Retour en haut',
        sidebarMenuLabel: 'Menu',
        darkModeSwitchLabel: 'Thème',
        lightModeSwitchLabel: 'Thème'
      }
    },
    en: {
      label: 'English',
      lang: 'en-US',
      title: 'UCAO-TECH',
      description: 'TRC 2025 Project Documentation - UCAO-TECH Benin Team',
      themeConfig: {
        nav: [
          { text: 'Home', link: '/en/' }
        ],
        sidebar: [
          {
            text: 'Pre-selection',
            items: [
              { 
                text: 'IT', 
                collapsed: false,
                items: [
                  { text: 'Test 1: Creating a class for a Robot', link: '/en/preselection/informatique/test1' },
                  { text: 'Test 2: Introduction to ROS2', link: '/en/preselection/informatique/test2' },
                  { text: 'Test 3: Creating a Pathfinding Algorithm', link: '/en/preselection/informatique/test3' },
                  { text: 'Final Test: Conveyor System', link: '/en/preselection/informatique/final-test' }
                ]
              },
              { 
                text: 'Electronics', 
                collapsed: false,
                items: [
                  { text: 'Test 1: Gyroscope and accelerometer', link: '/en/preselection/electronique/test1' },
                  { text: 'Test 2: The black box', link: '/en/preselection/electronique/test2' },
                  { text: 'Test 3: 7-segment display', link: '/en/preselection/electronique/test3' },
                  { text: 'Final Test: Conveyor System', link: '/en/preselection/electronique/final-test' }
                ]
              },
              { 
                text: 'Mechanics', 
                collapsed: false,
                items: [
                  { text: 'Test 1: Beginner Level', link: '/en/preselection/mecanique/test1' },
                  { text: 'Test 2: Intermediate Level', link: '/en/preselection/mecanique/test2' },
                  { text: 'Test 3: Advanced Level', link: '/en/preselection/mecanique/test3' },
                  { text: 'Final Test: Conveyor System', link: '/en/preselection/mecanique/final-test' }
                ]
              }
            ]
          },
          {
            text: 'Final',
            items: [
              {
                text: 'Collection Phase',
                collapsed: false,
                items: [
                  { text: 'About the Rostmaster X3', link: '/en/markdown-examples#about-the-rostmaster-x3' }
                ]
              },
              {
                text: 'Sorting Phase',
                collapsed: false,
                items: [
                  { text: 'About the Dofbot', link: '/en/api-examples#about-the-dofbot' }
                ]
              }
            ]
          }
        ],
        socialLinks: [
          { icon: 'github', link: 'https://github.com/TekBot-Robotics-Challenge/2025-Team-UCAO-TECH-Docs' }
        ],
        docFooter: {
          prev: 'Previous page',
          next: 'Next page'
        },
        outline: {
          label: 'On this page'
        },
        returnToTopLabel: 'Return to top',
        sidebarMenuLabel: 'Menu',
        darkModeSwitchLabel: 'Theme',
        lightModeSwitchLabel: 'Theme'
      }
    }
  },
  themeConfig: {
    search: {
      provider: 'local'
    }
  },
  markdown: {
    math: true
  }
})
