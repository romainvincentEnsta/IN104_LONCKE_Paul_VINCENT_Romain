#include "snake_game.h"

void creation_grille(char grille[hauteur][largeur]) {
    for (int i = 0;i<hauteur;++i) {
        for (int j = 0;j<largeur;++j) {
            grille[i][j]='.';
        }
    }
}