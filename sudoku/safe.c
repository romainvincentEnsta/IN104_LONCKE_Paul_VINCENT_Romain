#include <stdio.h>
#include <stdbool.h>
#include "safe.h"

bool safe(int** grille, int ligne, int colonne, int valeur){
   // Vérifier la ligne
    for (int x = 0; x < 9; x++) {
        if (grille[ligne][x] == valeur) {
            return false;
        }
    }

    // Vérifier la colonne
    for (int x = 0; x < 9; x++) {
        if (grille[x][colonne] == valeur) {
            return false;
        }
    }

    // Vérifier le sous-carré 3x3
    int startRow = ligne - ligne % 3, startCol = colonne - colonne % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grille[i + startRow][j + startCol] == valeur) {
                return false;
            }
        }
    }

    return true;
}
