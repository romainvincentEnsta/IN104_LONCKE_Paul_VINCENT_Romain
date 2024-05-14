#include <stdio.h>
#include <stdlib.h>
#include "creation_grille.h"

// Le but de cette fonction est tout simplement de créer la grille de morpion sous la forme d'un tableau de longueur 9.

int* creation_grille(){
    int* grille=malloc(sizeof(int)*9);
    for (int i=0 ; i<9 ; i++){
        grille[i]=-1;
    }
    return grille;
}
