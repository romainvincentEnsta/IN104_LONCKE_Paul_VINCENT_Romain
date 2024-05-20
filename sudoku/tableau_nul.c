#include <stdio.h>
#include "tableau_nul.h"

int tableau_nul(int* tab){    //On teste si le tableau initialisé auparavant à 0 est bien complètement rempli
    for (int i=0 ; i<9 ; i++){
        if (tab[i]==0){    //test de remplissage 
            return 1;
        }
    }
    return 0;
}