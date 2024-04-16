#include <stdio.h>
#include <stdlib.h>
#include "time.h"

int* creation_grille(){
    int* grille=malloc(sizeof(int)*9);
    for (int i=0 ; i<9 ; i++){
        grille[i]=-1;
    }
    return grille;
}

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

int placer (int* grille, int chiffre, int joueur){
    if ((chiffre>8) || (joueur>2) || (grille[chiffre]!=-1)){
        printf("Wesh grosse erreur\n");
        return 0;
    }
    else {
        grille[chiffre]= joueur;
        return 1;
    }
}

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
    int gagné=0;
    int tours =0;
    int* grille= creation_grille();
    while (!gagné){
        afficher_grille(grille);
        int case_1;
        int case_2;
        int triche_1;
        int triche_2;
        printf("Quelle est le numéro de la case dans laquelle le joueur n°1 veux jouer ?\n");
        scanf("%d",&case_1);
        triche_1=placer(grille,case_1-1,1);
        while (!triche_1){
            printf("Wohhh tu crois tricher comme ça\n");
            printf("Quelle est le numéro de la case dans laquelle le joueur n°1 veux jouer ?\n");
            scanf("%d",&case_1);
            triche_1=placer(grille,case_1-1,1);
        }
        gagné = a_gagne(grille,1) || a_gagne(grille,2) || est_plein(grille);
        if (gagné){
            break;
        }
        afficher_grille(grille);
        printf("Quelle est le numéro de la case dans laquelle le joueur n°2 veux jouer ?\n");
        scanf("%d",&case_2);
        triche_2=placer(grille,case_2-1,2);
        while (!triche_2){
            afficher_grille(grille);
            printf("Wohhh tu crois tricher comme ça\n");
            printf("Quelle est le numéro de la case dans laquelle le joueur n°2 veux jouer ?\n");
            scanf("%d",&case_2);
            triche_2=placer(grille,case_2-1,2);
        }
        tours++;
        gagné = a_gagne(grille,1) || a_gagne(grille,2) || est_plein(grille);
        printf("%d\n",gagné);
        }
    if (a_gagne(grille,1)){
        afficher_grille(grille);
        printf("Bravo au joueur n°1\n");
    }
    else if(a_gagne(grille,2)){
        afficher_grille(grille);
        printf("Bravo  au joueur n°2\n");
    }
    else {
        afficher_grille(grille);
        printf("Match nul en %d\n",tours);
    }
    free(grille);
    return 0;
}
