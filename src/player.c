#include <stdlib.h>
#include "player.h"

/*
 *
 * Creates a player data structure
 * given initial xy coordinates.
 *
 */
struct PLAYER *player_create(int y, int x)
{
	struct PLAYER *local_player = malloc(sizeof(struct PLAYER));
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
void player_destroy(struct PLAYER *local_player)
{
	free(local_player);
}

void player_move(struct PLAYER *p, struct MAP *m, struct VECTOR2 (*move_func)(struct VECTOR2))
{
	struct VECTOR2 loc = (struct VECTOR2) {p->x, p->y};
	struct VECTOR2 dest = move_func(loc);

	if (m->data[dest.y][dest.x] != '#')
	{
		p->y = dest.y;
		p->x = dest.x;
	}
}

