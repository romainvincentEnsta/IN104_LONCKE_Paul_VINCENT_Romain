#include <stdio.h>
#include "safe.h"
#include "afficher_sudoku.h"
#include "solve.h"
#include "sudoku.h"
#include <stdbool.h>

#define r 9
#define c 9

int main(){
    int** grille = creation_grille(r,c);
    afficher_sudoku(grille);
    bool vérification=sudoku_solve(grille);
    if (!vérification){
        printf("Erreur");
    }
    else {
        afficher_sudoku(grille);
    }
    for (int i = 0;i<9;++i) {
        free(grille[i]);
    }
    free(grille);
    return 0;
}

