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
    srand(time(0));
    int gagné=true;
    int** grille = creation_grille();
    afficher_sudoku(grille);
    gagné=sudoku_solve(grille);
    while(!gagné){
        for(int i=0 ; i<9 ; i++){
            free(grille[i]);
        }
        free(grille);
        int**grille=creation_grille();
        afficher_sudoku(grille);
        gagné=sudoku_solve(grille);
        printf("%d\n",gagné);
    }
    if (sudoku_solve(grille)){
        afficher_sudoku(grille);
        printf("Ca marche\n");
    }
    else {
        printf("C'est non\n");
    }
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
    for (int i = 0;i<9;i++) {
        free(grille[i]);
    }
    free(grille);
    return 0;
}

