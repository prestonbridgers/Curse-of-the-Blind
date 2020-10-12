#ifndef COTB_H_INCLUDED
#define COTB_H_INCLUDED

#include "core_structs.h"
#include "enemy.h"
#include "map.h"
#include "player.h"
#include "util.h"

#include "a_star.h"

GAME *cotb_init(const char *map_path);

#endif
