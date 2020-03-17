#ifndef ENEMY_H_INCLUDED
#define ENEMY_H_INCLUDED

#include "core_structs.h"

void enemy_create(int x, int y, MAP *m);
void enemy_destroy(ENEMY *e);
void enemy_move_toward(ENEMY *e, int **navmap, PLAYER *p, MAP *m);

#endif
