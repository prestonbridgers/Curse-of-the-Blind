#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "menus.h"

/*
 *
 * Helper function for the display_note function below.
 * Extracts raw text form a file and returns a string
 * containing the text.
 *
 */
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

/*
 *
 * Reads text in from a file and displays it on a window
 * to the user. Waits for a key to be pressed, then deletes
 * the window.
 *
 */
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
	for (int i = 1; i < win_height - 1; i++)
	{
		for (int j = 1; j < win_width - 1; j++)
		{
			int msg_i = (i - 1) * (win_width - 2) + (j - 1);
			if (msg_i < len)
				mvwaddch(win, i, j, msg[msg_i]);
		}
	}

	wrefresh(win);
	getch();
	delwin(win);
}
