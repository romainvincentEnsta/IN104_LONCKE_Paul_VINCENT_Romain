#include <stdio.h>
#include <stdlib.h>
#include "sudoku.h"
#include <time.h>

#define r 9
#define c 9


int** creation_grille() {
    srand(time(0));   //On souhaite des nombres aléatoires différents à chaque utilisation
    int** sudoku;
    sudoku = (int**)malloc(sizeof(int*)*r);   //On initialise la grille de sudoku
    for (int i = 0;i<9;++i) {
        sudoku[i] = malloc(sizeof(int)*c);    
    }

    int cell_1[9] = {0,0,0,0,0,0,0,0,0};  //On va retenir les nombres que l'ont a assigné dans chaque carré de la diagonale
    int cell_2[9] = {0,0,0,0,0,0,0,0,0};  //Pour cela on génère trois tableau qui vont nous permettre de retenir les numéros déjà placés
    int cell_3[9] = {0,0,0,0,0,0,0,0,0};  //Au ieme indice correspond un booléen qui nous dit si le chiffre entre 1 et 9 a été tiré
    
    for (int i = 0;i<3;++i) {      //On remplit les tableaux cell en tirant des nombres aléatoires
        for (int j = 0;j<3;++j) {  //1er carré
            int a = rand()%(r);
            while (cell_1[a] == 1) {
                a = rand()%(r);
            }
            sudoku[i][j]=a+1;
            cell_1[a] = 1;
        }
    }

    for (int i = 3;i<6;++i) {  //2e carré
        for (int j = 3;j<6;++j) {
            int a = rand()%(r);
            while (cell_2[a] == 1) {
                a = rand()%(r);
            }
            sudoku[i][j]=a+1;
            cell_2[a] = 1;
        }
    }

    for (int i = 6;i<9;++i) {  //3e carré
        for (int j = 6;j<9;++j) {
            int a = rand()%(r);
            while (cell_3[a] == 1) {
                a = rand()%(r);
            }
            sudoku[i][j]=a+1;
            cell_3[a] = 1;
        }
    }
    return sudoku;    //On renvoit la grille ainsi préparée
}
