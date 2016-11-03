#include <stdio.h>
#include <stdlib.h>
#include <time.h>


struct Tableau{
	int taille;
	int tab[100];
};
typedef struct Tableau Tab;

int alea(int n){
	int k;
	k = rand()%n;
	while(k <= 0){
		k = rand()%n;
	}
	return k;
}

void affiche_tableau(Tab P, int elem){
	int i;
	for(i=0;i<elem;i++){
		printf("T.tab[%d] = %d\n", i, P.tab[i]);
	}
}

int produit_tableau(Tab P, int elem){
	int i; int prod = 1;
	for(i=0;i<elem;i++){
		prod = prod * P.tab[i];
	}
	return prod;
}

int recherche_minimum(Tab P, int elem){
	int min; int i;
	min = P.tab[0];
	for(i=1;i<elem;i++){
		if(min > P.tab[i]){
			min = P.tab[i];
		}
	}
	return min;
}

Tab decalage(Tab P, int elem){
	int i;
	for(i=elem;i>0;i--){
		P.tab[i] = P.tab[i-1];
	}
	P.tab[0] = 0;
	P.taille ++;
	return P;
}

Tab tri(Tab P, int elem){
	int i, k, j;
	for(j=0;j<elem;j++){
		for(i=0;i<elem-1;i++){
			if(P.tab[i] > P.tab[i+1]){
				k = P.tab[i];
				P.tab[i] = P.tab[i+1];
				P.tab[i+1] = k;
			}
		}
	}
	return P;
}

Tab insere(Tab P, int k){
	int milieu;
	milieu = P.taille/2;
	P.taille++;
	while(/*condition ?*/){
		if(k<P.tab[milieu]){
			milieu = mileu / 2;
		}
		else if(k>P.tab[milieu]{
			milieu += milieu /4;
		}
		else if(k==P.tab[milieu]){
		}
	}
}

int main(){
	srand(time(NULL));
	
	int a;	Tab T;	int i;
	//int min;	//int prod;
	
	a = alea(20);
	printf("%d\n", a);
	
	T.taille = 10;
	
	for(i=0;i<10;i++){
		T.tab[i] = alea(20);
	}
	affiche_tableau(T, 10);
	
	/*prod = produit_tableau(T, T.taille);
	
	printf("le produit vaut : %d\n", prod);
	
	min = recherche_minimum(T, T.taille);
	printf("le minimum vaut : %d\n", min);*/
	
	/*T = decalage(T, T.taille);
	affiche_tableau(T, T.taille);*/
	
	printf("\n");
	
	T = tri(T, T.taille);
	affiche_tableau(T, T.taille);
	
	printf("\n");
	
	
	
	
}
