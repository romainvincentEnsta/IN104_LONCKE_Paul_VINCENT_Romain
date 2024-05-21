#include <stdio.h>

int** serpent(int largeur,int hauteur) {
    int** snake;
    snake = (int**)malloc(sizeof(int*)*hauteur);
    for (int i = 0;i<largeur;++i) {
        snake[i] = malloc(sizeof(int)*largeur);
    }

    return snake;
}