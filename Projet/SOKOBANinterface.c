#include "SOKOBANdeplacement.c"


struct element{
	SOKOBAN s;
	struct element *suiv;
};
typedef struct element *Liste;


Liste l = NULL;
Liste ll = NULL;

Liste ajoutDebut(Liste l, SOKOBAN s){
	Liste tmp = malloc(sizeof(struct element));
	tmp->s = s;
	tmp->suiv = l;
	return tmp;
}

Liste supprimeDebut(Liste l){
	Liste ll;
	if(l != NULL){
		ll = l;
		l = l->suiv;
	free(ll);
  }
  return l;
}

SOKOBAN undo(SOKOBAN s){
	if(l != NULL){
		ll = ajoutDebut(l, s);
		l = supprimeDebut(l);
	}
	moves --;
	return l->s;
}

SOKOBAN redo(SOKOBAN s){
	if(ll != NULL){
		l = ajoutDebut(ll, s);
		ll = supprimeDebut(ll);
	}
	moves ++;
	return l->s;
}

SOKOBAN gestion_undo_redo(POINT p, SOKOBAN s){
	
	if(p.x >= 488 && p.x <= 532 && p.y >= 173 && p.y <= 217){
		return undo(s);
	}
	if(p.x >= 538 && p.x <= 582 && p.y >= 173 && p.y <= 217){
		return redo(s);
	}
	return s;
}

int main(/*int argc, char* argv[]*/){
	
	init_graphics(LARG_FENETRE,HAUT_FENETRE);
	affiche_auto_off();
	
	int lvl;
	lvl = 25;
	
	SOKOBAN S;
	POINT p;
	char c;
	
	/*if(argc > 1){
		lvl = atoi(argv[1]);
	}*/
	S = lit_niveau(S, lvl);
	l = ajoutDebut(l, S);
	
	while(1){
		affiche_tout(S, lvl);
		affiche_all();
		p = wait_key_or_clic(&c);
		p = clic_deplacement(p);
		S = gestion_undo_redo(p, S);
		S = deplace_bonhomme(S, p);
		l = ajoutDebut(l, S);
		affiche_all();
	}
	wait_escape(0);
	exit(0);
}
