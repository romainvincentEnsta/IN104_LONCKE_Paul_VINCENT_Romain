#include <stdlib.h>
#include <time.h>
#include "snake_game.h"

void placer_food(char** grille, int *foodX, int* foodY) {
    srand(time(0));
    do {
        *foodX = rand() % largeur;
        *foodY = rand() % hauteur; 
    } while (grille[*foodY][*foodX] == 'O');

    grille[*foodY][*foodX] = 'X';
}