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
