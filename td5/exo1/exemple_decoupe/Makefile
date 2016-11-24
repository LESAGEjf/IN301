all: plum
	
run: plum
	./plum

ploum.o: ploum.c plim.h plam.h
	gcc -c ploum.c -Wall
	
plam.o: plam.c
	gcc -c plam.c -Wall

plim.o: plim.c
	gcc -c plim.c -Wall

plum: plim.o plam.o ploum.o
	gcc plim.o plam.o ploum.o -o plum
	
clean:
	rm -f *.o
	rm plum
