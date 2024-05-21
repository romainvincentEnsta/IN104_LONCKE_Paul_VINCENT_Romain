#include <stdio.h>
#include "structures.h"
#include "initialisation.h"
#include "move_ghost.h"
#include "is_still_alive.h"
#include "move_pacman.h"
#include "get_arrow.h"
#include <stdlib.h>
#include <stdbool.h>
#include "time.h"


int main(){
    srand(time(0));
    int compteur_food=0;
    ghost_t* all_ghosts=malloc(sizeof(ghost_t)*NB_GHOSTS);
    pac_man_t pac_man;
    (pac_man.coords).x=1;
    (pac_man.coords).y=1;
    pac_man.lives=3;
    pac_man.food=0;
    pac_man.nx=0;
    pac_man.ny=0;
    char zone_jeu[H][W]= {
        { "############################################################" },
        { "#                                                          #" },
        { "#                                                          #" },
        { "#        # # # # #          #             # # # # # #      #" },
        { "#        #       #         # #            #                #" },
        { "#        #       #        #   #           #                #" },
        { "#        # # # # #       #     #          #                #" },
        { "#        #              # # # # #         #                #" },
        { "#        #             #         #        #                #" },
        { "#        #            #           #       #                #" },
        { "#        #           #             #      #                #" },
        { "#        #          #               #     # # # # # #      #" },
        { "#                                                          #" },
        { "#                                                          #" },
        { "#                                                          #" },
        { "#        ##        ##           #          ##        #     #" },
        { "#        # #      # #          # #         # #       #     #" },
        { "#        #  #    #  #         #   #        #  #      #     #" },
        { "#        #    # #   #        #     #       #   #     #     #" },
        { "#        #     #    #       # # # # #      #    #    #     #" },
        { "#        #          #      #         #     #     #   #     #" },
        { "#        #          #     #           #    #      #  #     #" },
        { "#        #          #    #             #   #       # #     #" },
        { "#        #          #   #               #  #        ##     #" },
        { "#                                                          #" },
        { "#                                                          #" },
        { "#                                                          #" },
        { "#                                                          #" },
        { "#                                                          #" },
        { "############################################################" }
    };
    zone_jeu[pac_man.coords.x][pac_man.coords.y]='P';
    int* pt_ou_pas_pt=malloc(sizeof(int)*NB_GHOSTS);
    for (int i=0 ; i<NB_GHOSTS ; i++){
        pt_ou_pas_pt[i]=0;
    }
    initialisation(all_ghosts, zone_jeu,compteur_food);
    for (int i=0 ; i<H ; i++){
        for (int j=0 ; j<W ; j++){
            printf("%c",zone_jeu[i][j]);
        }
        printf("\n");
    }
    while((pac_man.lives>0) || (pac_man.food<compteur_food)){
        pt_ou_pas_pt=move_ghost(zone_jeu,all_ghosts,pt_ou_pas_pt);
        move_pacman(zone_jeu,&pac_man);
        is_still_alive(&pac_man,zone_jeu);
    }
    if (pac_man.lives>0){
        printf("Bravo tu as gagné !!!!!");
    }
    free(pt_ou_pas_pt);
    free(all_ghosts);
}

