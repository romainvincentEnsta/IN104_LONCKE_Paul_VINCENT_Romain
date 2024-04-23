#include <stdio.h>
#include <stdlib.h>
#include "remplir_case.h"
#include <time.h>
#include "tableau_plein.h"

int remplir_case(int valeur, int* mémoire){
    srand(time(0));
    valeur=rand()%(9)+1;
    if (tableau_plein(mémoire)){
        if (mémoire[valeur-1]==1){
            return remplir_case(valeur,mémoire);
        }
        else{
            return valeur;
        }
    }
    return 0;
}

