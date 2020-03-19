#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include "core_structs.h"
#include "util.h"

PLAYER *player_create(enum ENTITY uid, int y, int x);
void player_destroy(PLAYER *local_player);
void player_move(PLAYER *p, MAP *m, VECTOR2 (*move_func)(VECTOR2));
void player_collides_enemy(PLAYER *p, ENTITY_TYPER *ent);

#endif
