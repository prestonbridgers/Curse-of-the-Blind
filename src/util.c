#include <stdio.h>

#include "util.h"

struct VECTOR2 util_v2_NW(struct VECTOR2 v)
{
	return (struct VECTOR2) {v.x - 1, v.y - 1};
}

struct VECTOR2 util_v2_N(struct VECTOR2 v)
{
	return (struct VECTOR2) {v.x, v.y - 1};
}

struct VECTOR2 util_v2_NE(struct VECTOR2 v)
{
	return (struct VECTOR2) {v.x + 1, v.y - 1};
}

struct VECTOR2 util_v2_E(struct VECTOR2 v)
{
	return (struct VECTOR2) {v.x + 1, v.y};
}

struct VECTOR2 util_v2_W(struct VECTOR2 v)
{
	return (struct VECTOR2) {v.x - 1, v.y};
}

struct VECTOR2 util_v2_SW(struct VECTOR2 v)
{
	return (struct VECTOR2) {v.x - 1, v.y + 1};
}

struct VECTOR2 util_v2_S(struct VECTOR2 v)
{
	return (struct VECTOR2) {v.x, v.y + 1};
}

struct VECTOR2 util_v2_SE(struct VECTOR2 v)
{
	return (struct VECTOR2) {v.x + 1, v.y + 1};
}

