#include <stdio.h>
#include "structures.h"
#include "is_still_alive.h"

void is_still_alive(pac_man_t* pac_man, char zone_jeu[H][W]){
    if (pac_man->lives<=0){
        printf("C'est fini voilà votre score : %d",pac_man->food);
    }
    else {
        for (int i=0 ; i<H ; i++){
            for (int j=0 ; j<W ; j++){
                printf("%c",zone_jeu[i][j]);
            }
            printf("\n");
        }
    }
}