CC=gcc
CFLAGS= -c -I$(IDIR)

IDIR=../include
LDIR=../lib
ODIR=./obj

LIBS= -L$(LDIR) -lncurses -la_star

_DEPS= player.h map.h menus.h util.h core_structs.h enemy.h cotb.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = player.o map.o menus.o util.o main.o enemy.o cotb.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) $< $(CFLAGS) -o $@

curse: $(OBJ)
	$(CC) $(OBJ) $(LIBS) -o $@ 

.PHONY: clean run

run:
	./curse ../maps/map-1.txt 2> ../errlog.txt

clean:
	rm $(ODIR)/*.o
