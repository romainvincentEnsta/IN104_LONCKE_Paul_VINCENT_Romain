#include <stdio.h>
#include "placer.h"


//Le but de cette fonction est de placer une valeur donné par un joueur dans la grille, en vérifiant qu'il n'a pas fait d'erreur.
// On utilise des unsigned int pour éviter d'ajouter la condition chiffre (ou joueur) positif.
int placer (int* grille, unsigned int chiffre, unsigned int joueur){
    if (chiffre>8 ){//il faut que la valeur de la case donné soit comprise entre 0 et 8.
        printf("Wesh grosse erreur chifregrille\n");
        return 0;
    }
    if (joueur>2) {//il faut que que le joueur soit compris entre 0 et 1/
        printf("Wesh grosse erreur joueur\n");
        return 0;
    }
     if(grille[chiffre]!=-1){// Si la case de la grille est déjà remplie...
        printf("Wesh grosse erreur grille[chiffre]\n");
        return 0;
     }

    else {
        grille[chiffre]= joueur;
        return 1;
    }
}
