#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ncurses.h>
#include "player.h"
#include "map.h"
#include "event.h"
#include "menus.h"

//  _      _   _             _                                        
// | | ___| |_( )___   _ __ | | __ _ _   _   ___  ___  _ __ ___   ___ 
// | |/ _ \ __|// __| | '_ \| |/ _` | | | | / __|/ _ \| '_ ` _ \ / _ \
// | |  __/ |_  \__ \ | |_) | | (_| | |_| | \__ \ (_) | | | | | |  __/
// |_|\___|\__| |___/ | .__/|_|\__,_|\__, | |___/\___/|_| |_| |_|\___|
//                    |_|            |___/                            
//   __            _    _                     _     _            
//  / _|_   _  ___| | _(_)_ __   __ _  __   _(_) __| | ___  ___  
// | |_| | | |/ __| |/ / | '_ \ / _` | \ \ / / |/ _` |/ _ \/ _ \
// |  _| |_| | (__|   <| | | | | (_| |  \ V /| | (_| |  __/ (_) |
// |_|  \__,_|\___|_|\_\_|_| |_|\__, |   \_/ |_|\__,_|\___|\___/ 
//                              |___/                            
//                                    _           _     
//   __ _  __ _ _ __ ___   ___  ___  | |__   ___ (_)___ 
//  / _` |/ _` | '_ ` _ \ / _ \/ __| | '_ \ / _ \| / __|
// | (_| | (_| | | | | | |  __/\__ \ | |_) | (_) | \__ \
//  \__, |\__,_|_| |_| |_|\___||___/ |_.__/ \___/|_|___/
//  |___/                                               

struct GAME
{
	struct MAP_WIN *map_win;
	int is_running;
};

// Function prototypes
void event_handle(struct GAME *g, char input);

/*
 *
 * So this is going to be a cluster fuck for now.
 * I apologize in advance for the spaghetti.
 * I really don't know what the fuck is going on;
 * I've yet to decide on how I want to structure
 * everything. Good luck following the code.
 * I'll get around to organizing it and actually
 * making it readable in the future if this
 * project turns out to be something I actually
 * want to finish.
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
	game->map_win = map_newwin("map.txt");
	game->is_running = 1;
	map_show(game->map_win);

	menus_display_note("note.txt");

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

/*
 *
 * This function handles the "menu screen".
 * Idk why this is even a thing that exists.
 * It was really just to show proof of concept
 * that menus are a thing that I can do with
 * this library. I'll probably seperating
 * all the menus and UI stuff into a 
 * seperate source file for the sake
 * of organization.
 *
 */


void event_handle(struct GAME *g, char input)
{
	int y = g->map_win->map->pc->ypos;
	int x = g->map_win->map->pc->xpos;

	switch (input)
	{
		case 'w':
			if (y - 1 < 0) break;
			else if (g->map_win->map->data[y - 1][x] == '#') break;
			else if (g->map_win->map->data[y - 1][x] == 'r') menu_screen();
			else g->map_win->map->pc->ypos--;
			break;
		case 's':
			if (y + 1 > g->map_win->map->height - 1) break;
			else if (g->map_win->map->data[y + 1][x] == '#') break;
			else if (g->map_win->map->data[y + 1][x] == 'r') menu_screen();
			else g->map_win->map->pc->ypos++;
			break;
		case 'a':
			if (x - 1 < 0) break;
			else if (g->map_win->map->data[y][x - 1] == '#') break;
			else if (g->map_win->map->data[y][x - 1] == 'r') menu_screen();
			else g->map_win->map->pc->xpos--;
			break;
		case 'd':
			if (x + 1 > g->map_win->map->width - 1) break;
			else if (g->map_win->map->data[y][x + 1] == '#') break;
			else if (g->map_win->map->data[y][x + 1] == 'r') menu_screen();
			else g->map_win->map->pc->xpos++;
			break;
	}
}
