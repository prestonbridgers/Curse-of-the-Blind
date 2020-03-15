CC=gcc
CFLAGS=-I$(IDIR) -L$(LDIR)

IDIR=../include
LDIR=../lib
ODIR=./obj

LIBS=-lncurses -la_star

_DEPS= player.h map.h menus.h util.h core_structs.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = player.o map.o menus.o util.o main.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

curse: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean run

run:
	./curse 2> ../errlog.txt

clean:
	rm $(ODIR)/*.o
