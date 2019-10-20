#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include "map.h"


/*
 *
 * Loads a map from a given file. Assumes the existence of a player tile '@'
 * in the given map.
 *
 */
struct map *map_load(char *filename)
{

	// Vars
	struct player *local_player;
	struct map *local_map = malloc(sizeof(struct map));
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

	// Finding the location of the player symbol and initializing
	// local_player accordingly.
	for (int i = 0; i < local_map->height; i++)
		for (int j = 0; j < local_map->width; j++)
			if (local_map->data[i][j] == '@')
				local_player = player_create("TEMP", i, j);
	local_map->pc = local_player;

	// Always close files
	fclose(map_fd);
	return local_map;
}

/*
 *
 * Frees memory associated with given map data structure.
 *
 */
void map_destroy(struct map *local_map)
{
	player_destroy(local_map->pc);
	free(local_map);
}

/*
 *
 * nCurses wrapper function to create a new window in
 * association with a given map.
 *
 * If it is assumed that the map window will always be
 * in the center of the screen, starty and startx could
 * be calculated inside of this function. This isn't an
 * assumption I want to make for now.
 *
 */
WINDOW *map_newwin(struct map *local_map, int starty, int startx)
{
	// Making the nCurses window data structure
	WINDOW *local_win = newwin(local_map->height + 2, local_map->width + 2, starty, startx);

	// Drawing the map data to the window.
	box(local_win, 0, 0);
	for (int i = 0; i < local_map->height; i++)
	{
		for (int j = 0; j < local_map->width; j++)
		{
			mvwaddch(local_win, i + 1, j + 1, local_map->data[i][j]);
		}
	}

	// Drawing the window to the screen (not sure if this
	// is the best place for this function call)
	wrefresh(local_win);
	return local_win;
}
