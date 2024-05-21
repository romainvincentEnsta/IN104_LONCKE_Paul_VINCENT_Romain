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
    printf("Dans quelle direction voulez vous bouger le pacman ? \n Ecrire : \n z pour Up \n s pour Down \n q pour Left \n d pour right\n");
    char_input(&new);
    while ((new!='q') && (new!='d') && (new!='z') && (new!='s')){
        printf("La valeur donnée n'est pas valide. Veuillez bien la remplir avec cette configuartion\n Ecrire : \n z pour Up \n s pour Down \n q pour Left \n d pour right\n");
        char_input(&new);
    }
    if (new=='q'){
        pac_man->nx=0;
        pac_man->ny=-1;
    }
    if (new=='d'){
        pac_man->nx=0;
        pac_man->ny=1;
    }
    if (new=='z'){
        pac_man->nx=-1;
        pac_man->ny=0;
    }
    if (new=='s'){
        pac_man->nx=1;
        pac_man->ny=0;
    }
}