#include <stdio.h>

void afficher_sudoku(int** sudoku) {
    for (int i = 0;i<9;++i) {
        for (int j = 0;j<9;++j) {
            printf("%d ",sudoku[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}