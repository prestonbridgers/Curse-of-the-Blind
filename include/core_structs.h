#ifndef CORE_STRUCTS_H_INCLUDED
#define CORE_STRUCTS_H_INCLUDED

#include <ncurses.h>

#define CHAR_TILE '@'
#define ENEMY_TILE 'e'
#define GROUND_TILE '.'
#define WALL_TILE '#'
#define DOOR_TILE '+'
#define EMPTY_SPACE_TILE '-'

enum ENTITY
{
	player,
	enemy
};

typedef struct
{
	enum ENTITY uid;
	int is_passable;
	int x;
	int y;
} ENTITY_TYPER;

typedef struct
{ 
	enum ENTITY uid;
	int is_passable;
	int x;
	int y;
	int atk;
} ENEMY;

typedef struct
{
	enum ENTITY uid;
	int is_passable;
	int x;
	int y;
	int hp;
} PLAYER;

typedef struct
{
	char **data;
	int height;
	int width;
	void **ent_list;
	int num_ents;
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
