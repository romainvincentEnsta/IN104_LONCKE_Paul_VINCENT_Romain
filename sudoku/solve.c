#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "solve.h"
#include "remplir_case.h"
#include "grille_pleine.h"
#include "safe.h"

bool sudoku_solve(int** grille){
    srand(time(0));  //On l'utilise pour avoir un nombre aléatoire différent à chaque partie
    int ligne = 0;
    int colonne = 0;
    int valeur=0;
    if (grille_pleine(grille)){                  //Tant que la grille n'est pas pleine on veut la remplir
            while (grille[ligne][colonne]!=0){   //On tire un coéfficient au hasard
                ligne=rand()%(9);
                colonne=rand()%(9);
        }
        int* mémoire;                            //On garde en mémoire les valeurs déjà assignées dans ce tableau
        mémoire=malloc(9*sizeof(int));
        for(int j=0 ; j<9 ; j++){                //On l'initialise à zéro
            mémoire[j]=0;
        }
        for (int i=0;  i<=8 ; i++){                   //On teste quels nombres ont été tirés et on remplit le tableau mémoire
            if (safe(grille, ligne,colonne,i+1)){
                mémoire[i]=1;
                printf("case safe\n");
            }
            else{
                mémoire[i]=0;   
            }
        }
        valeur = remplir_case(valeur, mémoire);   //On assigne une valeur disponible dans le tableau mémoire
        if (valeur!=0){
            grille[ligne][colonne]=valeur;  //On néttoie
            free(mémoire);
            return sudoku_solve(grille);
        }
        else {
        free(mémoire);
        return false;
        }
    }
    else {
        return true;
    }
}
