---
outline: { level: [2,3] }
outlineImage: /final/images/phase de collecte/OIP.webp
---

# À propos du Rostmaster X3

### Étapes d'assemblage du kit Rosmaster X3

Découvrez deux méthodes simples pour assembler votre kit Rosmaster X3 : visionnez nos vidéos d'assemblage détaillées pour un guidage visuel étape par étape, ou téléchargez notre guide ZIP [ici](ROSMASTER-X1-X3-Manual.zip) avec un manuel illustré complet incluant des photos pour chaque étape.

<VideoPlayer />

### Introduction au câblage
Le câblage du robot Rostmaster X3 représente une phase critique de l'assemblage, où la précision est primordiale pour écarter tout danger de court-circuit capable de détériorer définitivement les éléments électroniques. Il est crucial d'adopter une approche rigoureuse afin d'obtenir des performances fiables et pérennes, en vérifiant que toutes les liaisons électriques correspondent exactement aux normes requises. En respectant scrupuleusement les diagrammes fournis, on élimine les fautes habituelles qui nuiraient à l'efficacité du robot, favorisant ainsi une synergie parfaite entre les modules pour une utilisation intuitive et sans faille.

#### Description de l'interface des cartes d'expansion et du Raspberry Pi
![Caractéristiques de la carte Rosmaster](/final/images/phase%20de%20collecte/carte.jpg)

#### Schéma de câblage pour la version Raspberry Pi
![Schéma de câblage du Raspberry Pi 5](https://www.yahboom.net/public/upload/upload-html/1756384156/pi5.jpg)

### Précautions d'utilisation
- Le robot Rosmaster prend en charge quatre contrôleurs principaux, à savoir la carte de développement Jetson Nano, la carte de développement Jetson Orin NANO, la carte de développement Jetson Orin NX et la carte Raspberry Pi 5.
- Pour les cartes de développement Jetson Nano, Jetson ORIN NANO et Jetson ORIN NX, le nom d'utilisateur système d'usine est : jetson, mot de passe : yahboom
- Pour le contrôleur principal Raspberry Pi 5, le nom d'utilisateur système d'usine est : pi, mot de passe : yahboom
- Quel que soit le contrôleur principal, le mot de passe de connexion de Jupyter Lab est : yahboom
- Puisque le robot Rosmaster initialisera le capteur d'attitude neuf axes embarqué lors de la mise sous tension, il doit être placé horizontalement sur le sol lors de la mise sous tension ou de la réinitialisation en appuyant sur le bouton RESET, et il peut être utilisé normalement après avoir entendu un 'bip' après environ quelques secondes.
- Dans des conditions normales, l'indicateur MCU du robot Rosmaster clignote deux fois toutes les trois secondes. Si l'indicateur MCU est toujours allumé ou éteint, cela signifie que le microcontrôleur sur la carte d'extension est dans un état anormal. Veuillez appuyer sur le bouton RESET pour réinitialiser le microcontrôleur.
- Avant d'exécuter le programme singleton, veuillez d'abord fermer le grand programme, sinon cela peut avoir un impact.
- Après la mise sous tension, le lidar tournera automatiquement. Veuillez ne pas bloquer la rotation du lidar pour éviter d'endommager le produit.

### Batterie et charge
- Il est strictement interdit d'accéder à des équipements qui dépassent la charge du produit.
- Il est strictement interdit d'utiliser des batteries ou des chargeurs non fournis par l'entreprise.
- Lors de la charge de la batterie, veuillez éteindre l'interrupteur d'alimentation principal sur la carte d'extension. Ne pas utiliser la batterie pendant la charge pour éviter que le chargeur ou la batterie n'explose.
- Lorsque la batterie est en charge, l'indicateur du chargeur s'allumera en rouge, et lorsqu'elle sera complètement chargée, elle s'allumera en vert. Après la fin de la charge, le chargeur doit être débranché à temps pour éviter d'endommager la batterie due à une surcharge. Quelqu'un doit être présent lors de la charge.
- Lorsque la batterie est inférieure à 9.6V, le buzzer de la carte d'extension émet un son d'alarme 'didi di di', et l'indicateur MCU clignote rapidement. À ce moment, vous devez éteindre l'alimentation puis charger la batterie.
- Éteignez l'interrupteur d'alimentation principal sur la carte d'extension après utilisation. Lorsque non utilisé pendant une longue période, veuillez maintenir la tension du pack de batteries lithium à 11.1V~11.7V, retirez le pack de batteries lithium et placez-le dans la zone de sécurité des batteries, ne le mélangez pas avec des objets métalliques, le film isolant enveloppé à l'extérieur ne peut pas être déchiré.
- Tenez-vous à l'écart de la chaleur, du feu, de tout liquide, n'utilisez jamais dans un environnement humide ou pluvieux. Un environnement humide peut causer des dommages par court-circuit au produit.
- Lorsque le pack de batteries lithium ou le chargeur de batterie prend feu ou fume, veuillez utiliser un extincteur à sable ou à poudre sèche pour éteindre le feu, puis évacuez rapidement vers une zone sûre.
- Si le pack de batteries lithium ou le chargeur de batterie est endommagé, sérieusement chauffé, déformé, décoloré, odorant ou tout autre phénomène anormal, il ne doit pas être utilisé, et contactez-nous ou d'autres agents à temps pour le traiter.
- Veuillez l'utiliser dans un environnement avec une température de 0°C à 35°C. La stabilité du pack de batteries lithium ou du chargeur de batterie peut diminuer à d'autres températures.
- Il est strictement interdit de percer intentionnellement, court-circuiter, connecter en sens inverse, souder privément, frapper, écraser, jeter des packs de batteries lithium ou des chargeurs de batterie.
- Il est interdit d'utiliser le produit dans un environnement d'électricité statique forte et de champ magnétique fort, sinon le produit sera endommagé.
- Il est strictement interdit de modifier ou de modifier la carte de circuit matériel sans autorisation.
- Lorsqu'il n'y a pas de supervision adulte, veuillez ne pas laisser les enfants utiliser des packs de batteries lithium ou des chargeurs de batterie, et stockez les batteries dans un endroit que les enfants ne peuvent pas atteindre.
- Si le pack de batteries lithium ou le chargeur de batterie fume ou chauffe (dans les cas graves, l'enveloppe extérieure se fissurera), vous devriez rapidement déconnecter l'interrupteur d'alimentation principal, l'alimentation, ou déconnecter l'interrupteur principal, et placer la batterie ou le chargeur dans une zone ouverte.
