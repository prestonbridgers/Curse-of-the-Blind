#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ncurses.h>
#include <unistd.h>

#include "core_structs.h"
#include "enemy.h"
#include "map.h"
#include "menus.h"
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

	// Vars
	GAME *game = malloc(sizeof(GAME));
	game->map_win = map_newwin(MAP_PATH);
	game->plr = player_create(player, 10, 10);

	game->map_win->map->ent_list[0] = game->plr;
	game->map_win->map->num_entities++;

	game->is_running = 1;

	// Creating entities
	enemy_create(5, 5, game->map_win->map); 
	enemy_create(10, 14, game->map_win->map); 
	enemy_create(5, 6, game->map_win->map); 
	enemy_create(17, 15, game->map_win->map); 
	map_debug_print_ents(game->map_win->map);

	map_show(game->map_win, game->plr);

	// DEBUG: Testing a_star pathfinding
	int **navmap = map_gen_navmap(game->map_win->map);
	for (int i = 0; i < game->map_win->map->height; i++)
	{
		for (int j = 0; j < game->map_win->map->width; j++)
		{
			fprintf(stderr, "%d ", navmap[i][j]);
		}
		fprintf(stderr, "\n");
	}

	// GAME LOOP
	char in;
	while (game->is_running)
	{
		if ((in = getch()) == 'q')
			game->is_running = 0;
		else
			event_handle(game, in);

		map_show(game->map_win, game->plr);

		refresh();
	}

	// Free memory and cleanup
	map_destroy(game->map_win);
	endwin();
	return 0;
}

void event_handle(GAME *g, char input)
{
	int y = g->plr->y;
	int x = g->plr->x;

	switch (input)
	{
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
