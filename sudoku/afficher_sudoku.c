#include <stdio.h>
#include "afficher_sudoku.h"

void afficher_sudoku(int** sudoku) {
    printf(" -----------------------\n");
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (j % 3 == 0) {
                printf(" |");
            }
            printf(" %d", sudoku[i][j]);
        }
        printf(" |\n");
        if ((i + 1) % 3 == 0) {
            printf(" -----------------------\n");
        }
    }
}

