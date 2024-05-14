#include <stdio.h>
#include <stdlib.h>
#include "remplir_case.h"
#include <time.h>

int remplir_case(int valeur, int* mémoire){
<<<<<<< HEAD
    if (mémoire[valeur-1]==1){
        return 1;
    }
    else {
        return 0;
=======
    srand(time(0));  //On veut des nombres aléatoires différents
    valeur=rand()%(9)+1;  //On initialise valeur
    if (tableau_plein(mémoire)){     //Si mémoire n'est pas déjà plein
        if (mémoire[valeur-1]==1){   
            return remplir_case(valeur,mémoire);  //Si la valeur de "valeur" a déjà été tiré on recommence
        }
        else{
            return valeur;
        }
>>>>>>> a625a7a3da9adc9b270970c4dc5716b93cd3c8e1
    }
}

