#include <stdio.h>
#include <stdlib.h>
#include "remplir_case.h"
#include "tableau_nul.h"
#include <time.h>

int remplir_case(int valeur, int* mémoire){
    srand(time(0));  //On veut des nombres aléatoires différents
    valeur=rand()%(9)+1;  //On initialise valeur
    if (tableau_nul(mémoire)){     //Si mémoire n'est pas déjà plein
        if (mémoire[valeur-1]==1){   
            return remplir_case(valeur,mémoire);  //Si la valeur de "valeur" a déjà été tiré on recommence
        }
        else{
            return valeur;
        }
    }
    return  0;
}

