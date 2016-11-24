#include <stdio.h>
#include "circonference.h"
#include "surface.h"

int main(){
	int rayon;
	rayon = 10;
	
	printf("surface = %f\n", surface(rayon));
	printf("circonference = %f\n", circonferece(rayon));
	return 0;
}
