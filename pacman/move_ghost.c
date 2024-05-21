#include <stdio.h>
#include <stdlib.h>
#include "structures.h"
#include "move_ghost.h"
// cette fonction permet de déplacer les fantômes et renvoie un tableau qui indique s'il y avait de la food là où sont les fantômes
int* move_ghost(char zone_jeu[H][W], ghost_t* all_ghost, int* pt_ou_pas_pt,pac_man_t* pac_man){
    for (int i=0 ; i<NB_GHOSTS ; i++){// On crée des directions aléatoires pour le i-ème fantôme
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
        while ((zone_jeu[(all_ghost[i].coords).x+nx][(all_ghost[i].coords).y+ny]=='#') ||  ((zone_jeu[(all_ghost[i].coords).x+nx][(all_ghost[i].coords).y+ny]=='G'))){
            // le while au dessus teste si les directions aléatoires envoie le fantôme sur pacman, un mur, ou un autre fantôme
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
        if (pt_ou_pas_pt[i]==0){//si il y avait un point à l'endroit où est le fantôme, on le remets.
            zone_jeu[(all_ghost[i].coords).x][(all_ghost[i].coords).y]='.';
        }
        else {
            zone_jeu[(all_ghost[i].coords).x][(all_ghost[i].coords).y]=' ';
        }
        if (zone_jeu[(all_ghost[i].coords).x+nx][(all_ghost[i].coords).y+ny]=='.'){//on mets le fantôme au nouvelle coordonnée actualisant la nourriture
            pt_ou_pas_pt[i]=0;
            zone_jeu[(all_ghost[i].coords).x+nx][(all_ghost[i].coords).y+ny]='G';
            (all_ghost[i].coords).x=(all_ghost[i].coords).x+nx;
            (all_ghost[i].coords).y=(all_ghost[i].coords).y+ny;
        }
        else if (zone_jeu[(all_ghost[i].coords).x+nx][(all_ghost[i].coords).y+ny]=='P'){// Si un fantôme arrive sur parcman
            printf("C'est le cas où le fantôme vient sur P\n");
            pt_ou_pas_pt[i]=1;
            zone_jeu[(all_ghost[i].coords).x+nx][(all_ghost[i].coords).y+ny]='G';
            pac_man->lives=pac_man->lives-1;// on fait perdre une vie à pacman
            zone_jeu[1][1]='P';// on remet pacman aux coordonnées 1,1
            (pac_man->coords).x=1;
            (pac_man->coords).y=1;
            printf("Vous avez perdu une vie, il vous en reste : %d\n",pac_man->lives);
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
