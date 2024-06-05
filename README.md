# Projet Arduino - LED sous le lit
 ## Matériel nécessaire
 * x2 résistance 1kΩ
 * x1 résistance 1MΩ (variable selon sensibilité du capteur de lumière souhaité)
 * x1 photorésistance
 * x2 transistor bipolaire (TIP120)
 * x1 capteur de mouvement IR (HC-SR501)
 * x1 bande LED (30 LED/m, 5V)
 * x1 Arduino Nano ou Arduino Pro-Mini 5V

## Schéma électrique
<p align="center"><img src="/Schematic projet.png">

## Alimentation électrique
Si la bande LED fait plus que quelques cm, il faut l'alimenter par le secteur et pas par directement via l'Arduino. Sinon, l'Arduino va cramer dû au courant requis par le ruban LED.
Voir la figure ci-dessous pour l'alimentation du ruban LED et de la carte Arduino :

<p align="center"><img src="/Dessin branchement LED.png">

