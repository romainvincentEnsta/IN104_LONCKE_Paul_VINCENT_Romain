#include <stdio.h>
#include "remplir_case.h"

int remplir_case(int valeur, int* mémoire){
    valeur=rand()%(9)+1;
    for (int j =0 ; j<=8 ; j++){
        if (mémoire[j]==0){
            if (mémoire[valeur-1]==1){
                remplir_case(valeur,mémoire);
                return 0;
            }
            else{
                return valeur;
            }
        }
        else {
            return 0;
        }
    }
    return valeur;
}

