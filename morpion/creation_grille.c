#include <stdio.h>
#include <stdlib.h>
#include "creation_grille.h"

int* creation_grille(){
    int* grille=malloc(sizeof(int)*9);
    for (int i=0 ; i<9 ; i++){
        grille[i]=-1;
    }
    return grille;
}
