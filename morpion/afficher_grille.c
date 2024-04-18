#include <stdio.h>
#include "afficher_grille.h"

void afficher_grille(int* grille){
    printf("|");
    for (int i=0 ; i<9 ; i++){
        if (i/3==0){
            if(grille[i]==-1){
                printf(". ");
            }
            else if (grille[i]==1){
                printf("x ");
            }
            else if (grille[i]==2){
                printf("o ");
            }
            if (i==2){
                printf("|\n");
            }
        }
        else if(i/3==1){
            if (i==3){
                printf("|");
            }
            if(grille[i]==-1){
                printf(". ");
            }
            else if (grille[i]==1){
                printf("x ");
            }
            else if (grille[i]==2){
                printf("o ");
            }
            if (i==5){
                printf("|\n");
            }
        }
        else if(i/3==2){
            if (i==6){
                printf("|");
            }            
            if(grille[i]==-1){
                printf(". ");
            }
            else if (grille[i]==1){
                printf("x ");
            }
            else if (grille[i]==2){
                printf("o ");
            }
            if (i==8){
                printf("|\n");
            }
        }
    }
}
