#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include "game.h"

struct player
{
	int xpos;
	int ypos;
	char *name;
};

struct player *player_create(char *local_name, int y, int x);
void player_destroy(struct player *local_player);
void player_event(struct GAME *g, char c);

#endif
