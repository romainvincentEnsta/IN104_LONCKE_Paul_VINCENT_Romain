#include <stdio.h>
#include "placer.h"

int placer (int* grille, int chiffre, int joueur){
    if (chiffre>8 ){
        printf("Wesh grosse erreur chifregrille\n");
        return 0;
    }
    if (joueur>2) {
        printf("Wesh grosse erreurchiffre chiffe\n");
        return 0;
    }
     if(grille[chiffre]!=-1){
        printf("Wesh grosse erreur grille[chiffre\n");
        return 0;
     }

    else {
        grille[chiffre]= joueur;
        return 1;
    }
}
