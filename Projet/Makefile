CFLAGS=-c -g -Wall

all: sokoban
	./sokoban

sokoban: sokoban.o SOKOBANaffichage.o SOKOBANdeplacement.o SOKOBANinterface.o
	gcc -o sokoban sokoban.o SOKOBANaffichage.o SOKOBANdeplacement.o SOKOBANinterface.o -luvsqgraphics `sdl-config --libs` -lm -lSDL_ttf

sokoban.o: sokoban.c sudoku.h SOKOBANconstantes.h lire_ecrire.h
	gcc $(CFLAGS) sudoku.c

affichage.o: affichage.c affichage.h sudoku.h constantes.h
	gcc $(CFLAGS) `sdl-config --cflags` affichage.c

action.o: action.c action.h constantes.h
	gcc $(CFLAGS) `sdl-config --cflags` action.c

lire_ecrire.o: lire_ecrire.c sudoku.h constantes.h
	gcc $(CFLAGS) lire_ecrire.c

clean:
	rm -f sudoku
	rm -f sudoku.o
	rm -f affichage.o
	rm -f action.o

