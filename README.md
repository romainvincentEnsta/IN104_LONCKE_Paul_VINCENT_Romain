# IN104_Projet

# Sommaire
* [Présentation du projet](#présentation-du-projet)
* [Présentation des différents jeux](#présentation-des-différents-jeux)
    * [Sudoku](#sudoku)
    * [Morpion](#morpion)
    * [PacMan](#pacman)
    * [Snake](#snake)
* [Mise en oeuvre des différents jeux](#mise-en-oeuvre-des-différents-jeux)
    * [Mise en oeuvre du Sudoku](#mise-en-oeuvre-du-sudoku)
        * [Création de la grille](#création-de-la-grille)
        * [Mise en place de la grille de jeu](#mise-en-place-de-la-grille-de-jeu)
        * [Jouabilité](#jouabilité)
    * [Mise en oeuvre du morpion](#mise-en-oeuvre-du-morpion)
        * [Création de la grille](#création-de-la-grille)
        * [Jouabilité](#jouabilitc3a9-1)
    * [Mise en oeuvre de PacMan]()
        * [Création du labyrinthe](#initialisation)
        * [Mouvements de PacMan et des fantômes](#mouvement-de-pac_man-et-des-fantômes)
        * [Jouabilité](#jouabilité-2)
    * [Mise en oeuvre de Snake]()


# Présentation du projet
On souhaite reproduire le fonctionnement d'une machine de jeu des années 70/80 en recréant 4 jeux vidéos phares : Sudoku,Morpion,PacMan,Snake.


# Présentation des différents jeux
## Sudoku
Le but du jeu est de remplir la grille avec une série de chiffres tous différents, qui ne se trouvent jamais plus d’une fois sur une même ligne, dans une même colonne ou dans une même région (également appelée « bloc », « groupe », « secteur » ou « sous-grille »). Les chiffres allant de 1 à 9, les régions sont alors des carrés de 3 × 3. Quelques chiffres sont déjà disposés dans la grille, ce qui autorise une résolution progressive du problème complet.

## Morpion
Les joueurs inscrivent tour à tour leur symbole sur une grille 3 x 3. Le premier qui parvient à aligner trois de ses symboles horizontalement, verticalement ou en diagonale gagne la partie.

## PacMan
Le jeu consiste à déplacer Pac-Man, un personnage qui, vu de profil, ressemble à un diagramme circulaire à l’intérieur d’un labyrinthe, afin de lui faire manger toutes les pac-gommes qui s’y trouvent en évitant d’être touché par des fantômes.

## Snake 
Le joueur contrôle une longue et fine ligne semblable à un serpent, qui doit slalomer entre les bords de l'écran et les obstacles qui parsèment le niveau. Pour gagner chacun des niveaux, le joueur doit faire manger à son serpent un certain nombre de pastilles similaire à de la nourriture, allongeant à chaque fois la taille du serpent. Alors que le serpent avance inexorablement, le joueur ne peut que lui indiquer une direction à suivre (en haut, en bas, à gauche, à droite) afin d'éviter que la tête du serpent ne touche les murs ou son propre corps, auquel cas il risque de mourir.


# Mise en oeuvre des différents jeux
## Mise en oeuvre du Sudoku
### Création de la grille 
On commence par générer un tableau de __int*__ de taille 9 x 9. Puis on remplit d'abord les carrés 3 x 3 sur la diagonale principale (de gauche à droite et de haut en bas). On utilise la fonction __RAND__ pour obtenir des nombres aléatoires. Les tableaux __cell_i__ permettent de compter les chiffres déjà tirés. Ainsi chaque carré obéit bien aux contraintes fixées par le sudoku. On réalise tout cela avec la fonction __sudoku.c__.

Ensuite on remplit les autres cases de la grille en respectant les contraintes du Sudoku.

La fonction __safe__ dans __safe.c__ permet de vérifier que les conditions sont bien remplies.

__Grille pleine__ permet de vérifier si on a complété la grille.

Enfin __afficher_sudoku__ se charge de l'affichage.

Le fichier __main.c__ permet de d'executer l'ensemble pour obtenir la grille.

### Mise en place de la grille de jeu
Jusqu'ici nous avons un problème de Segmentation Fault pour respecter les contraintes. 

### Jouabilité

## Mise en oeuvre du morpion
### Création de la grille 

Le fichier __creation_grille.c__ permet d'allouer avec un __malloc__ l'espace mémoire nécessaire à la création de la grille 3 x 3.

### Jouabilité

La fonction __placer__ permet en prennant la donnée de l'utilisateur de remplir la case qu'il a choisi avec son symbole.

Les fichiers __a_gagné.c__ et __est_plein.c__ permettent de vérifier si la partie se termine. Soit en ayant un joueur qui la remporte, soit en faisant match nul (auquel cas on vérifie si la grille est pleine).

Le fichier __morpion.c__ est celui permettant la prise en compte du choix des joueurs. 

Enfin le fichier __afficher_grille.c__ permet d'afficher la grille.

## Mise en oeuvre de PacMan
### Initialisation

Au début du fichier __main.c__, on initialise la structure permettant de contenir pac_man définiedans le fichier
 __structures.h__, et la zone de jeu qui est une matrice de caractère.

Par la suite, on utilise la fonction __initialisation__ afin d'initialiser les fantômes sur la zone de jeu. 

On définit ensuite le tableau __pt_ou_pas_pt__, qui donne l'information de la présence de nourriture avant que les fantômes arrivent
sur la case où ils sont actuellement.

### Mouvement de pac_man et des fantômes

Le fichier __get_arrow.c__ contient les fonctions __get_arrow__, qui permet de récupérer la direction voulue par
l'utilisateur pour le pacman, et __char_input__ qui est une version améliorée de scan_f

Le fichier __move_pacman__ contient la fonction __move_pacman__ qui permet, une fois les déplacements connus de pacman,
de le déplacer effectivement et de gérer la possible perte d'une vie.

Le fichier __move_ghost.c__ contient la fonction __move_ghost__ qui permet de déplacer les fantômes aléatoirement,
en gardant la nourriture au bon endroit

Le fichier __is_still_alive.c__ contient la fonction __is_still_alive__, qui permet de vérifier s'il reste encore des vies
au pacman, et de déterminer ainsi une condition d'arrêt du jeu

### Jouabilité

Le code demandera donc à l'utilisateur d'entrer la direction dans laquelle il veut bouger le PacMan en mettant la lettre L,R,U ou D 
pour Left,Right,Up ou Down. A chaque tour les fantômes se déplacent donc de manière aléatoire.
