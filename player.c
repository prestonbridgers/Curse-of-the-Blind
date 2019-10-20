#include <stdlib.h>
#include "player.h"

struct player *player_create(char *local_name, int y, int x)
{
	struct player *local_player = malloc(sizeof(struct player));
	local_player->name = local_name;
	local_player->xpos = x;
	local_player->ypos = y;
	return local_player;
}

void player_destroy(struct player *local_player)
{
	free(local_player);
}
