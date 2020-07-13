#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>

#include "map.h"
#include "player.h"
#include "enemy.h"

MAP *map_load(char *map_path)
{ 
	// Vars
	MAP *local_map = malloc(sizeof(MAP));
	local_map->height = 0;
	local_map->width = 0;
	local_map->num_ents = 1;
	FILE *map_fd = fopen(map_path, "r");
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
	
	// Allocate memory for the entity list
	local_map->ent_list = calloc(local_map->width * local_map->height, sizeof(void*));

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

		// Checking for entities
		switch (c)
		{
			case CHAR_TILE: // The player
				//TODO
				break;
			case ENEMY_TILE: // The enemies
				enemy_create(j % local_map->width, i, local_map);
				break;
		}

	
		j++;
	}

	fclose(map_fd);
	return local_map;
}

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
				case GROUND_TILE:
				case DOOR_TILE:
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

MAP_WIN *map_newwin(char *map_path)
{
	MAP_WIN *local_mapwin = malloc(sizeof(MAP_WIN));
	MAP *local_map = map_load(map_path);

	int starty = (LINES - local_map->height) / 2;
	int startx = (COLS - local_map->width) / 2;
	WINDOW *local_win = newwin(local_map->height, local_map->width, starty, startx);

	local_mapwin->map = local_map;
	local_mapwin->win = local_win;

	return local_mapwin;
}

void map_show(MAP_WIN *mw)
{
	// Show map data
	for (int i = 0; i < mw->map->height; i++)
		for (int j = 0; j < mw->map->width; j++)
			mvwaddch(mw->win, i, j, mw->map->data[i][j]);

	// Show entities
	for (int i = mw->map->num_ents - 1; i >= 0; i--)
	{
		ENTITY_TYPER *ent = (ENTITY_TYPER*) mw->map->ent_list[i];
		switch (ent->uid)
		{
			case player:
				mvwaddch(mw->win, ent->y, ent->x, CHAR_TILE);
				break;
			case enemy:
				mvwaddch(mw->win, ent->y, ent->x, ENEMY_TILE);
				break;
		}
	}

	wrefresh(mw->win);
}

void map_debug_print_ents(MAP *m)
{
	fprintf(stderr, "PRINTING ENTITY LIST (amount: %d):\n", m->num_ents);
	for (int i = 0; i < m->num_ents; i++)
	{
		ENTITY_TYPER *ent = (ENTITY_TYPER*) m->ent_list[i];
		switch (ent->uid)
		{
			case player:
				fprintf(stderr, "\tEnt #%d: player\n", i);
				break;
			case enemy:
				fprintf(stderr, "\tEnt #%d: enemy\n", i);
				break;
		}
	}
}
