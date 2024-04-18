#include <stdio.h>
#include "tableau_plein.h"

int tableau_plein(int* tab){
    for (int i=0 ; i<9 ; i++){
        if (tab[i]==0){
            return 1;
        }
    }
    return 0;
}