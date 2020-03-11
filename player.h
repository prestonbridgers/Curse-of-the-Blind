#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include "game.h"
#include "map.h"

struct PLAYER
{
	int x;
	int y;
};

struct PLAYER *player_create(int y, int x);
void player_destroy(struct PLAYER *local_player);

void player_map_move_NW(struct PLAYER *plr, struct MAP *map);
void player_map_move_N(struct PLAYER *plr, struct MAP *map);
void player_map_move_NE(struct PLAYER *plr, struct MAP *map);
void player_map_move_W(struct PLAYER *plr, struct MAP *map);
void player_map_move_E(struct PLAYER *plr, struct MAP *map);
void player_map_move_SW(struct PLAYER *plr, struct MAP *map);
void player_map_move_S(struct PLAYER *plr, struct MAP *map);
void player_map_move_SE(struct PLAYER *plr, struct MAP *map);

#endif
