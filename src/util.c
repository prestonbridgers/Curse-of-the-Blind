#include <stdio.h>
#include <string.h>

#include "util.h"
#include "cotb.h"

void util_update_hp_bar(GAME *g)
{
	int starty = (LINES - g->map_win->map->height) / 2;
	int startx = (COLS - g->map_win->map->width) / 2;
    char *hp_title = "HP[";

    WINDOW *win = newwin(3, 13 + strlen(hp_title), starty - 3, startx);
    box(win, 0, 0);

    mvwaddstr(win, 1, 1, hp_title);

    for (int i = 0; i < g->plr->hp; i++)
    {
        mvwaddch(win, 1, 1 + strlen(hp_title) + i, '-');
    }
    mvwaddch(win, 1, 1 + strlen(hp_title) + 10, ']');

    wrefresh(win);
}

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

