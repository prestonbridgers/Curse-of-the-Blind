default: player.o map.o event.o
	gcc event.o player.o map.o main.c -lncurses

player.o: player.c
map.o: map.c
event.o: event.c

clean:
	rm *.o a.out
