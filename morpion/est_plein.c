#include <stdio.h>
#include "est_plein.h"

int est_plein(int* grille){
    for(int i =0 ; i<9 ; i++){
        if (grille[i]==-1){
            return 0;
        }
    }
    return 1;
}