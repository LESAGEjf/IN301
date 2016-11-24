#include <stdio.h>
#include <stdlib.h>
#include <time.h>




int main( int argc, char** argv){
	int i;
	float somme = 0;
	
	for(i=0; i<argc; i++){
		printf("%s\n", argv[i]);
		somme = atof(argv[i]);
		printf("%f\n", somme);
	}
	
		
	return 0;
}
