#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ncurses.h>
#include <unistd.h>

#include "player.h"
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
	game->is_running = 1;
	map_show(game->map_win);

	// GAME LOOP
	char in;
	while (game->is_running)
	{
		if ((in = getch()) == 'q')
			game->is_running = 0;
		else if (in == 'm')
			menu_screen();
		else
			event_handle(game, in);

		map_show(game->map_win);
	}

	// Free memory and cleanup
	map_destroy(game->map_win);
	endwin();
	return 0;
}

void event_handle(struct GAME *g, char input)
{
	int y = g->map_win->map->pc->y;
	int x = g->map_win->map->pc->x;

	switch (input)
	{
		case 'k': // up
			if (y - 1 < 0) break;
			else if (g->map_win->map->data[y - 1][x] == '#') break;
			else if (g->map_win->map->data[y - 1][x] == 'T') menus_display_note("tapes/note.txt");
			else g->map_win->map->pc->y--;
			break;
		case 'j': // down
			if (y + 1 > g->map_win->map->height - 1) break;
			else if (g->map_win->map->data[y + 1][x] == '#') break;
			else if (g->map_win->map->data[y + 1][x] == 'T') menus_display_note("tapes/note.txt");
			else g->map_win->map->pc->y++;
			break;
		case 'h': // left
			if (x - 1 < 0) break;
			else if (g->map_win->map->data[y][x - 1] == '#') break;
			else if (g->map_win->map->data[y][x - 1] == 'T') menus_display_note("tapes/note.txt");
			else g->map_win->map->pc->x--;
			break;
		case 'l': // right
			if (x + 1 > g->map_win->map->width - 1) break;
			else if (g->map_win->map->data[y][x + 1] == '#') break;
			else if (g->map_win->map->data[y][x + 1] == 'T') menus_display_note("tapes/note.txt");
			else g->map_win->map->pc->x++;
			break;
		case 'y': // up-left
			if (x - 1 < 0 && y - 1 < 0) break;
			else if (g->map_win->map->data[y - 1][x - 1] == '#') break;
			else if (g->map_win->map->data[y - 1][x - 1] == 'T') menus_display_note("tapes/note.txt");
			else 
			{
				g->map_win->map->pc->x--;
				g->map_win->map->pc->y--;
			}
			break;
		case 'u': // up-right
			if (x + 1 < 0 && y - 1 < 0) break;
			else if (g->map_win->map->data[y - 1][x + 1] == '#') break;
			else if (g->map_win->map->data[y - 1][x + 1] == 'T') menus_display_note("tapes/note.txt");
			else 
			{
				g->map_win->map->pc->x++;
				g->map_win->map->pc->y--;
			}
			break;
		case 'b': // down-left
			if (x - 1 < 0 && y + 1 < 0) break;
			else if (g->map_win->map->data[y + 1][x - 1] == '#') break;
			else if (g->map_win->map->data[y + 1][x - 1] == 'T') menus_display_note("tapes/note.txt");
			else 
			{
				g->map_win->map->pc->x--;
				g->map_win->map->pc->y++;
			}
			break;
		case 'n': // down-right
			if (x + 1 < 0 && y + 1 < 0) break;
			else if (g->map_win->map->data[y + 1][x + 1] == '#') break;
			else if (g->map_win->map->data[y + 1][x + 1] == 'T') menus_display_note("tapes/note.txt");
			else 
			{
				g->map_win->map->pc->x++;
				g->map_win->map->pc->y++;
			}
			break;
	}
}
