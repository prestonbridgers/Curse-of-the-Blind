#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include "player.h"

struct GAME
{
	struct MAP_WIN *map_win;
	struct PLAYER *plr;
	int is_running;
};

#endif
