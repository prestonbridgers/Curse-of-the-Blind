#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "menus.h"

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
	mvwprintw(menu_win, 1, 1, "Menu:"); mvwprintw(menu_win, 2, 1, "1) Help");
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

char *load_text(char *filename)
{
	FILE *f = fopen(filename, "r");
	int c_count = 0;
	char *data;
	char c;

	while ((c = fgetc(f)) != EOF)
			c_count++;
	rewind(f);

	data = malloc(sizeof(char) * c_count);

	int i = 0;
	while ((c = fgetc(f)) != EOF)
	{
		if (c == '\n')
			data[i++] = ' ';
		else
			data[i++] = c;
	}

	fclose(f);
	return data;
}

void menus_display_note(char *filename)
{
	WINDOW *win;
	int win_height;
	int win_width = 52;
	int win_startx;
	int win_starty;
	char *msg = load_text(filename);
	int len = 0;
	char c;

	while ((c = msg[++len]) != '\0')
		continue;

	win_height = len / win_width + 3;
	win_startx = (COLS - win_width) / 2;
	win_starty = (LINES - win_height) / 2;

	win = newwin(win_height, win_width, win_starty, win_startx);

	box(win, 0, 0);
	// TODO: Each line there is a 7 char offset for some reason.
	for (int i = 1; i < win_height - 1; i++)
	{
		for (int j = 1; j < win_width - 1; j++)
		{
			int msg_i = (i - 1) * win_height + (j - 1);
			if (msg_i < len)
				mvwaddch(win, i, j, msg[msg_i]);
		}
	}

	wrefresh(win);
	refresh();
	delwin(win);
}
