CC=gcc
CFLAGS=-I$(IDIR) -L$(LDIR)

IDIR=../include
LDIR=../lib
ODIR=./obj

LIBS=-lncurses -la_star

_OBJ = player.o map.o menus.o util.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.c
	$(CC) -c -o $@ $^ $(CFLAGS)

curse: $(OBJ)
	$(CC) -o $@ $^ main.c $(CFLAGS) $(LIBS)

.PHONY: clean run

run:
	./curse 2> ../errlog.txt

clean:
	rm $(ODIR)/*.o
