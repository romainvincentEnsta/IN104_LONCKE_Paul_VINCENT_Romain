#include <stdio.h>

#define largeur 20
#define hauteur 20


char** creation_grille() {
    char** grille;
    grille = (char**)malloc(sizeof(char*)*hauteur);
    for (int i = 0;i<largeur;++i) {
        grille[i] = malloc(sizeof(char)*largeur);
    }

    for (int i = 0;i<hauteur;++i) {
        for (int j = 0;j<largeur;++j) {
            grille[i][j]='.';
        }
    }

    return grille;
}