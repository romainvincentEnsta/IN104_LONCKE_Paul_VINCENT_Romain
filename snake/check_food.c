#include "snake_game.h"

extern int snakeX[largeur * hauteur];
extern int snakeY[largeur * hauteur];
extern int longueur_serpent;
extern int foodX, foodY;

void checkFood() {
    if (snakeX[0] == foodX && snakeY[0] == foodY) {
        // On augmente la taille du serpent
        longueur_serpent++;
        // On ajoute un nouveau segment au serpent a la position actuelle de sa queue
        snakeX[longueur_serpent - 1] = snakeX[longueur_serpent - 2];
        snakeY[longueur_serpent - 1] = snakeY[longueur_serpent - 2];
        // Placer le nouveau manger
        placer_food(grille[hauteur][largeur], &foodX, &foodY);
    }
}
