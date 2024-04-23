#include <stdio.h>
#include "afficher_sudoku.h"

void afficher_sudoku(int** sudoku) {
    /*for (int a=0 ; a<9 ; a++){
        printf("_");
    }
    printf("\n");
    for (int i = 0;i<9;++i) {
        for (int j = 0;j<9;++j) {
            if (j/3==0){
                printf("|");
            }
            printf("%d",sudoku[i][j]);
            if ((i/3==2) && (j==8)){
                for (int b=0 ; b<8 ; b++){
                    printf("_");
                }
            }
        }
        printf("\n");
    }
    for (int a=0 ; a<9 ; a++){
        printf("_");
    }
    printf("\n");*/
    for (int a = 0 ; a<9 ; a++){
        for (int i=0 ; i<9 ; i++){
            printf("%d ",sudoku[a][i]);
        }
        printf("\n");
    }
}

