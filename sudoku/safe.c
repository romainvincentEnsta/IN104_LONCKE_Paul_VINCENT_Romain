#include <stdio.h>
#include <stdbool.h>
#include "safe.h"

bool safe(int** grille, int ligne, int colonne, int valeur){
    for (int l=0 ; l<8 ; l++){//On parcourt la ligne de la case (ligne,colonne)
        if(grille[ligne][l]==valeur){
            return false;
        }
        else{
            for(int k=0; k<=8 ; k++){
                if (grille[k][colonne]==valeur){//On parcourt la colonne de la case (ligne,colonne)
                    return false;
                }
                else {
                    int quotient_l=ligne/3;
                    int quotient_c=colonne/3;
                    for(int m=0 ; m<=2 ; m++){
                        for(int n=0 ; n<=2 ; n++){
                            if (grille[quotient_l*3+m][quotient_c*3+n]==valeur){/* On parcourt la celulle
                                de la case (ligne,colonne), enn prenant le quotient de ligne et colonne pour obtenir l'indice de la cellule
                                puis on parcourt la cellule en question*/
                                return false;
                            }
                            else{
                                return true;
                            }
                        }
                    }
                }
            }
        }
    }
    return true;
}

int main() {
    return 0;
}