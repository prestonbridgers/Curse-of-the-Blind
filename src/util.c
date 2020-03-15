#include <stdio.h>

#include "util.h"

VECTOR2 util_v2_NW(VECTOR2 v)
{
	return (VECTOR2) {v.x - 1, v.y - 1};
}

VECTOR2 util_v2_N(VECTOR2 v)
{
	return (VECTOR2) {v.x, v.y - 1};
}

VECTOR2 util_v2_NE(VECTOR2 v)
{
	return (VECTOR2) {v.x + 1, v.y - 1};
}

VECTOR2 util_v2_E(VECTOR2 v)
{
	return (VECTOR2) {v.x + 1, v.y};
}

VECTOR2 util_v2_W(VECTOR2 v)
{
	return (VECTOR2) {v.x - 1, v.y};
}

VECTOR2 util_v2_SW(VECTOR2 v)
{
	return (VECTOR2) {v.x - 1, v.y + 1};
}

VECTOR2 util_v2_S(VECTOR2 v)
{
	return (VECTOR2) {v.x, v.y + 1};
}

VECTOR2 util_v2_SE(VECTOR2 v)
{
	return (VECTOR2) {v.x + 1, v.y + 1};
}

