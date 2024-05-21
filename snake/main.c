#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "snake_game.h"
#include "initialisation_partie.h"
#include "affichage_grille.h"
#include "update_position_serpent.h"
#include "check_collision.h"
#include "check_food.h"

#define largeur 20
#define hauteur 20
#define INITIAL_SNAKE_LENGTH 3

extern char grille[hauteur][largeur];
extern int snakeX[largeur * hauteur];
extern int snakeY[largeur * hauteur];
extern int longueur_serpent;
extern int foodX, foodY;
extern char direction;
extern int gameOver;

int main() {
    initialisation_partie();
    
    
    printf("Game Over!\n");
    return 0;
}
