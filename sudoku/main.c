#include <stdio.h>
#include "safe.h"
#include "afficher_sudoku.h"
#include "solve.h"
#include "sudoku.h"
#include <time.h>
#include <stdbool.h>
#include <stdlib.h>

#define r 9
#define c 9

int main(){
    int** grille = creation_grille();  //On initialise une grille vide
    afficher_sudoku(grille);           //On l'affiche
    sudoku_solve(grille);  
    afficher_sudoku(grille);            //On la remplit
/*    while (!vérification){
        printf("Erreur");
        for (int i = 0;i<9;i++) {
            free(grille[i]);
        }
        free(grille);
        int** grille=creation_grille(r,c);
        vérification=sudoku_solve(grille);
    }
*/
/*  if (!vérification){
        printf("Erreur\n");
    }
    else {
    afficher_sudoku(grille);
    }
*/
    for (int i = 0;i<9;i++) {      //On vide la mémoire
        free(grille[i]);
    }
    free(grille);
    return 0;
}

