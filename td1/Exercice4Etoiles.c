#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void affiche_etoile(int nb){
	
	while(nb>1){
		printf(" ");
		nb--;
	}
	printf("*\n");
}


int main(){
	
	int nb;
	scanf("%d",&nb);
	while(nb>0){
		affiche_etoile(nb);
		nb--;
	}
}
