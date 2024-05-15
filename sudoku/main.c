#include <stdio.h>
#include "safe.h"
#include "afficher_sudoku.h"
#include "solve.h"
#include "sudoku.h"
#include <time.h>
#include <stdbool.h>
#include <stdlib.h>
#include "grille_pleine.h"

#define r 9
#define c 9

int main(){
    int** grille = creation_grille();  //On initialise une grille vide
    sudoku_solve(grille);              //On la résout
    //On enlève des nombres au hasard
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (rand() % 10 < 3)
                grille[i][j] = 0;
        }
    }

    afficher_sudoku(grille);            //On l'affiche

    int a, b, num;
    while (1) {
        printf("Enter the row and column to update: ");
        scanf("%d %d", &a, &b);
        a--;
        b--;

        printf("Enter the new number: ");
        scanf("%d", &num);

        if (num == 0) {
            if (grille[a][b] == 0)
                printf("This cell is already empty.\n");
            else {
                grille[a][b] = 0;
                afficher_sudoku(grille);
            }
        } else {
            if (grille[a][b] == num) {
                afficher_sudoku(grille);
            } else {
                if (safe(grille,a,b,num)) {
                    grille[a][b] = num;
                    afficher_sudoku(grille);
                } else {
                    printf("This number cannot be placed here.\n");
                }
            }
        }
    }

    if (grille_pleine(grille)) {
        printf("Bravo !\n");
        for (int i = 0;i<9;i++) {      //On vide la mémoire
            free(grille[i]);
        }
    free(grille);
    }

    return 0;
}

