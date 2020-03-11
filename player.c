#include <stdlib.h>
#include "player.h"
#include "map.h"

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

void player_map_move_NW(struct PLAYER *plr, struct MAP *map)
{
	if (plr->x - 1 < 0 && plr->y - 1 < 0) return;
	else if (map->data[plr->y - 1][plr->x - 1] == '#') return;
	else 
	{
		plr->x--;
		plr->y--;
	}
}

void player_map_move_N(struct PLAYER *plr, struct MAP *map)
{
	if (plr->x < 0 && plr->y - 1 < 0) return;
	else if (map->data[plr->y - 1][plr->x] == '#') return;
	else plr->y--;
}

void player_map_move_NE(struct PLAYER *plr, struct MAP *map)
{
	if (plr->x + 1 < 0 && plr->y - 1 < 0) return;
	else if (map->data[plr->y - 1][plr->x + 1] == '#') return;
	else 
	{
		plr->x++;
		plr->y--;
	}
}

void player_map_move_W(struct PLAYER *plr, struct MAP *map)
{
	if (plr->x - 1 < 0 && plr->y < 0) return;
	else if (map->data[plr->y][plr->x - 1] == '#') return;
	else plr->x--;
}

void player_map_move_E(struct PLAYER *plr, struct MAP *map)
{
	if (plr->x + 1 < 0 && plr->y < 0) return;
	else if (map->data[plr->y][plr->x + 1] == '#') return;
	else plr->x++;
}

void player_map_move_SW(struct PLAYER *plr, struct MAP *map)
{
	if (plr->x - 1 < 0 && plr->y + 1 < 0) return;
	else if (map->data[plr->y + 1][plr->x - 1] == '#') return;
	else 
	{
		plr->x--;
		plr->y++;
	}
}

void player_map_move_S(struct PLAYER *plr, struct MAP *map)
{
	if (plr->x < 0 && plr->y + 1 < 0) return;
	else if (map->data[plr->y + 1][plr->x] == '#') return;
	else plr->y++;
}

void player_map_move_SE(struct PLAYER *plr, struct MAP *map)
{
	if (plr->x + 1 < 0 && plr->y + 1 < 0) return;
	else if (map->data[plr->y + 1][plr->x + 1] == '#') return;
	else 
	{
		plr->x++;
		plr->y++;
	}
}

