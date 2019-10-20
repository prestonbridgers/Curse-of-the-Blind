#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ncurses.h>

#include "player.h"
#include "map.h"
#include "event.h"

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

// Function prototypes
void menu_screen();
void refresh_stat(WINDOW *local_win, int local_h, int local_w);

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
	short game_running = 1;

	struct map *m = map_load("map.txt");
	int map_starty = (LINES - m->height) / 2;
	int map_startx = (COLS - m->width) / 2;
	WINDOW *map_win = map_newwin(m, map_starty, map_startx);

	int stat_height = 4;
	int stat_width = 61;
	int stat_startx = map_startx;
	int stat_starty = map_starty - stat_height;
	WINDOW *stat_win = newwin(stat_height, stat_width, stat_starty, stat_startx);
	refresh_stat(stat_win, stat_height, stat_width);

	// GAME LOOP
	char in;
	while (game_running)
	{
		if ((in = getch()) == 'q')
			break;
		else if (in == 'm')
			menu_screen();
		event_handle(m, in);

		// TODO: Get all this into a single update() function
		map_update(m, map_win);
		refresh_stat(stat_win, stat_height, stat_width);
	}

	// Free memory and cleanup
	map_destroy(m);
	delwin(map_win);
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
void menu_screen()
{
	// Vars
	int in;
	int menu_height = 10;
	int menu_width = 10;
	int menu_startx = (COLS - menu_height) / 2;
	int menu_starty = (LINES - menu_width) / 2;
	WINDOW *menu_win = newwin(menu_height, menu_width, menu_starty, menu_startx);

	// Writing things onto menu
	box(menu_win, 0, 0);
	mvwprintw(menu_win, 1, 1, "Menu:");
	mvwprintw(menu_win, 2, 1, "1) Help");
	mvwprintw(menu_win, 3, 1, "2) Quit");
	wrefresh(menu_win);

	// Menu screen input loop
	while ((in = getch()) != '2')
	{
		char help_msg[] = "You need help. . . I don't know what to tell ya.";
		switch (in)
		{
			case '1':
				mvprintw(LINES - 1, (COLS - strlen(help_msg)) / 2, help_msg);
				refresh();
				break;
		}
	}

	// Rip window after we're done.
	delwin(menu_win);
}

/*
 *
 * This is a function that I need to tuck
 * away in its own source file with many other
 * utility functions to update/redraw windows.
 * I plan on having one big update() function
 * call to wrap all the redraw functions into.
 * It's here for now though, so I get to look
 * at it in all of its glory.
 *
 */
void refresh_stat(WINDOW *local_win, int local_h, int local_w)
{
	box(local_win, 0, 0);
	mvwprintw(local_win, 1, 1, "Player: {name} the {class?}\t\tatk: {attack stat}");
	mvwprintw(local_win, 2, 1, "Race: {race?}\t\t\t\tdef: {defense stat}");
	wrefresh(local_win);
}	
