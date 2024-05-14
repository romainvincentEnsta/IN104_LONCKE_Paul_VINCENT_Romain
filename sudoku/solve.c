#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "safe.h"
#include "solve.h"
#include "remplir_case.h"
#include "grille_pleine.h"
#include "tableau_nul.h"

bool sudoku_solve(int** grille){
<<<<<<< HEAD
    int ligne = 0;
    int colonne = 0;
    int valeur=0;
    if (!grille_pleine(grille)){
        printf("grille non pleine\n");
            while (grille[ligne][colonne]!=0){
=======
    srand(time(0));  //On l'utilise pour avoir un nombre aléatoire différent à chaque partie
    int ligne = 0;
    int colonne = 0;
    int valeur=0;
    if (grille_pleine(grille)){                  //Tant que la grille n'est pas pleine on veut la remplir
            while (grille[ligne][colonne]!=0){   //On tire un coéfficient au hasard
>>>>>>> a625a7a3da9adc9b270970c4dc5716b93cd3c8e1
                ligne=rand()%(9);
                colonne=rand()%(9);
        }
        int* mémoire;                            //On garde en mémoire les valeurs déjà assignées dans ce tableau
        mémoire=malloc(9*sizeof(int));
        for(int j=0 ; j<9 ; j++){                //On l'initialise à zéro
            mémoire[j]=0;
        }
        for (int i=0;  i<=8 ; i++){                   //On teste quels nombres ont été tirés et on remplit le tableau mémoire
            if (safe(grille, ligne,colonne,i+1)){
                mémoire[i]=1;
                printf("case safe\n");
            }
            else{
                mémoire[i]=0;   
            }
        }
<<<<<<< HEAD
        if(!tableau_nul(mémoire)){
            printf("tableau non nul\n");
            valeur=rand()%(9)+1;
            while(!remplir_case(valeur,mémoire)){
                valeur=rand()%(9)+1;
            }
            grille[ligne][colonne]=valeur;
=======
        valeur = remplir_case(valeur, mémoire);   //On assigne une valeur disponible dans le tableau mémoire
        if (valeur!=0){
            grille[ligne][colonne]=valeur;  //On néttoie la mémoire
>>>>>>> a625a7a3da9adc9b270970c4dc5716b93cd3c8e1
            free(mémoire);
            return sudoku_solve(grille);
        }
        else {
        free(mémoire);
        return false;
        }
    }
    else {
        return true;
    }
}
