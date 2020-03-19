#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ncurses.h>
#include <unistd.h>

#include "core_structs.h"
#include "enemy.h"
#include "map.h"
#include "player.h"
#include "enemy.h"

#include "a_star.h"

#define MAP_PATH "../maps/map.txt"

// Function prototypes
void event_handle(GAME *g, char input);

/*
 *
 */
int main(int argc, char *argv[])
{
	// Curses Initialization
	initscr();
	curs_set(0);
	raw();
	keypad(stdscr, TRUE);
	noecho();
	refresh();

	// Instantiating the game
	GAME *game = malloc(sizeof(GAME));
	game->map_win = map_newwin(MAP_PATH);
	game->plr = player_create(player, 19, 35);
	game->is_running = 1;

	// Putting the player into the map's entity list
	game->map_win->map->ent_list[0] = game->plr;
	game->map_win->map->num_entities++;

	// Creating entities
	enemy_create(5, 5, game->map_win->map); 
	enemy_create(1, 7, game->map_win->map); 
	enemy_create(5, 18, game->map_win->map); 
	enemy_create(18, 5, game->map_win->map); 
	map_debug_print_ents(game->map_win->map);

	// GAME LOOP
	char in;
	do
	{
		map_show(game->map_win);
		in = getch();
		event_handle(game, in);

		if (game->plr->hp <= 0)
			game->is_running = 0;

	} while (game->is_running);

	// Free memory and cleanup
	map_destroy(game->map_win);
	endwin();
	return 0;
}

void event_handle(GAME *g, char input)
{
	switch (input)
	{
		case 'q':
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
