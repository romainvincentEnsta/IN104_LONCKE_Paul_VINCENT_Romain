#include <stdio.h>
#include "afficher_sudoku.h"

void afficher_sudoku(int** sudoku) {
    for (int a = 0 ; a<9 ; a++){              //On affiche chaque élément de chaque ligne en sachant qu'il y a 9 éléments par ligne et 9 lignes au total
        for (int i=0 ; i<9 ; i++){
            printf("%d ",sudoku[a][i]);
        }
        printf("\n");
    }
}

