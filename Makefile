default: player.o map.o menus.o
	gcc player.o map.o menus.o main.c -lncurses

player.o: player.c
map.o: map.c
menus.o: menus.c

clean:
	rm *.o a.out
