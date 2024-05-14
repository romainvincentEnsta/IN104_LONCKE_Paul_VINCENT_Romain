#include <stdio.h>
#include <stdbool.h>
#include "tableau_nul.h"

int tableau_nul(int* mémoire){
    for (int i=0 ; i<9 ; i++){
        if (mémoire[i]!=0){
            return true;
        }
    }
    return false;
}