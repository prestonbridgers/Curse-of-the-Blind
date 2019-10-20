#include <stdlib.h>
#include "player.h"

/*
 *
 * Creates a player data structure given a
 * name and initial xy coordinates.
 *
 * Name is currently useless, but who cares?
 * Everyone needs a name.
 *
 */
struct player *player_create(char *local_name, int y, int x)
{
	struct player *local_player = malloc(sizeof(struct player));
	local_player->name = local_name;
	local_player->xpos = x;
	local_player->ypos = y;
	return local_player;
}

/*
 *
 * Frees memory associated with given
 * player data structure.
 *
 */
void player_destroy(struct player *local_player)
{
	free(local_player);
}
