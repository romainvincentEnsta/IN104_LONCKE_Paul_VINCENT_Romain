#ifndef SNAKE_GAME_H
#define SNAKE_GAME_H

#define largeur 20
#define hauteur 20
#define LONGUEUR_SERPENT_INITIALE 3

extern char grille[hauteur][largeur];
extern int snakeX[largeur * hauteur];
extern int snakeY[largeur * hauteur];
extern int longueur_serpent;
extern int foodX, foodY;
extern char direction;
extern int gameOver;

#endif 
