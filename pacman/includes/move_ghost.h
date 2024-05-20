#ifndef MOVE_GHOST_H
#define MOVE_GHOST_H

#include <stdio.h>
#include "structures.h"

int* move_ghost(char zone_jeu[H][W], ghost_t* all_ghost, int* pt_ou_pas_pt, pac_man_t* pac_man);

#endif