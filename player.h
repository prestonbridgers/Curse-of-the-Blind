#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include "game.h"

struct PLAYER
{
	int x;
	int y;
};

struct PLAYER *player_create(int y, int x);
void player_destroy(struct PLAYER *local_player);
void player_event(struct GAME *g, char c);

#endif
