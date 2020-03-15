#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include "game.h"
#include "util.h"
#include "map.h"

struct PLAYER
{
	int x;
	int y;
};

struct PLAYER *player_create(int y, int x);
void player_destroy(struct PLAYER *local_player);
void player_move(struct PLAYER *p, struct MAP *m, struct VECTOR2 (*move_func)(struct VECTOR2));

#endif
