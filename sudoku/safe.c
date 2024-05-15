#include <stdio.h>
#include <stdbool.h>
#include "safe.h"

bool safe(int** grille, int ligne, int colonne, int valeur){
    for (int l=0 ; l<8 ; l++){//On parcourt la ligne de la case (ligne,colonne)
        if(grille[ligne][l]==valeur){
            return false;
        }
    }
    for(int k=0; k<=8 ; k++){
        if (grille[k][colonne]==valeur){//On parcourt la colonne de la case (ligne,colonne)
            return false;
        }
    }
    int quotient_l=ligne/3;
    int quotient_c=colonne/3;
    for(int m=0 ; m<=2 ; m++){
        for(int n=0 ; n<=2 ; n++){
            if ((grille[quotient_l*3+m][quotient_c*3+n]==valeur) && ( m!=ligne%3) && (n!=colonne%3)){/* On parcourt la celulle
                de la case (ligne,colonne), en prenant le quotient de ligne et colonne pour obtenir l'indice de la cellule
                puis on parcourt la cellule en question*/
                return false;
            }
        }
    }
    return true;
}
