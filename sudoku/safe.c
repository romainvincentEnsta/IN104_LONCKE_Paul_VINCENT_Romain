#include <stdio.h>
#include <stdbool.h>

bool safe(int** grille, int ligne, int colonne, int valeur){
    for (int ligne=0 ; ligne<=8 ; ligne++ ){
        for (int colonne=0 ; colonne<=8 ; colonne++){
            for (int l=0 ; l<8 ; l++){
                if(grille[ligne][l]==valeur){
                    return false;
                }
                else{
                    for(int k=0; k<=8 ; k++){
                        if (grille[k][colonne]==valeur){
                            return false;
                        }
                        else {
                            int quotient_l=ligne/3;
                            int quotient_c=colonne/3;
                            for(int m=0 ; m<=2 ; m++){
                                for(int n=0 ; n<=2 ; n++){
                                    if (grille[quotient_l*3+m][quotient_c*3+n]==valeur){
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
        }
    }
}