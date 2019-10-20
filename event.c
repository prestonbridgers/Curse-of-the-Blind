#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>

#include "event.h"

/*
 *
 *	A cool idea for an event handler but it's setup
 *	kinda bad. It can't mutate important game state
 *	like the is_running flag. I could throw all the
 *	game state into a game struct and pass a around
 *	a pointer to it. I may just end up doing that.
 *	TODO: Do the above.
 *
 */
void event_handle(struct map *local_map, char key)
{
	mvprintw(0, 0, "TODO: Make the event handler better!");
}
