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

int estTrie(liste l){ //tri croissant
	if( estListeVide(l) || estListeVide((*l).suiv) ){
		return 1;
	}
	if(l->val > l->suiv->val){
		return 0;
	}
	return estTrie(l->suiv);
}

liste insereT(liste l, int e){
	if(!estTrie(l)){
		printf("erreur");
		return l;
	}
	
	if(estListeVide(l) || e < l->val){
		return insereD(l, e);
	}
	l->suiv = insereT(l->suiv, e);
	return l;
}

int nbrvaleur(liste l){
	int nb=0;
	while(!estListeVide(l)){
		nb++;
		l = l->suiv;
	}
	return nb;
}

int nbrvaleur_rec(liste l){
	if(estListeVide(l)) return 0;
	return (1 + nbrvaleur_rec(l->suiv));
}

int rechvaleur(liste l, int e){
	int B = 0;
	while(!estListeVide(l)){
		if(l->val == e){
			B = 1;
		}
	l = l->suiv;
	}
	return B;
}

int rechvaleur_rec(liste l, int e){
	if(estListeVide(l))	return 0;
	if(l->val == e) return 1;
	return rechvaleur_rec(l->suiv, e);
}

int main(){
	liste l;
	int k;
	l = creerListe();
	l = insereD(l,3);
	l = insereD(l,2);
	l = insereD(l,1);
	l = insereF(l, 4);
	l = insereF_rec(l, 8);
	if(estTrie(l)){
		insereT(l, 6);
		insereT(l, 5);
		insereT(l, 7);
		insereT(l, 12);
	}
	afficheListe(l);
	k = nbrvaleur(l);
	printf("%d \n", k);
	if(rechvaleur(l, 6)){
		printf("la valeur 6 est presente\n");
	}
	libere(l);
	
	return 0;
}
