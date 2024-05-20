#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "solve.h"
#include "remplir_case.h"
#include "grille_pleine.h"
#include "safe.h"

bool sudoku_solve(int** grille){
    int row, col;
    bool isEmpty = false;

    // Rechercher une cellule vide dans la grille
    for (row = 0; row < 9; row++) {
        for (col = 0; col < 9; col++) {
            if (grille[row][col] == 0) {
                isEmpty = true;
                break;
            }
        }
        if (isEmpty) {
            break;
        }
    }

    // Si aucune cellule vide n'est trouvée, la grille est résolue
    if (!isEmpty) {
        return true;
    }

    // Essayer les chiffres de 1 à 9
    for (int num = 1; num <= 9; num++) {
        if (safe(grille, row, col, num)) {
            grille[row][col] = num;

            // Recursion pour continuer avec cette solution partielle
            if (sudoku_solve(grille)) {
                return true;
            }

            // Si la tentative de placer le nombre n'aboutit pas, backtrack
            grille[row][col] = 0;
        }
    }

    return false; // Déclencher un backtracking
}