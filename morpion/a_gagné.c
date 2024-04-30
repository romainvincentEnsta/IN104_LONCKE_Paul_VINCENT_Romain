#include <stdio.h>
#include "a_gagné.h"

/* Cette fonction permet de vérifier lorsque le joueur représenté par l'unsigned int joueur a gagné. Pour cela on vérifie sur chaque colonne, chaque ligne
, et que la diagonale et l'anti-diagonale si il y a 3 symboles qui se suivent (ou plûtot les nombres associés aux joueurs).*/ 

int a_gagne(int* grille, int joueur){
    int gagne = 0;// l'entier qui sera renvoyé à la fin et qui vaut 0 ou 1.
    int test = 0;
    // horizontal, on teste la victoire sur les lignes.
    for (int i=0 ; i<3 ; i++){//On réalise une boucle sur chacune des lignes
        test=1;
        for (int j=0 ; j<3 ; j++){
            if ((grille[3*i+j])!=joueur){// Si le joueur n'a pas trois symboles sur la ligne, il n'a pas gagné d'où test=0.
                test=0;
            }
        }
        gagne = gagne || test;/*si gagné ou test vaut 1, alors le joueur avait soit déjà gagné sur une autre ligne,
         soit il vient de gagner, dans les deux cas cette expression prends alors bien la valeur 1.*/
    }
    //On réalise la même chose sur les colonnes ou sur la diago, ou anti-diago.
    // vertical, on teste la victoire sur les colonnes.
    for( int i=0 ; i<3 ; i++){
        test=1;
        for (int j=0 ; j<3  ; j++){
            if ((grille[i+3*j])!=joueur){
                test=0;
            }
        }
        gagne = gagne || test;
    }
    // diagonale
    test=1;
    for (int i=0 ; i<3 ; i++){
        if ((grille[3*i+i])!=joueur){
            test=0;
        }
    }
    gagne = gagne || test;
    // anti-diagonale
    test=1;
    for (int i=0 ; i<3 ; i++){
        if ((grille[3*(2-i)+i])!=joueur){
            test=0;
        }
    }
    gagne = gagne || test;
    return gagne;
}
