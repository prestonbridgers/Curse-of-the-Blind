#include <stdio.h>
#include <stdlib.h>

#include "event_handler.h"
#include "player.h"

int EH_handle_event(struct GAME *g, char input)
{
	switch (input)
	{
		case 'q': // Quit
			g->is_running = 0;
			break;
		case 'k': // up
			player_map_move_N(g->plr, g->map_win->map);
			break;
		case 'j': // down
			player_map_move_S(g->plr, g->map_win->map);
			break;
		case 'h': // left
			player_map_move_W(g->plr, g->map_win->map);
			break;
		case 'l': // right
			player_map_move_E(g->plr, g->map_win->map);
			break;
		case 'y': // up-left
			player_map_move_NW(g->plr, g->map_win->map);
			break;
		case 'u': // up-right
			player_map_move_NE(g->plr, g->map_win->map);
			break;
		case 'b': // down-left
			player_map_move_SW(g->plr, g->map_win->map);
			break;
		case 'n': // down-right
			player_map_move_SE(g->plr, g->map_win->map);
			break;
	}
}
