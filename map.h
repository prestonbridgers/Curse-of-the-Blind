#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED

#include <ncurses.h>
#include "player.h"

struct map
{
	char **data;
	int height;
	int width;
	struct player *pc;
};

struct map *map_load(char *filename);
void map_destroy(struct map *local_map);
WINDOW *map_newwin(struct map *local_map, int starty, int startx);

#endif
