#include <stdio.h>

void afficher_grille(char** grille) {
    for (int i = 0;i<20;++i) {
        for (int j = 0;j<20;++j) {
            printf(" %c",grille[i][j]);
        }
        printf("\n");
    }
}
