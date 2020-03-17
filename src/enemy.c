#include <stdio.h>
#include <stdlib.h>

#include "core_structs.h"
#include "enemy.h"

void enemy_create(int x, int y, MAP *m)
{
	ENEMY *e = calloc(1, sizeof(ENEMY*));
	e->uid = enemy;
	e->x = x;
	e->y = y;
	m->ent_list[m->num_entities++] = e;
}

void enemy_destroy(ENEMY *e)
{
	free(e);
}
