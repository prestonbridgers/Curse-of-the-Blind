#ifndef CORE_STRUCTS_H_INCLUDED
#define CORE_STRUCTS_H_INCLUDED

#include <ncurses.h>

typedef struct
{
	int x;
	int y;
} PLAYER;

typedef struct
{
	char **data;
	int height;
	int width;
} MAP;

typedef struct
{
	MAP *map;
	WINDOW *win;
} MAP_WIN;

typedef struct
{
	MAP_WIN *map_win;
	PLAYER *plr;
	int is_running;
} GAME;

#endif
