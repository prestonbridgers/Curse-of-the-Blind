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

#include "a_star.h"

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
	game->map_win = map_newwin("../maps/map.txt");
	game->plr = player_create(10, 10);
	game->is_running = 1;
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

		//DEBUG: testing a_star pathfinding
		int **path = ASTAR_get_path(navmap, game->map_win->map->height, game->map_win->map->width, game->plr->x, game->plr->y, 15, 15);
		int p_count = 0;
		while (!(path[p_count][0] == END_OF_PATH && path[p_count][1] == END_OF_PATH))
		{
			mvwaddch(game->map_win->win, path[p_count][1], path[p_count][0], '>');
			p_count++;
		}
		wrefresh(game->map_win->win);
		refresh();
	}

	// Free memory and cleanup
	map_destroy(game->map_win);
	endwin();
	return 0;
}

void event_handle(struct GAME *g, char input)
{
	int y = g->plr->y;
	int x = g->plr->x;

	switch (input)
	{
		case 'k': // up
			if (y - 1 < 0) break;
			else if (g->map_win->map->data[y - 1][x] == '#') break;
			else if (g->map_win->map->data[y - 1][x] == 'T') menus_display_note("tapes/note.txt");
			else g->plr->y--;
			break;
		case 'j': // down
			if (y + 1 > g->map_win->map->height - 1) break;
			else if (g->map_win->map->data[y + 1][x] == '#') break;
			else if (g->map_win->map->data[y + 1][x] == 'T') menus_display_note("tapes/note.txt");
			else g->plr->y++;
			break;
		case 'h': // left
			if (x - 1 < 0) break;
			else if (g->map_win->map->data[y][x - 1] == '#') break;
			else if (g->map_win->map->data[y][x - 1] == 'T') menus_display_note("tapes/note.txt");
			else g->plr->x--;
			break;
		case 'l': // right
			if (x + 1 > g->map_win->map->width - 1) break;
			else if (g->map_win->map->data[y][x + 1] == '#') break;
			else if (g->map_win->map->data[y][x + 1] == 'T') menus_display_note("tapes/note.txt");
			else g->plr->x++;
			break;
		case 'y': // up-left
			if (x - 1 < 0 && y - 1 < 0) break;
			else if (g->map_win->map->data[y - 1][x - 1] == '#') break;
			else if (g->map_win->map->data[y - 1][x - 1] == 'T') menus_display_note("tapes/note.txt");
			else 
			{
				g->plr->x--;
				g->plr->y--;
			}
			break;
		case 'u': // up-right
			if (x + 1 < 0 && y - 1 < 0) break;
			else if (g->map_win->map->data[y - 1][x + 1] == '#') break;
			else if (g->map_win->map->data[y - 1][x + 1] == 'T') menus_display_note("tapes/note.txt");
			else 
			{
				g->plr->x++;
				g->plr->y--;
			}
			break;
		case 'b': // down-left
			if (x - 1 < 0 && y + 1 < 0) break;
			else if (g->map_win->map->data[y + 1][x - 1] == '#') break;
			else if (g->map_win->map->data[y + 1][x - 1] == 'T') menus_display_note("tapes/note.txt");
			else 
			{
				g->plr->x--;
				g->plr->y++;
			}
			break;
		case 'n': // down-right
			if (x + 1 < 0 && y + 1 < 0) break;
			else if (g->map_win->map->data[y + 1][x + 1] == '#') break;
			else if (g->map_win->map->data[y + 1][x + 1] == 'T') menus_display_note("tapes/note.txt");
			else 
			{
				g->plr->x++;
				g->plr->y++;
			}
			break;
	}
}
