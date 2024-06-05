# Projet Arduino - LED sous le lit
Ce petit projet permet de contrôler un ruban LED installé sous un lit : lorsque la luminosité est suffisament faible (i.e. la nuit, mesuré via une photorésistance) et qu'un mouvement est détecté (via un capteur de mouvement infra-rouge), alors les LEDs s'allument pendant une certaine période.

 ## Matériel nécessaire
 * x2 résistance 1kΩ
 * x1 résistance 1MΩ (variable selon sensibilité du capteur de lumière souhaité)
 * x1 photorésistance
 * x2 transistor bipolaire (TIP120)
 * x1 capteur de mouvement IR (HC-SR501)
 * x1 bande LED (30 LED/m, 5V)
 * x1 Arduino Nano ou Arduino Pro-Mini 5V
 * x1 alimentation de 5V (l'ampérage de l'alim va dépendre de la longueur du ruban LED et de la puissance lumineuse qui va être utilisée. Pour 4m de LED et un luminosité basse, un chargeur de téléphone suffit)

## Schéma électrique
<p align="center"><img src="/Schematic projet.png">

## Alimentation électrique
Si la bande LED fait plus que quelques cm, il faut l'alimenter par le secteur et pas par directement via l'Arduino. Sinon, l'Arduino va cramer dû au courant requis par le ruban LED.
Voir la figure ci-dessous pour l'alimentation du ruban LED et de la carte Arduino :

<p align="center"><img src="/Dessin branchement LED.png">

