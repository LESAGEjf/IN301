#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

int main() {
	unsigned long int i;
	struct timeval tv1,tv2;
	double date1, date2, duree;
#define N 1048576
	char buf[N];
	
	FILE *F = fopen("fic.test","w");

	gettimeofday(&tv1, NULL);
	date1 = 1e6*tv1.tv_sec + tv1.tv_usec;

//	setvbuf(F, buf, _IOFBF, N);    // écrit dans le fichier quand le buffer est plein
	setvbuf(F, buf, _IOLBF, N);    // écrit dans le fichier ligne par ligne
//	setvbuf(F, buf, _IONBF, 0);    // écrit dans le fichier à chaque fois

	for( i=0 ; i<1e5 ; i++) {
		fprintf(F," %lu", i);
		if (i%1000==0) fprintf(F,"\n");
		if (i%10000==0) printf("%lu/10\n",i/10000);
	}
	fflush(F);

	gettimeofday(&tv2, NULL);  
	date2 = 1e6*tv2.tv_sec + tv2.tv_usec;
	duree = (date2 - date1)*1e-6;

	fclose(F);

printf("_IOFBF = %d\n",_IOFBF);
printf("_IOLBF = %d\n",_IOLBF);
printf("_IONBF = %d\n",_IONBF);
	printf("Durée = %f s\n", duree);
	return 0;
}
