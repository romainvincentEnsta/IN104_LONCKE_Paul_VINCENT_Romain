#include <stdio.h>
#include "structures.h"
#include "initialisation.h"
#include <stdbool.h>
#include <stdlib.h>


bool initialisation(ghost_t* all_ghosts,char zone_jeu[H][W], int compteur_food){
    for (int i = 0; i<NB_GHOSTS ; i++){
    int x=1;
    int y=1;
    while((zone_jeu[x][y]!=' ') || ( (x==1) && (y==1) )){
        x=rand()%H;
        y=rand()%W;
    }
    all_ghosts[i].coords.x=x;
    all_ghosts[i].coords.y=y;
    zone_jeu[x][y]='G';
    }
    for (int i=0 ; i<H ; i++){
        for (int j=0; j<W ; j++){
            if (zone_jeu[i][j]==' '){
                zone_jeu[i][j]='.';
                compteur_food++;
            }
        }
    }
    return true;
}
