#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int Convertir_Heures(int tps){
	int Heures;
	Heures = tps/3600;
	return Heures;
}

int Convertir_Minutes(int tps){
	int Minutes;
	Minutes = tps/60;
	return Minutes;
}


int main(){
	int tps;
	scanf("%d", &tps);
	
	int h, m, s;
	
	h = Convertir_Heures(tps);
	tps = tps - h * 3600;
	
	m = Convertir_Minutes(tps);
	tps = tps - m * 60;
	
	s = tps;
	
	printf("%d heure", h);
	if(h>1){
		printf("s");
	}
	printf(" ");
	printf("%d minute", m);
	if(m>1){
		printf("s");
	}
	printf(" ");
	printf("%d seconde", s);
	if(s>1){
		printf("s");
	}
	printf(".\n");

}
