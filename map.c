#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include "map.h"

struct map *map_load(char *filename)
{
	struct player *local_player;
	struct map *local_map = malloc(sizeof(struct map));
	local_map->height = 0;
	local_map->width = 0;

	FILE *map_fd = fopen(filename, "r");
	char c;

	while ((c = fgetc(map_fd)) != '\n')
		local_map->width++;
	rewind(map_fd);
	while ((c = fgetc(map_fd)) != EOF)
		if (c == '\n')
			local_map->height++;
	rewind(map_fd);

	local_map->data = malloc(sizeof(char*) * local_map->height);
	for (int i = 0; i < local_map->height; i++)
		local_map->data[i] = malloc(sizeof(char) * local_map->width);

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

	// Finding the location of the player symbol
	for (int i = 0; i < local_map->height; i++)
		for (int j = 0; j < local_map->width; j++)
			if (local_map->data[i][j] == '@')
				local_player = player_create("TEMP", i, j);
	local_map->pc = local_player;

	fclose(map_fd);
	return local_map;
}

void map_destroy(struct map *local_map)
{

}

WINDOW *map_newwin(struct map *local_map, int starty, int startx)
{
	WINDOW *local_win = newwin(local_map->height + 2, local_map->width + 2, starty, startx);

	box(local_win, 0, 0);
	for (int i = 0; i < local_map->height; i++)
	{
		for (int j = 0; j < local_map->width; j++)
		{
			mvwaddch(local_win, i + 1, j + 1, local_map->data[i][j]);
		}
	}
	wrefresh(local_win);
	return local_win;
}
