#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define largeur 20
#define hauteur 20

char** placer_food(char** grille) {
    srand(time(0));
    int foodX, foodY;

    do {
        foodX = rand() % largeur;
        foodY = rand() % hauteur; 
    } while (grille[foodX][foodY] == 'O');

    grille[foodX][foodY] = 'X';
    
    return grille;
}