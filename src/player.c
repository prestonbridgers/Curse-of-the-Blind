#include "player.h"
#include <stdlib.h>

/*
 * * Creates a player data structure
 * given initial xy coordinates.
 *
 */
PLAYER *player_create(enum ENTITY uid, int y, int x)
{
	PLAYER *local_player = malloc(sizeof(PLAYER));
	local_player->uid = uid;
	local_player->x = x;
	local_player->y = y;
	local_player->isPassable = 0;
	local_player->hp = 100;
	return local_player;
}

/*
 *
 * Frees memory associated with given
 * player data structure.
 *
 */
void player_destroy(PLAYER *local_player)
{
	free(local_player);
}

void player_move(PLAYER *p, MAP *m, VECTOR2 (*move_func)(VECTOR2))
{
	VECTOR2 loc = (VECTOR2) {p->x, p->y};
	VECTOR2 dest = move_func(loc);
	int encountered_entity = 0;

	ENTITY_TYPER *ent;
	for (int i = 1; i < m->num_entities; i++)
	{
		ent = (ENTITY_TYPER*) m->ent_list[i];
		if (dest.x == ent->x && dest.y == ent->y) // Player will run into this entity
		{
			encountered_entity = 1;
			fprintf(stderr, "Player interacting with entity #%d\n", i);
			if (ent->isPassable)
			{
				p->y = dest.y;
				p->x = dest.x;
			}

			// Running interact functions
			switch (ent->uid)
			{
				case enemy:
					player_collides_enemy(p, ent);
					break;
			}	
		}
	}

	if (!encountered_entity && m->data[dest.y][dest.x] != WALL_TILE)
	{
		p->y = dest.y;
		p->x = dest.x;
	}
}

void player_collides_enemy(PLAYER *p, ENTITY_TYPER *ent)
{
	ENEMY *e = (ENEMY*) ent;
	p->hp -= e->atk;

	fprintf(stderr, "Player hp: %d\n", p->hp);
}
