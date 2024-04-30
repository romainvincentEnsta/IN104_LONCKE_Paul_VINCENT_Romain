#include <stdio.h>
#include <stdlib.h>
#include "a_gagné.h"
#include "afficher_grille.h"
#include "creation_grille.h"
#include "est_plein.h"
#include "placer.h"

//Ce fichier est le main.c classique.

void number_input(int* x){
    scanf("%d", x);
    while (getchar() != '\n'); // Cette ligne permet de lire le buffer, jusqu'à retombe sur le retour à ligne, 
    //et on vide ainsi le buffer
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
        number_input(&case_1);
        triche_1=placer(grille,case_1-1,1);
        while (!triche_1){// dans le cas où la valeur donné par l'utilisateur n'est pas bonne, on lui demande de remettre une valeur.
            printf("Wohhh tu crois tricher comme ça\n");
            printf("Quelle est le numéro de la case dans laquelle le joueur n°1 veux jouer ?\n");
            int num;
            number_input(&num);
            //printf("ke vais demander de scanner");
            triche_1=placer(grille,num-1,1);
        }
        gagné = a_gagne(grille,1) || a_gagne(grille,2) || est_plein(grille);//soit l'un des joueurs a gagné après ce move, soit il  y a match nul.
        if (gagné){
            break;
        }
        afficher_grille(grille);
        printf("Quelle est le numéro de la case dans laquelle le joueur n°2 veux jouer ?\n");
        number_input(&case_2);
        triche_2=placer(grille,case_2-1,2);
        while (!triche_2){
            afficher_grille(grille);
            printf("Wohhh tu crois tricher comme ça\n");
            printf("Quelle est le numéro de la case dans laquelle le joueur n°2 veux jouer ?\n");
            number_input(&case_2);
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
