#include "map.h"

#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>

/*
 *
 * Loads a map from a given file. Assumes the existence of a player tile '@'
 * in the given map.
 *
 */
MAP *map_load(char *filename)
{

	// Vars
	MAP *local_map = malloc(sizeof(MAP));
	local_map->height = 0;
	local_map->width = 0;
	FILE *map_fd = fopen(filename, "r");
	char c;

	// Get the width and height of the map
	while ((c = fgetc(map_fd)) != '\n')
		local_map->width++;
	rewind(map_fd);
	while ((c = fgetc(map_fd)) != EOF)
		if (c == '\n')
			local_map->height++;
	rewind(map_fd);

	// Allocate memory to the data array of local_map
	local_map->data = malloc(sizeof(char*) * local_map->height);
	for (int i = 0; i < local_map->height; i++)
		local_map->data[i] = malloc(sizeof(char) * local_map->width);

	// Read map file data into the local_map data array
	int i = 0;
	int j = 0;
	while ((c = fgetc(map_fd)) != EOF)
	{
		if (c == '\n')
		{
			i++;
			continue;
		}

		local_map->data[i][j % local_map->width] = c;
		j++;
	}

	// Always close files
	fclose(map_fd);
	return local_map;
}

/*
 *
 * Frees memory associated with given map data structure.
 *
 */
void map_destroy(MAP_WIN *mw)
{
	free(mw->map);
	delwin(mw->win);
	free(mw);
}

int **map_gen_navmap(MAP *m)
{

	int **navmap = calloc(m->height, sizeof(int*));
	for (int i = 0; i < m->height; i++)
	{
		navmap[i] = calloc(m->width, sizeof(int));
		for (int j = 0; j < m->width; j++)
		{
			switch (m->data[i][j])
			{
				case '.':
				case '+':
					navmap[i][j] = 0;
					break;
				default:
					navmap[i][j] = 1;
					break;
			}
		}
	}

	return navmap;
}

/*
 *
 * nCurses wrapper function to create a new window in
 * association with a given map.
 *
 */
MAP_WIN *map_newwin(char *filename)
{
	MAP_WIN *local_mapwin = malloc(sizeof(MAP_WIN));
	MAP *local_map = map_load(filename);

	int starty = (LINES - local_map->height) / 2;
	int startx = (COLS - local_map->width) / 2;
	WINDOW *local_win = newwin(local_map->height + 2, local_map->width + 2, starty, startx);

	local_mapwin->map = local_map;
	local_mapwin->win = local_win;

	return local_mapwin;
}

void map_show(MAP_WIN *mw, PLAYER *plr)
{
	box(mw->win, 0, 0);
	for (int i = 0; i < mw->map->height; i++)
	{
		for (int j = 0; j < mw->map->width; j++)
		{
			mvwaddch(mw->win, i + 1, j + 1, ' '); // Clearing the screen
		}
	}
	wrefresh(mw->win);

	for (int i = 0; i < mw->map->height; i++)
	{
		for (int j = 0; j < mw->map->width; j++)
		{
			mvwaddch(mw->win, i, j, mw->map->data[i][j]); // Top-left
			if (i == plr->y && j == plr->x)
				mvwaddch(mw->win, i, j, '@'); // Top-left
				


//			if (i == plr->y && j == plr->x)
//			{
//				mvwaddch(mw->win, i, j, mw->map->data[i - 1][j - 1]); // Top-left
//				mvwaddch(mw->win, i, j + 1, mw->map->data[i - 1][j]); // Top-middle
//				mvwaddch(mw->win, i, j + 2, mw->map->data[i - 1][j + 1]); // Top-right
//
//				
//				mvwaddch(mw->win, i + 1, j, mw->map->data[i][j - 1]); // Middle-left
//				mvwaddch(mw->win, i + 1, j + 1, '@'); // Character
//				mvwaddch(mw->win, i + 1, j + 2, mw->map->data[i][j + 1]); // Middle-right
//
//				mvwaddch(mw->win, i + 2, j, mw->map->data[i + 1][j - 1]); // Bot-left
//				mvwaddch(mw->win, i + 2, j + 1, mw->map->data[i + 1][j]); // Bot-middle
//				mvwaddch(mw->win, i + 2, j + 2, mw->map->data[i + 1][j + 1]); // Bot-right
//			}
		}
	}
	wrefresh(mw->win);
}
