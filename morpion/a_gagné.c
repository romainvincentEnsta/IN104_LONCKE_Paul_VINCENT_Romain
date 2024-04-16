#include <stido.h>
#include "a_gagné.h"

int a_gagne(int* grille, int joueur){
    int gagne = 0;
    int test = 0;
    // horizontal
    for (int i=0 ; i<3 ; i++){
        test=1;
        for (int j=0 ; j<3 ; j++){
            if ((grille[3*i+j])!=joueur){
                test=0;
            }
        }
        gagne = gagne || test;
    }
    // vertical
    for( int i=0 ; i<3 ; i++){
        test=1;
        for (int j=0 ; j<3  ; j++){
            if ((grille[i+3*j])!=joueur){
                test=0;
            }
        }
        gagne = gagne || test;
    }
    // diagonal
    test=1;
    for (int i=0 ; i<3 ; i++){
        if ((grille[3*i+i])!=joueur){
            test=0;
        }
    }
    gagne = gagne || test;
    // anti-diagonal
    test=1;
    for (int i=0 ; i<3 ; i++){
        if ((grille[3*(2-i)+i])!=joueur){
            test=0;
        }
    }
    gagne = gagne || test;
    return gagne;
}

int est_plein(int* grille){
    for(int i =0 ; i<9 ; i++){
        if (grille[i]==-1){
            return 0;
        }
    }
    return 1;
}

int main(){
    return 0;
}