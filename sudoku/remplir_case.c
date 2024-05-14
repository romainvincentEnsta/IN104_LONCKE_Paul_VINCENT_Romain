#include <stdio.h>
#include <stdlib.h>
#include "remplir_case.h"
#include <time.h>

int remplir_case(int valeur, int* mémoire){
    if (mémoire[valeur-1]==1){
        return 1;
    }
    else {
        return 0;
    }
}

