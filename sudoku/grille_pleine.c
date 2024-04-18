#include <stdio.h>
#include "grille_pleine.h"

int  grille_pleine(int** grille){
    for (int i==0 ; i<9 ; i++){
        for(int j==0 ; j<9 ; j++){
            if (grille[i][j]==0){
                return 1;
            }
        }
    }
    return 0;
}

