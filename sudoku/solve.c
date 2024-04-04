#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "safe.h"
#include "solve.h"

int remplir_case(int valeur, int* mémoire){
    valeur=rand()%(9);
    for (int j =0 ; j<=8 ; j++){
        if (mémoire[j]==0){
            if (mémoire[valeur-1]==1){
                remplir_case(valeur,mémoire);
            }
            else{
                return valeur;
            }
        }
        else {
            return 0;
        }
    }
}


bool sudoku_solve(int** grille){
    int ligne = 0;
    int colonne = 0;
    int valeur=0;
    for(int a=0; a<=9 ; a++){
        for(int b=0 ; b<=9 ; b++){
            if (grille[a][b]==0){
                    while (grille[ligne][colonne]!=0){
                    ligne=rand()%(9);
                    colonne=rand()%(9);
                }
                int mémoire[9];
                for (int i=0;  i<=8 ; i++){
                    if (safe(grille, ligne,colonne,i+1)){
                        mémoire[i]=0;
                    }
                    else{
                        mémoire[i]=1;
                    }
                }
                valeur = remplir_case(valeur, mémoire);
                if (valeur!=0){
                    grille[ligne][colonne]=valeur;
                    sudoku_solve(grille);
                }
                else {
                    return false;
                }
            }
        else {
            return true;
            }
        }
    }
}


int main() {
    return 0;
}