#include "player.h"
#include <stdlib.h>

/*
 *
 * Creates a player data structure
 * given initial xy coordinates.
 *
 */
PLAYER *player_create(enum ENTITY uid, int y, int x)
{
	PLAYER *local_player = malloc(sizeof(PLAYER));
	local_player->uid = uid;
	local_player->x = x;
	local_player->y = y;
	return local_player;
}

/*
 *
 * Frees memory associated with given
 * player data structure.
 *
 */
void player_destroy(PLAYER *local_player)
{
	free(local_player);
}

void player_move(PLAYER *p, MAP *m, VECTOR2 (*move_func)(VECTOR2))
{
	VECTOR2 loc = (VECTOR2) {p->x, p->y};
	VECTOR2 dest = move_func(loc);

	if (m->data[dest.y][dest.x] != '#')
	{
		p->y = dest.y;
		p->x = dest.x;
	}
}

