default: event_handler.o player.o map.o menus.o
	gcc event_handler.o player.o map.o menus.o main.c -lncurses

player.o: player.c
map.o: map.c
menus.o: menus.c
event_handler.o: event_handler.c

clean:
	rm *.o a.out
