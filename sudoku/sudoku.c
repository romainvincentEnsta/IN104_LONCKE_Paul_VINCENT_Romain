#include <stdio.h>
#include <stdlib.h>
#include "sudoku.h"

#define r 9
#define c 9

int** creation_grille(int longueur, int largeur) {
    int sudoku[longueur][largeur];
    int cell_1[9] = {0,0,0,0,0,0,0,0,0};
    int cell_2[9] = {0,0,0,0,0,0,0,0,0};
    int cell_3[9] = {0,0,0,0,0,0,0,0,0};
    
    for (int i = 0;i<3;++i) {
        for (int j = 0;j<3;++j) {
            int a = rand()%(r);
            while (cell_1[a] == 1) {
                a = rand()%(r);
            }
            sudoku[i][j]=a+1;
            cell_1[a] = 1;
        }
    }

    for (int i = 3;i<6;++i) {
        for (int j = 3;j<6;++j) {
            int a = rand()%(r);
            while (cell_2[a] == 1) {
                a = rand()%(r);
            }
            sudoku[i][j]=a+1;
            cell_2[a] = 1;
        }
    }

    for (int i = 6;i<9;++i) {
        for (int j = 6;j<9;++j) {
            int a = rand()%(r);
            while (cell_3[a] == 1) {
                a = rand()%(r);
            }
            sudoku[i][j]=a+1;
            cell_3[a] = 1;
        }
    }
    return sudoku;
}

int main() {
    return 0;
}