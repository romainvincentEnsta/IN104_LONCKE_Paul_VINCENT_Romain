#!/bin/bash

# Affiche le menu pour l'utilisateur
echo "Veuillez choisir un exécutable à lancer :"
echo "0) Morpion"
echo "1) Sudoku"
echo "2) PacMan"
echo "3) Snake"

# Lit le choix de l'utilisateur
read -p "Entrez le numéro de votre choix (0-3) : " choix

# Exécute l'exécutable correspondant au choix de l'utilisateur
case $choix in
    0)
        echo "Lancement du morpion"
        cd ./morpion/
        make
        ./morpion.x
        ;;
    1)
        echo "Lancement du Sudoku"
        cd ./sudoku/
        make
        ./main.x
        ;;
    2)
        echo "Lancement de PacMan"
        cd ./pacman/
        make
        ./main.x
        ;;
    3)
        echo "Lancement du Snake"
        cd ./snake/
        gcc -Wall -Werror snake.c -o main.x
        ./main.x
        ;;
    *)
        echo "Choix invalide. Veuillez entrer un numéro entre 1 et 4."
        ;;
esac
