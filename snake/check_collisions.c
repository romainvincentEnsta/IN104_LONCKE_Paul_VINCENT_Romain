#include "snake_game.h"

extern int snakeX[largeur * hauteur];
extern int snakeY[largeur * hauteur];
extern int longueur_serpent;
extern int gameOver;

void checkCollision() {
    // On regarde la collision avec les murs
    if (snakeX[0] < 0 || snakeX[0] >= largeur || snakeY[0] < 0 || snakeY[0] >= hauteur) {
        gameOver = 1;
    }
    
    // On regarde la collision avec lui même
    for (int i = 1; i < longueur_serpent; i++) {
        if (snakeX[0] == snakeX[i] && snakeY[0] == snakeY[i]) {
            gameOver = 1;
        }
    }
}
