#Makefile du Projet SOKOBAN

CFLAGS=-Wall

all: sokoban
	./sokoban

sokoban: sokoban.o SOKOBANconstantes.o SOKOBANcase.o SOKOBANinterface.o SOKOBANinitialise.o SOKOBANaffiche.o sasquatch1.xsb
	gcc -o sokoban sokoban.o SOKOBANconstantes.o SOKOBANcase.o SOKOBANinterface.o SOKOBANaffiche.o SOKOBANinitialise.o -luvsqgraphics `sdl-config --libs` -lm -lSDL_ttf


sokoban.o: sokoban.c SOKOBANconstantes.h SOKOBANcase.c SOKOBANinterface.h SOKOBANinitialise.h SOKOBANaffiche.h
	gcc $(CFLAGS) sokoban.c


SOKOBANconstantes.o: SOKOBANconstantes.h
	gcc $(CFLAGS) SOKOBANconstantes.h

SOKOBANcase.o: SOKOBANcase.c SOKOBANconstantes.h
	gcc $(CFLAGS) SOKOBANcase.c

SOKOBANinterface.o: SOKOBANinterface.c SOKOBANinterface.h SOKOBANcase.c SOKOBANconstantes.h
	gcc $(CFLAGS) SOKOBANinterface.c

SOKOBANinitialise.o: SOKOBANinitialise.c SOKOBANinitialise.h SOKOBANconstantes.h SOKOBANcase.c
	gcc $(CFLAGS) SOKOBANinitialise.c

SOKOBANaffichage.o: SOKOBANaffiche.c SOKOBANaffiche.h SOKOBANconstantes.h SOKOBANcase.c SOKOBANinterface.h
	gcc $(CFLAGS) SOKOBANaffichage.c


clean:
	rm -f sokoban
	rm -f sokoban.o
	rm -f SOKOBANconstantes.o
	rm -f SOKOBANcase.o
	rm -f SOKOBANinterface.o
	rm -f SOKOBANinitialise.o
	rm -f SOKOBANaffichage.o
