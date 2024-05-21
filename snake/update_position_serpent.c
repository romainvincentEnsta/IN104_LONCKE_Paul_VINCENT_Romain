#include "snake_game.h"

extern int snakeX[largeur * hauteur];
extern int snakeY[largeur * hauteur];
extern char direction;

void updateSnakePosition() {
    moveSnakeBody();
    
    // Move snake head
    switch (direction) {
        case 'z': snakeY[0]--; break;
        case 's': snakeY[0]++; break;
        case 'q': snakeX[0]--; break;
        case 'd': snakeX[0]++; break;
    }
}
