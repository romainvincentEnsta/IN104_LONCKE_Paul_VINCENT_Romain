#include <stdio.h>
#include <stdlib.h>
#include "structures.h"
#include "move_ghost.h"

int* move_ghost(char zone_jeu[H][W], ghost_t* all_ghost, int* pt_ou_pas_pt){
    for (int i=0 ; i<NB_GHOSTS ; i++){
        int nx=rand()%2;
        int ny=rand()%2;
        int dir_x=rand()%2;
        int dir_y=rand()%2;
        if (dir_x%2==1){
            nx=-nx;
        }
        if (dir_y%2==1){
            ny=-ny;
        }
        while ((zone_jeu[(all_ghost[i].coords).x+nx][(all_ghost[i].coords).y+ny]=='#') || ((zone_jeu[(all_ghost[i].coords).x+nx][(all_ghost[i].coords).y+ny]=='P')) || ((zone_jeu[(all_ghost[i].coords).x+nx][(all_ghost[i].coords).y+ny]=='G'))){
            nx=rand()%2;
            ny=rand()%2;
            dir_x=rand()%2;
            dir_y=rand()%2;
            if (dir_x%2==1){
                nx=-nx;
            }
            if (dir_y%2==1){
                ny=-ny;
            }
        }
        if (pt_ou_pas_pt[i]==0){
            zone_jeu[(all_ghost[i].coords).x][(all_ghost[i].coords).y]='.';
        }
        else {
            zone_jeu[(all_ghost[i].coords).x][(all_ghost[i].coords).y]=' ';
        }
        if (zone_jeu[(all_ghost[i].coords).x+nx][(all_ghost[i].coords).y+ny]=='.'){
            pt_ou_pas_pt[i]=0;
            zone_jeu[(all_ghost[i].coords).x+nx][(all_ghost[i].coords).y+ny]='G';
            (all_ghost[i].coords).x=(all_ghost[i].coords).x+nx;
            (all_ghost[i].coords).y=(all_ghost[i].coords).y+ny;
        }
        else{
            pt_ou_pas_pt[i]=1;
            zone_jeu[(all_ghost[i].coords).x+nx][(all_ghost[i].coords).y+ny]='G';
            (all_ghost[i].coords).x=(all_ghost[i].coords).x+nx;
            (all_ghost[i].coords).y=(all_ghost[i].coords).y+ny;
        }
    }
    return pt_ou_pas_pt;
}
