#include <stdio.h>
#include "placer.c"

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

int main(){
    return 0;
}