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

