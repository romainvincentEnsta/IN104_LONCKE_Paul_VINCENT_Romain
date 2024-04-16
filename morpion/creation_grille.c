#include <stdio.h>
#include "creation_grille.h"

int* creation_grille(){
    int* grille=malloc(sizeof(int)*9);
    for (int i=0 ; i<9 ; i++){
        grille[i]=-1;
    }
    return grille;
}

int main(){
    return 0;
}