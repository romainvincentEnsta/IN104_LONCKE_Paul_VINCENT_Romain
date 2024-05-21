#include <stdio.h>
#include "structures.h"
#include "get_arrow.h"
#include <stdlib.h>

void char_input(char* x){
    scanf("%c", x);
    while (getchar() != '\n'); // Cette ligne permet de lire le buffer, jusqu'à retombe sur le retour à ligne, 
    //et on vide ainsi le buffer
}

void get_arrow(pac_man_t* pac_man){
    char new;
    printf("Dans quelle direction voulez vous bouger le pacman ? \n Ecrire : \n U pour Up \n D pour Down \n L pour Left \n R pour right\n");
    char_input(&new);
    while ((new!='L') && (new!='R') && (new!='U') && (new!='D')){
        printf("La valeur donnée n'est pas valide. Veuillez bien la remplir avec cette configuartion\n Ecrire : \n U pour Up \n D pour Down \n L pour Left \n R pour right\n");
        char_input(&new);
    }
    if (new=='L'){
        pac_man->nx=0;
        pac_man->ny=-1;
    }
    if (new=='R'){
        pac_man->nx=0;
        pac_man->ny=1;
    }
    if (new=='U'){
        pac_man->nx=-1;
        pac_man->ny=0;
    }
    if (new=='D'){
        pac_man->nx=1;
        pac_man->ny=0;
    }
}