#include "core_structs.h"

#ifndef UTIL_H_INCLUDED
#define UTIL_H_INCLUDED

typedef struct
{
	int x;
	int y;
} VECTOR2;

void util_update_hp_bar(GAME *g);

VECTOR2 util_v2_NW(VECTOR2 v);
VECTOR2 util_v2_N(VECTOR2 v);
VECTOR2 util_v2_NE(VECTOR2 v);

VECTOR2 util_v2_E(VECTOR2 v);
VECTOR2 util_v2_W(VECTOR2 v);

VECTOR2 util_v2_SW(VECTOR2 v);
VECTOR2 util_v2_S(VECTOR2 v);
VECTOR2 util_v2_SE(VECTOR2 v);

#endif
