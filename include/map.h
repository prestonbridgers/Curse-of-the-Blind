#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED

#include "core_structs.h"

MAP_WIN *map_newwin(char *map_path);
void map_destroy(MAP_WIN *mw);
void map_show(MAP_WIN *mw);
int **map_gen_navmap(MAP *m);
void map_debug_print_ents(MAP *m);

#endif
