#include <stdio.h>
#include "grille_pleine.h"

int  grille_pleine(int** grille){     //La fonction parcourt la grille qui a précédemment été initialisée à zéro et renvoit 0 si tous les coefficients sont non nuls et 1 sinon
    for (int i=0 ; i<9 ; i++){
        for(int j=0 ; j<9 ; j++){
            if (grille[i][j]==0){  //On teste si le coefficient vaut 0 et n'a donc pas encore été remplit
                return 0;
            }
        }
    }
    return 1;
}

