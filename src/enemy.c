#include <stdio.h>
#include <stdlib.h>

#include "core_structs.h"
#include "enemy.h"

#include "a_star.h"

void enemy_create(int x, int y, MAP *m)
{
	ENEMY *e = calloc(1, sizeof(ENEMY*));
	e->uid = enemy;
	e->x = x;
	e->y = y;
	e->is_passable = 0;
	e->atk = 1;

	m->ent_list[m->num_ents++] = e;
}

void enemy_destroy(ENEMY *e)
{
	free(e);
}

void enemy_move_toward(ENEMY *e, int **navmap, PLAYER *p, MAP *m)
{
	int **path = ASTAR_get_path(navmap, m->height, m->width,
										 e->x, e->y, p->x, p->y);
	e->x = path[0][0];
	e->y = path[0][1];
	for (int i = 0; i < m->height * m->width; i++)
		free(path[i]);
	free(path);
}


