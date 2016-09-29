#include <stdio.h>
#include <stdlib.h>
#include <time.h>






int main(){

	int i;
	float E, S;
	
	printf("precision ? ");
	scanf("%f", &E);
	
	S = 0.0;
	i = 0;
	while(1.0 / (i*i) > E){
		S += 1.0/(i*i);
		i++;
	}
		printf("la limite est : %f\n", S);
}
