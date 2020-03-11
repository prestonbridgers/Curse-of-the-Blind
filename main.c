#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ncurses.h>
#include <unistd.h>

#include "player.h"
#include "event_handler.h"
#include "map.h"
#include "event.h"
#include "menus.h"
#include "game.h"

// Function prototypes
void event_handle(struct GAME *g, char input);

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
	struct GAME *game = malloc(sizeof(struct GAME));
	game->map_win = map_newwin("maps/map.txt");
	game->plr = player_create(1, 1);
	game->is_running = 1;
	map_show(game->map_win, game->plr);

	// GAME LOOP
	char in;
	while (game->is_running)
	{
		in = getch();
		EH_handle_event(game, in);

		map_show(game->map_win, game->plr);
	}

	// Free memory and cleanup
	map_destroy(game->map_win);
	endwin();
	return 0;
}

