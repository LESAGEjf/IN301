#include "SOKOBANdeplacement.c"

//gerer avec undo au debut il y a un bug

SOKOBAN undo(SOKOBAN s){
	if(moves != 0){
		ll = ajoutDebut(ll, s);
		l = supprimeDebut(l);
		moves --;
		return l->s;
	}
	if(moves == 0){
		return s;
	}
	return s;
}

SOKOBAN redo(SOKOBAN s){
	if(ll != NULL){
		l = ajoutDebut(l, ll->s);
		ll = supprimeDebut(ll);
		moves ++;
		return l->s;
	}
	if(ll == NULL){
		return s;
	}
	return s;
}


SOKOBAN undo_redo(POINT p, SOKOBAN s, char c){	
	if( (p.x >= 488 && p.x <= 532 && p.y >= 173 && p.y <= 217)|| c == 'u'){
		s = undo(s);
	}
	if((p.x >= 538 && p.x <= 582 && p.y >= 173 && p.y <= 217) || c == 'r'){
		s = redo(s);
	}
	return s;
}

int clic_precedent_suivant(POINT p, int lvl, char c){
	if( (p.x >= 437 && p.x <= 503 && p.y >= 347 && p.y <= 413) || c == 'p'){
		if(lvl > 1) return 1;
	}
	if( (p.x >= 537 && p.x <= 603 && p.y >= 347 && p.y <= 413) || c == 's'){
		if(lvl < 50) return 2;
	}
	return 0;
}

SOKOBAN suivant_precedent(POINT p, int *lvl, SOKOBAN s, char c){
	if(clic_precedent_suivant(p, *lvl, c) == 2){
			*lvl = *lvl+1;
			s = lit_niveau(s, *lvl);
			l = NULL;
			ll = NULL;
			moves = 0;
	}
	if(clic_precedent_suivant(p, *lvl, c) == 1){
			*lvl = *lvl-1;
			s = lit_niveau(s, *lvl);
			l = NULL;
			ll = NULL;
			moves = 0;
	}
	return s;
}

void affiche_confirmation_reinitialiser(){
	POINT hg, bd, ouihg, ouibd, nonhg, nonbd, a, b, c, d;
	hg.x = 210; hg.y = 320;
	bd.x = 420; bd.y = 160;
	ouihg.x = 252; ouihg.y = 240;
	ouibd.x = 294; ouibd.y = 200;
	nonhg.x = 336; nonhg.y = 240;
	nonbd.x = 378; nonbd.y = 200;
	a.x = 260; a.y = 230;
	b.x = 344; b.y = 230;
	c.x = 230; c.y = 310;
	d.x = 225; d.y = 290;
	draw_fill_rectangle(hg, bd, gris);
	draw_fill_rectangle(ouihg, ouibd, red);
	draw_fill_rectangle(nonhg, nonbd, green);
	aff_pol("oui", 12, a, blanc);
	aff_pol("non", 12, b, blanc);
	aff_pol("Etes-vous sur de vouloir", 12, c, red);
	aff_pol("reinitialiser le niveau actuel ?", 12, d, red);
}

void affiche_confirmation_quitter(){
	POINT hg, bd, ouihg, ouibd, nonhg, nonbd, a, b, c, d;
	hg.x = 210; hg.y = 320;
	bd.x = 420; bd.y = 160;
	ouihg.x = 252; ouihg.y = 240;
	ouibd.x = 294; ouibd.y = 200;
	nonhg.x = 336; nonhg.y = 240;
	nonbd.x = 378; nonbd.y = 200;
	a.x = 260; a.y = 230;
	b.x = 344; b.y = 230;
	c.x = 230; c.y = 310;
	d.x = 225; d.y = 290;
	draw_fill_rectangle(hg, bd, gris);
	draw_fill_rectangle(ouihg, ouibd, red);
	draw_fill_rectangle(nonhg, nonbd, green);
	aff_pol("oui", 12, a, blanc);
	aff_pol("non", 12, b, blanc);
	aff_pol("Etes-vous sur de vouloir", 12, c, red);
	aff_pol("quiter le niveau actuel ?", 12, d, red);
}

int confirme(POINT p){
	if(p.x >= 252 && p.x <= 294 && p.y >= 200&& p.y <= 240){
		return 1;
	}
	if(p.x >= 336 && p.x <= 378 && p.y >= 200&& p.y <= 240){
		return 2;
	}
	return 0;
}

SOKOBAN reinitialise(POINT p, int *lvl, SOKOBAN s, char c){
	if( (p.x >= 17 && p.x <= 83 && p.y >= 327 && p.y <= 393) || c == 'r'){
		affiche_confirmation_reinitialiser();
		affiche_all();
		p = wait_key_or_clic(&c);
		while(confirme(p) == 0 || c != 'o' || c != 'n'){
			p = wait_key_or_clic(&c);
		}
		if(confirme(p) == 1 || c == 'o'){
			s = lit_niveau(s, *lvl);
			l = NULL;
			ll = NULL;
			moves = 0;
		}
		if(confirme(p) == 2 || c == 'n'){
			affiche_tout(s, *lvl);
		}
	}
	return s;
}

void quitter(POINT p, char c, SOKOBAN s, int *lvl){
	if( (p.x >= 17 && p.x <= 83 && p.y >= 387 && p.y <= 453) || c == 'q'){
		affiche_confirmation_quitter();
		affiche_all();
		p = wait_key_or_clic(&c);
		while(confirme(p) == 0 || c != 'o' || c != 'n'){
			p = wait_key_or_clic(&c);
		}
		if(confirme(p) == 1|| c == 'o'){
			exit(0);
		}
		if(confirme(p) == 2 || c == 'n'){
			affiche_tout(s, *lvl);
		}
	}
}


int main(/*int argc, char* argv[]*/){
	
	init_graphics(LARG_FENETRE,HAUT_FENETRE);
	affiche_auto_off();
	
	int lvl;
	lvl = 1;
	
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
		S = reinitialise(p, &lvl, S, c);
		S = suivant_precedent(p, &lvl, S, c);
		S = undo_redo(p, S, c);
		p = clic_deplacement(p);
		S = deplace_bonhomme(S, p);
		affiche_all();
		quitter(p, c, S, &lvl);
	}
	wait_escape(0);
	exit(0);
}
