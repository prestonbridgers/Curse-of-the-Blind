#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED

#include <ncurses.h>
#include "player.h"

struct MAP
{
	char **data;
	int height;
	int width;
	struct player *pc;
};

struct MAP_WIN
{
	struct MAP *map;
	WINDOW *win;
};

struct MAP_WIN *map_newwin(char *filename);
void map_destroy(struct MAP_WIN *mw);
void map_show(struct MAP_WIN *mw);

#endif
