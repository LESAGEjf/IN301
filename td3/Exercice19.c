#include <stdio.h>
#include <stdlib.h>

struct element{
	int val;
	struct element* suiv;
};
typedef struct element elm;
typedef elm* liste;
typedef int bool;

liste creerListe()
{
	return NULL;
}

int estListeVide(liste l)
{
	return l == NULL;
}

liste insereD(liste l, int e)
{
	liste l2;
	l2 = malloc(sizeof(elm));
	
	if(l2 == NULL){
		printf(" erreur mémoire ");
		exit(EXIT_FAILURE);
	}
	
	(*l2).val = e;
	(*l2).suiv = l;
	return l2;
}

liste insereF(liste l, int e){
	liste l2, lfin;
	if(estListeVide(l)){
		return insereD(l,e);
	}
	lfin = l;
	while(!estListeVide((*lfin).suiv)){
		lfin = (*lfin).suiv;
	}
	
	l2 = malloc(sizeof(elm));
	if(l2 == NULL){
		printf(" erreur mémoire ");
		exit(EXIT_FAILURE);
	}
	(*l2).val = e;
	(*l2).suiv = NULL;
	(*lfin).suiv = l2;
	
	return l;
}

liste insereF_rec(liste l, int e){
	if(estListeVide(l)){
		return insereD(l,e);
	}
	(*l).suiv = insereF_rec((*l).suiv, e);
	return l;
}


void libere(liste l){
	liste l2;
	while ( !estListeVide(l) ){
		l2 = (*l).suiv;
		free(l);
		l = l2;
	}
}

void afficheListe(liste l){
	if( !estListeVide(l) ){
		printf("%d \n", (*l).val);
		afficheListe((*l).suiv);
	}
}

int main(){
	liste l;
	l = creerListe();
	l = insereD(l,2);
	l = insereD(l,3);
	l = insereD(l,1);
	l = insereF(l, 12);
	l = insereF_rec(l, 8);
	afficheListe(l);
	
	libere(l);
	
	return 0;
}
