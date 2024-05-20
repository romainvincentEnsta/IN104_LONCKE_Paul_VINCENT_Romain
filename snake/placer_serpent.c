#include <stdio.h>

#define largeur 20
#define hauteur 20

char** placer_serpent(char** grille, int longueur_serpent) {
    int startX = largeur/2;
    int startY = hauteur/2;

    for (int i = 0;i<longueur_serpent;++i) {
        grille[startY + i][startX] = 'O';
    }
    return grille;
}