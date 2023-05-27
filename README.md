#
CY-MEMORY-RPG - Fiche README
Table des matières:
1)Description du projet
2)Instructions d'installation pour différents systèmes d'exploitation
3)Configuration requise
4)Bibliothèques externes utilisées
5)Étapes spéciales à suivre
6)Contrôles du jeu
7)Fonctionnalités du jeu
8)Problèmes connus rencontrés
9)Licence/n
10)Remarques

Description du projet
CY-MEMORY-RPG est un jeu de rôle de type tour par tour sur plateau se déroulant dans un labyrinthe. Le jeu permet de jouer de 2 à 4 joueurs, chacun possédant une classe différente. Le but du jeu est de se déplacer sur le plateau, affronter les monstres et trouver un coffre au trésor et une arme antique spécifique à chaque classe. Le joueur qui trouve son arme antique et un coffre au trésor remporte la victoire.

Instructions d'installation pour différents systèmes d'exploitation
Assurez-vous d'avoir un compilateur C installé sur votre ordinateur, comme GCC.
Clonez ce dépôt GIT.
Compilez le jeu en utilisant la commande suivante :
gcc main.c -o jeu

Configuration requise
Système d'exploitation : Windows, macOS, Linux
Compilateur C compatible, comme GCC

Bibliothèques externes utilisées
stdio.h
stdlib.h
string.h
time.h (pour le suivi de la durée du jeu en temps réel)
stdbool.h
unistd.h
Étapes spéciales à suivre
Choisissez le nombre de joueurs.
Entrez le pseudo de chaque joueur.
Sélectionnez la classe de chaque joueur.
Contrôles du jeu
Utilisez les touches z, q, s et d pour vous déplacer dans les différentes directions (haut, bas, gauche, droite) et choisir votre destination.

Fonctionnalités du jeu
Jeu multijoueur seulement.
4 différentes classes de personnages : guerrier, ranger, magicien, voleur.
Cases spéciales avec des effets uniques, comme des portails de téléportation ou des totems de transmutation.
Armes antiques correspondant à chaque classe de joueur, nécessaires pour remporter la victoire.
Différents types de monstres avec des faiblesses face à certaines armes.
Gestion de la mort des joueurs, avec un retour au point de départ.
Apparition aléatoire des joueurs à l'extérieur du tableau.
Chronométrage de la durée du jeu en temps réel.


Différents symboles et leur signification:
▩ signifie qu'une case n'est pas révélée

le - signifie que la case ne fait pas partie du jeu est n'est pas utilisable

la lettre "Z" représente la case Zombie

la lettre "T" représente la case Troll

la lettre "H" représente la case harpie

la lettre "B" représente la case basilic

la lettre "C" représente la case coffre

la lettre "0" représente la case  du portail de teleportation

la lettre "t" représente la case totem de transmutation

la lettre "e" représente l'arme épée

la lettre "b" représente l'arme baton

la lettre "g" représente l'arme grimoire

la lettre "d" représente l'arme dague

le symbole "♣" représente la classe guerrier

le symbole "♦" représente la classe  ranger

le symbole "♥" représente la classe magicien

le symbole "♠" représente la classe voleur



Problèmes connus rencontrés durant la programmation du jeu CY-MEMORY
La création du plateau de jeu a été complexe en raison de l'aspect face cachée des cases. La mise en place de pointeurs a été nécessaire pour gérer cette particularité.
L'apparition des joueurs à l'extérieur du tableau a posé des difficultés, car un simple tableau 5x5 ne convenait pas à cette fonctionnalité.
La gestion du chronométrage en temps réel a été un défi, mais a été résolue pour afficher la durée du jeu à l'écran.
La disposition aléatoire des cartes sur les cases et leur quantité a également été un problème rencontré.

Licence
Le jeu n'a pas été publié sous une licence spécifique.

Remarques
Veuillez noter que cette version de notre jeu CY-MEMORY-RPG en langage C peut contenir des bugs ou des limitations. Si vous rencontrez des problèmes ou avez des suggestions pour améliorer le jeu, n'hésitez pas à nous les signaler. Nous apprécions vos commentaires et vous remercions de vos retour, nous  travaillerons à améliorer votre expérience de jeu.
