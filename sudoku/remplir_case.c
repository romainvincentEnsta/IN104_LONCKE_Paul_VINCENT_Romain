#include <stdio.h>
#include "remplir_case.h"
#include "tableau_plein.h"

int remplir_case(int valeur, int* mémoire){
    valeur=rand()%(9)+1;
    if (tableau_plein(mémoire)){
        if (mémoire[valeur-1]==1){
            remplir_case(valeur,mémoire);
            return 0;
        }
        else{
            return valeur;
        }
    }
    return 0;
}

