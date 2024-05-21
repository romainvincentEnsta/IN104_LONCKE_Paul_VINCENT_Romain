#include "snake_game.h"

extern char board[hauteur][largeur];
extern int snakeX[largeur * hauteur];
extern int snakeY[largeur * hauteur];
extern int longueur_serpent;

void moveSnakeBody() {
    // On efface la position précédente du serpent sur la grille
    for (int i = 0; i < longueur_serpent; i++) {
        grille[snakeY[i]][snakeX[i]] = '.';
    }

    // On bouge le corps du serpent
    for (int i = longueur_serpent - 1; i > 0; i--) {
        snakeX[i] = snakeX[i - 1];
        snakeY[i] = snakeY[i - 1];
    }

    // Update de la grille avec la nouvelle position du serpent
    placer_serpent(grille, longueur_serpent, snakeX, snakeY);
}
