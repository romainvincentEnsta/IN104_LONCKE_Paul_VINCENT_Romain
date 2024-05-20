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
        x=rand()%H;// on crée des valeurs aléatoires de coordonnées pour le i-ème fantôme
        y=rand()%W;
    }
    all_ghosts[i].coords.x=x;
    all_ghosts[i].coords.y=y;
    zone_jeu[x][y]='G';
    }
    for (int i=0 ; i<H ; i++){
        for (int j=0; j<W ; j++){
            if (zone_jeu[i][j]==' '){
                zone_jeu[i][j]='.';//on met ici de la nourriture partout il n'y a pas de mur/fantomes/pacman
                compteur_food++;
            }
        }
    }
    return true;
}
