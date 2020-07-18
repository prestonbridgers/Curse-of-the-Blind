#include "cotb.h"

#include <stdio.h>
#include <ncurses.h>
>>>>>>> dev

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
>>>>>>> dev

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
