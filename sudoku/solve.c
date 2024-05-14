#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "safe.h"
#include "solve.h"
#include "remplir_case.h"
#include "grille_pleine.h"
#include "tableau_nul.h"

bool sudoku_solve(int** grille){
    int ligne = 0;
    int colonne = 0;
    int valeur=0;
    if (!grille_pleine(grille)){
        printf("grille non pleine\n");
            while (grille[ligne][colonne]!=0){
                ligne=rand()%(9);
                colonne=rand()%(9);
        }
        int* mémoire;
        mémoire=malloc(9*sizeof(int));
        for(int j=0 ; j<9 ; j++){
            mémoire[j]=0;
        }
        for (int i=0;  i<=8 ; i++){
            if (safe(grille, ligne,colonne,i+1)){
                mémoire[i]=1;
                printf("case safe\n");
            }
            else{
                mémoire[i]=0;   
            }
        }
        if(!tableau_nul(mémoire)){
            printf("tableau non nul\n");
            valeur=rand()%(9)+1;
            while(!remplir_case(valeur,mémoire)){
                valeur=rand()%(9)+1;
            }
            grille[ligne][colonne]=valeur;
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
