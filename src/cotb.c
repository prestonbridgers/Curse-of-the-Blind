#include "cotb.h"

#include <stdlib.h>

GAME *cotb_init(const char *map_path)
{
	// nCurses Initialization
	initscr();
	curs_set(0);
	raw();
	keypad(stdscr, TRUE);
	noecho();
	refresh();

	// Initializing the GAME
	GAME *game = malloc(sizeof(GAME));
	game->map_win = map_newwin(map_path);
	game->plr = player_create(player, 1, 1);
	game->is_running = 1;

	// Adding player to the map's entity list
	game ->map_win->map->ent_list[0] = game->plr;

	return game;
}

void event_handle(GAME *g, char input)
{
	switch (input)
	{
		case 'q': // quit
			g->is_running = 0;
			break;
		case 'k': // up
			player_move(g->plr, g->map_win->map, util_v2_N);
			break;
		case 'j': // down
			player_move(g->plr, g->map_win->map, util_v2_S);
			break;
		case 'h': // left
			player_move(g->plr, g->map_win->map, util_v2_W);
			break;
		case 'l': // right
			player_move(g->plr, g->map_win->map, util_v2_E);
			break;
		case 'y': // up-left
			player_move(g->plr, g->map_win->map, util_v2_NW);
			break;
		case 'u': // up-right
			player_move(g->plr, g->map_win->map, util_v2_NE);
			break;
		case 'b': // down-left
			player_move(g->plr, g->map_win->map, util_v2_SW);
			break;
		case 'n': // down-right
			player_move(g->plr, g->map_win->map, util_v2_SE);
			break;
	}
}
