#ifndef UTIL_H_INCLUDED
#define UTIL_H_INCLUDED

struct VECTOR2
{
	int x;
	int y;
};

struct VECTOR2 util_v2_NW(struct VECTOR2 v);
struct VECTOR2 util_v2_N(struct VECTOR2 v);
struct VECTOR2 util_v2_NE(struct VECTOR2 v);

struct VECTOR2 util_v2_E(struct VECTOR2 v);
struct VECTOR2 util_v2_W(struct VECTOR2 v);

struct VECTOR2 util_v2_SW(struct VECTOR2 v);
struct VECTOR2 util_v2_S(struct VECTOR2 v);
struct VECTOR2 util_v2_SE(struct VECTOR2 v);

#endif
