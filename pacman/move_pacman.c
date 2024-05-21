#include <stdio.h>
#include "structures.h"
#include "move_pacman.h"
#include "get_arrow.h"

void move_pacman(char zone_jeu[H][W], pac_man_t* pac_man){
    zone_jeu[(pac_man->coords).x][(pac_man->coords).y]=' ';
    get_arrow(pac_man);
    if ((zone_jeu[(pac_man->coords).x+pac_man->nx][(pac_man->coords).y+pac_man->ny]=='#') || (zone_jeu[(pac_man->coords).x+pac_man->nx][(pac_man->coords).y+pac_man->ny]=='G')){
        pac_man->lives=pac_man->lives-1;
        printf("Tu as perdu une vie, ton nombre de vie restant est : %d\n",pac_man->lives);
        zone_jeu[1][1]='P';
        (pac_man->coords).x=1;
        (pac_man->coords).y=1;
    }
    else {
        if (zone_jeu[(pac_man->coords).x+pac_man->nx][(pac_man->coords).y+pac_man->ny]=='.'){
            pac_man->food=pac_man->food+1;
        }
        zone_jeu[(pac_man->coords).x+pac_man->nx][(pac_man->coords).y+pac_man->ny]='P';
        (pac_man->coords).x=(pac_man->coords).x+pac_man->nx;
        (pac_man->coords).y=(pac_man->coords).y+pac_man->ny;
    }
}
