all: toto
	

run: toto
	./toto

circonference.o: circonference.c pi.h
	gcc -c circonference.c -Wall

surface.o: surface.c pi.h
	gcc -c surface.c -Wall

principal.o: surface.h circonference.h principal.c
	gcc -c principal.c -Wall
	
toto: surface.o circonference.o principal.o
	gcc principal.o circonference.o surface.o -o toto

clean:
	rm -f *.o
	rm toto
