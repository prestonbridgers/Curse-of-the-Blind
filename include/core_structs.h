#ifndef CORE_STRUCTS_H_INCLUDED
#define CORE_STRUCTS_H_INCLUDED

#include <ncurses.h>

#define CHAR_TILE '@'
#define ENEMY_TILE 'e'
#define GROUND_TILE '.'
#define WALL_TILE '#'
#define DOOR_TILE '+'

enum ENTITY
{
	player,
	enemy
};

typedef struct
{
	enum ENTITY uid;
} ENTITY_TYPER;

typedef struct
{ 
	enum ENTITY uid;
	int x;
	int y;
} ENEMY;

typedef struct
{
	enum ENTITY uid;
	int x;
	int y;
} PLAYER;

typedef struct
{
	char **data;
	int height;
	int width;
	void **ent_list;
	int num_entities;
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
