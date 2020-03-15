#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED

#include "core_structs.h"

MAP_WIN *map_newwin(char *filename);
void map_destroy(MAP_WIN *mw);
void map_show(MAP_WIN *mw, PLAYER *plr);
int **map_gen_navmap(MAP *map);

#endif
