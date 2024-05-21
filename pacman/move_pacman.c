#include <stdio.h>
#include "structures.h"
#include "move_pacman.h"
#include "get_arrow.h"

void move_pacman(char zone_jeu[H][W], pac_man_t* pac_man){
    zone_jeu[(pac_man->coords).x][(pac_man->coords).y]=' ';
    get_arrow(pac_man);// Permet de récupérer les coordonnées auprès de l'utilisateur
    if ((zone_jeu[(pac_man->coords).x+pac_man->nx][(pac_man->coords).y+pac_man->ny]=='#') || (zone_jeu[(pac_man->coords).x+pac_man->nx][(pac_man->coords).y+pac_man->ny]=='G')){
        pac_man->lives=pac_man->lives-1;// si pacman rencontre un mur ou un fantome il perd une vie.
        if ((zone_jeu[(pac_man->coords).x+pac_man->nx][(pac_man->coords).y+pac_man->ny]=='G')){
            printf("C'est le cas où pacman va sur G\n");
        }
        printf("Tu as perdu une vie, ton nombre de vie restant est : %d\n",pac_man->lives);
        zone_jeu[1][1]='P';// il est remis aux coords (1,1)
    }
    else {
        if (zone_jeu[(pac_man->coords).x+pac_man->nx][(pac_man->coords).y+pac_man->ny]=='.'){
            pac_man->food=pac_man->food+1;//on vérifie s'il y a de la nourriture.
        }
        zone_jeu[(pac_man->coords).x+pac_man->nx][(pac_man->coords).y+pac_man->ny]='P';
        (pac_man->coords).x=(pac_man->coords).x+pac_man->nx;
        (pac_man->coords).y=(pac_man->coords).y+pac_man->ny;
    }
}
