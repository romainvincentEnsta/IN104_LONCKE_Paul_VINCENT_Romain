#include <stdio.h>
#include "afficher_sudoku.h"

void afficher_sudoku(int** sudoku) {
    for (int a = 0 ; a<9 ; a++){
        for (int i=0 ; i<9 ; i++){
            printf("%d ",sudoku[a][i]);
        }
        printf("\n");
    }
}

