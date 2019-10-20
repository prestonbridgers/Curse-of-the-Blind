#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ncurses.h>

#include "player.h"
#include "map.h"

void menu_screen();
void refresh_stat(WINDOW *local_win, int local_h, int local_w);

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

	mvprintw(0, 0, "@x: %d\t@y: %d", m->pc->xpos, m->pc->ypos);

	int stat_height = 4;
	int stat_width = 61;
	int stat_startx = map_startx;
	int stat_starty = map_starty - stat_height;
	WINDOW *stat_win = newwin(stat_height, stat_width, stat_starty, stat_startx);
	refresh_stat(stat_win, stat_height, stat_width);

	char in;
	while (game_running)
	{
		in = getch();

		switch (in)
		{
			case 'm': //Menu
				menu_screen();
				break;
			case 'q': //Quit
				game_running = 0;
				break;
		}

		refresh_stat(stat_win, stat_height, stat_width);
	}

	delwin(map_win);
	endwin();
	return 0;
}

void menu_screen()
{
	int in;
	int menu_height = 10;
	int menu_width = 10;
	int menu_startx = (COLS - menu_height) / 2;
	int menu_starty = (LINES - menu_width) / 2;
	WINDOW *menu_win;

	menu_win = newwin(menu_height, menu_width, menu_starty, menu_startx);
	box(menu_win, 0, 0);

	mvwprintw(menu_win, 1, 1, "Menu:");
	mvwprintw(menu_win, 2, 1, "1) Help");
	mvwprintw(menu_win, 3, 1, "2) Quit");
	wrefresh(menu_win);

	while ((in = getch()) != '2')
	{
		switch (in)
		{
			case '1':
				mvprintw(0, 0, "You need help. . . I don't konw what to tell ya.");
				refresh();
				break;
		}
	}

	delwin(menu_win);
}

void refresh_stat(WINDOW *local_win, int local_h, int local_w)
{
	box(local_win, 0, 0);
	mvwprintw(local_win, 1, 1, "Player: {name} the {class?}\t\tatk: {attack stat}");
	mvwprintw(local_win, 2, 1, "Race: {race?}\t\t\t\tdef: {defense stat}");
	wrefresh(local_win);
}	
