#ifndef STRUCTURES_H
#define STRUCTURES_H

#include <stdio.h>

#define H 30
#define W 60
#define NB_GHOSTS 8

typedef struct coordinates {
                int x;
                int y;
}coordinates_t ;

typedef struct pac_man {
                coordinates_t coords;
                int nx;
                int ny;
                int lives;
                int food;
}pac_man_t;

typedef struct ghost {
                coordinates_t coords;
}ghost_t;

#endif
