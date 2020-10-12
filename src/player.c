#include "player.h"
#include <stdlib.h>

/*
 * Creates a player data structure
 * given initial xy coordinates.
 *
 */
PLAYER *player_create(enum ENTITY uid, int x, int y)
{
	PLAYER *local_player = malloc(sizeof(PLAYER));
	local_player->uid = uid;
	local_player->x = x;
	local_player->y = y;
	local_player->is_passable = 0;
	local_player->hp = 10;
	return local_player;
}

/*
 *
 * Frees memory associated with given
 * player data structure.
 *
 */
void player_destroy(PLAYER *plr)
{
	free(plr);
}

void player_move(PLAYER *p, MAP *m, VECTOR2 (*move_func)(VECTOR2))
{
	VECTOR2 loc = (VECTOR2) {p->x, p->y};
	VECTOR2 dest = move_func(loc);
	int encountered_entity = 0;

	ENTITY_TYPER *ent;
	for (int i = 1; i < m->num_ents; i++)
	{
		ent = (ENTITY_TYPER*) m->ent_list[i];
		if (dest.x == ent->x && dest.y == ent->y) // Player will run into this entity
		{
			encountered_entity = 1;
			fprintf(stderr, "Player interacting with entity #%d\n", i);
			if (ent->is_passable)
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
                case player:
                    break;
                default:
                    break;
			}	
		}
	}

    // IF: No enemy encountered and destination is not a wall tile
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
