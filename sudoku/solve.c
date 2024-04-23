#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "grille_pleine.h"
#include "safe.h"
#include "solve.h"
#include "remplir_case.h"

bool sudoku_solve(int** grille){
    int ligne = 0;
    int colonne = 0;
    int valeur=0;
    if (grille_pleine(grille)){
            while (grille[ligne][colonne]!=0){
                ligne=rand()%(9);
                colonne=rand()%(9);
        }
        int mémoire[9];
        for (int i=0;  i<=8 ; i++){
            if (safe(grille, ligne,colonne,i+1)){
                mémoire[i]=0;
            }
            else{
                mémoire[i]=1;   
            }
        }
        valeur = remplir_case(valeur, mémoire);
        if (valeur!=0){
            grille[ligne][colonne]=valeur;
            sudoku_solve(grille);
            return true;
        }
        else {
            return false;
        }
        return true;
    }
    else {
        return true;
    }
}
