#include "snake_game.h"

void placer_serpent(char** grille, int longueur_serpent, int snakeX[], int snakeY[]) {
    int startX = largeur/2;
    int startY = hauteur/2;

    for (int i = 0;i<longueur_serpent;++i) {
        snakeX[i] = startX;
        snakeY[i] = startY + i;
        grille[snakeY[i]][snakeX[i]] = 'O';
    }
}