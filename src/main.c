#include "cotb.h"

#include <stdio.h>
#include <ncurses.h>

int main(int argc, char *argv[])
{
	// vars
	GAME *game;

	// Verifying arguments have been passed
	if (argc < 2)
	{
		printf("Usage:\n\t./curse {./map/path}\n");
		exit(1);
	}

	// Initializing CotB
	game = cotb_init(argv[1]);

	// GAME LOOP
	char in;
	do
	{
		map_show(game->map_win);

		in = getch();
		event_handle(game, in);

		if (game->plr->hp <= 0)
			game->is_running = 0;
	} while (game->is_running);

	// Cleanup
	map_destroy(game->map_win);
	endwin();
	return 0;
}

void event_handle(GAME *g, char input)
{
	switch (input)
	{
		case 'q': // quit
			g->is_running = 0;
			break;
		case 'k': // up
			player_move(g->plr, g->map_win->map, util_v2_N);
			break;
		case 'j': // down
			player_move(g->plr, g->map_win->map, util_v2_S);
			break;
		case 'h': // left
			player_move(g->plr, g->map_win->map, util_v2_W);
			break;
		case 'l': // right
			player_move(g->plr, g->map_win->map, util_v2_E);
			break;
		case 'y': // up-left
			player_move(g->plr, g->map_win->map, util_v2_NW);
			break;
		case 'u': // up-right
			player_move(g->plr, g->map_win->map, util_v2_NE);
			break;
		case 'b': // down-left
			player_move(g->plr, g->map_win->map, util_v2_SW);
			break;
		case 'n': // down-right
			player_move(g->plr, g->map_win->map, util_v2_SE);
			break;
	}
}
