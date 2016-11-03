#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int produit(int i, int j){
	int k;
	k = i * j;
	return k;
}


int main(){
	int N;
	printf("taille du tableau ? ");
	scanf("%d", &N);
	int T[N];
	int a, i, j, k, l;
	int min;
	
	for(i=0; i<N; i++){
		T[i] = 1;
	}
	printf("\npremiere case du tableau a multiplier ? ");
	scanf("%d", &j);
	printf("\ndeuxieme case du tableau a multiplier ? ");
	scanf("%d", &k);
	
	l = produit(T[j], T[k]);
	
	printf("\nle produit vaux %d \n", l);
	
	min = T[0];
	while(a<N){
		if(T[a] < min){
			min = T[a];
		}
		a++;
	}
	printf("\nle minimum vaux %d \n", min);
	
	k = T[0];
	for(i=1;i<N;i++){
		T[i] = T[i-1];
	
	
	
	
	
	
	
	
	
}

