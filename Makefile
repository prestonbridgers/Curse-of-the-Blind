default: player.o map.o
	gcc player.o map.o main.c -lncurses

player.o: player.c
map.o: map.c

clean:
	rm *.o a.out
