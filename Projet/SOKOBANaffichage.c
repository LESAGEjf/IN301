#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "graphics.h"
#include "SOKOBANconstantes.h"

int moves = 0;

struct Case{
	int objet;
	POINT bg, hd;
};
struct Case typedef CASE;

struct Sokoban{
	CASE la_case[NOMBRE_CASES_HORIZONTALES][NOMBRE_CASES_VERTICALES];
};
struct Sokoban typedef SOKOBAN;

void affiche_contour_jeu(){
	POINT hg, hd, bd;
	hg.x = 0; hg.y = NOMBRE_CASES_VERTICALES*TAILLE_CASE + 1;
	hd.x = NOMBRE_CASES_HORIZONTALES*TAILLE_CASE + 1; hd.y = hg.y;
	bd.x = hd.x; bd.y = 0;
	
	draw_line(hg, hd, white);
	draw_line(bd, hd, white);
}

void dessine_mur(SOKOBAN S, int x, int y){
	draw_fill_rectangle(S.la_case[x][y].hd, S.la_case[x][y].bg, COUL_MUR);
}

void dessine_caisse_a_bouger(SOKOBAN S, int x, int y){
	draw_fill_rectangle(S.la_case[x][y].hd, S.la_case[x][y].bg, COUL_CAISSE_A_BOUGER);
}

void dessine_caisse_place(SOKOBAN S, int x, int y){
	draw_fill_rectangle(S.la_case[x][y].hd, S.la_case[x][y].bg, COUL_CAISSE_PLACE);
}

void dessine_bonhomme(SOKOBAN S, int x, int y){
	POINT centre;
	centre.x = (S.la_case[x][y].hd.x + S.la_case[x][y].bg.x)/2;
	centre.y = (S.la_case[x][y].hd.y + S.la_case[x][y].bg.y)/2;
	draw_fill_circle(centre, TAILLE_CASE/2, COUL_BONHOMME);
}

void dessine_emplacement(SOKOBAN S, int x, int y){
	POINT hg, bd;
	hg.x = S.la_case[x][y].bg.x; 
	hg.y = S.la_case[x][y].hd.y;
	bd.x = S.la_case[x][y].hd.x; 
	bd.y = S.la_case[x][y].bg.y;
	draw_line(hg, bd, COUL_EMPLACEMENT);
	draw_line(S.la_case[x][y].hd, S.la_case[x][y].bg, COUL_EMPLACEMENT);
}

void affiche_cases(SOKOBAN S, int x, int y){
			if(S.la_case[x][y].objet == VIDE) draw_fill_rectangle(S.la_case[x][y].bg, S.la_case[x][y].hd, noir);
			if(S.la_case[x][y].objet == MUR) dessine_mur(S, x, y);
			if(S.la_case[x][y].objet == CAISSE_A_BOUGER) dessine_caisse_a_bouger(S, x, y);
			if(S.la_case[x][y].objet == EMPLACEMENT) dessine_emplacement(S, x, y);
			if(S.la_case[x][y].objet == BONHOMME) dessine_bonhomme(S, x, y);
			if(S.la_case[x][y].objet == CAISSE_PLACE) dessine_caisse_place(S, x, y);
			if(S.la_case[x][y].objet == EMPLACEMENTetBONHOMME){
				dessine_emplacement(S, x, y);
				dessine_bonhomme(S, x, y);
			}
}

SOKOBAN initialise_Sokoban(SOKOBAN S){
	int x, y;
	for(y=0;y<NOMBRE_CASES_VERTICALES; y++){
		for(x=0;x<NOMBRE_CASES_HORIZONTALES; x++){
			S.la_case[x][y].hd.x = x*TAILLE_CASE+TAILLE_CASE;
			S.la_case[x][y].hd.y = y*TAILLE_CASE+TAILLE_CASE;
			S.la_case[x][y].bg.x = x*TAILLE_CASE;
			S.la_case[x][y].bg.y = y*TAILLE_CASE;
			S.la_case[x][y].objet = VIDE;
		}
	}
	return S;
}

int Convertie_fichier(char k){
	int b;
	b = VIDE;
	if(k == '#') b = MUR;
		else if(k == '$') b = CAISSE_A_BOUGER;
			else if(k == '.') b = EMPLACEMENT;
				else if(k == '@') b = BONHOMME;
					else b = VIDE;
	return b;
}

SOKOBAN lit_niveau(SOKOBAN s, int lvl){
	FILE* fic;
	char caractereactuel = ' ';
	int b;
	int x, y;
	x = 0;
	y = 21;
	s = initialise_Sokoban(s);
	fic = fopen("sasquatch1.xsb", "r");
	if(fic != NULL){
		for(b=-1; b<lvl;b++){
			do{
				caractereactuel = fgetc(fic);
				if(lvl-1 == b){
					s.la_case[x][y].objet = Convertie_fichier(caractereactuel);
					if(caractereactuel == '\n'){
						y--; x = 0;
					}
					else x++;
					
				}
			}while( (caractereactuel != ';') && (caractereactuel != EOF) );
		}
	}
	else{
		printf("echec ouverture fichier\n");
		exit(EXIT_FAILURE);
	}
	
	fclose(fic);
	return s;
}

void affiche_un_bouton(char* txt, POINT centre, int rayon, COULEUR cr, COULEUR ctxt){
	POINT ptxt;
	ptxt.x = centre.x - 18;
	ptxt.y = centre.y + 10;
	POINT hg, bd;
	hg.x = centre.x - rayon; hg.y = centre.y + rayon;
	bd.x = centre.x + rayon; bd.y = centre.y - rayon;
	draw_fill_rectangle(hg, bd, cr);
	aff_pol(txt, 11, ptxt, ctxt);
}

void affiche_un_gros_bouton(char* txt, POINT centre, int rayon, COULEUR cr, COULEUR ctxt){
	POINT ptxt;
	ptxt.x = centre.x -30;
	ptxt.y = centre.y +10;
	POINT hg, bd;
	hg.x = centre.x - 1.5 * rayon; hg.y = centre.y + rayon;
	bd.x = centre.x + 1.5 * rayon; bd.y = centre.y - rayon;
	draw_fill_rectangle(hg, bd, cr);
	aff_pol(txt, 12, ptxt, ctxt);
}

void affiche_tous_les_boutons(){
	int r = 22;
	
	POINT gauche, droite, haut, bas, undo, redo, precedent, suivant, quitter, init;
	bas.x = 535; bas.y = 45;
	gauche.x = 485; gauche.y = 75;
	droite.x = 585; droite.y = 75;
	haut.x = 535; haut.y = 105;
	undo.x = 510; undo.y = 195;
	redo.x = 560; redo.y = 195;
	precedent.x = 470; precedent.y = 380;
	suivant.x = 570; suivant.y = 380;
	quitter.x = 50; quitter.y = 420;
	init.x = 50; init.y = 360;
	
	char b[] = "bas";
	char g[] = "gauche";
	char d[] = "droite";
	char h[] = "haut";
	char u[] = "undo";
	char re[] = "redo";
	char p[] = "precedent";
	char s[] = "suivant";
	char q[] = "quitter";
	char i[] = "init";
	
	
	affiche_un_bouton(b, bas, r, white, blue);
	affiche_un_bouton(g, gauche, r, white, blue);
	affiche_un_bouton(d, droite, r, white, blue);
	affiche_un_bouton(h, haut, r, white, blue);
	affiche_un_bouton(u, undo, r, green, white);
	affiche_un_bouton(re, redo, r, green, white);
	affiche_un_gros_bouton(p, precedent, r, white, black);
	affiche_un_gros_bouton(s, suivant, r, white, black);
	affiche_un_gros_bouton(q, quitter, r, white, red);
	affiche_un_gros_bouton(i, init, r, white, red);
}

void affiche_nombre_mouvement(int moves){
	POINT p1, p2;
	p1.x = 280; p1.y = 400;
	p2.x = 360; p2.y = 400;
	aff_pol("moves:", 20, p1, white);
	aff_int(moves, 20, p2, white);
}

void affiche_niveau_actuel(int lvl){
	POINT p1, p2;
	p1.x = 150; p1.y = 400;
	p2.x = 230; p2.y = 400;
	aff_pol("level:", 20, p1, white);
	aff_int(lvl, 20, p2, white);
}

void affiche_tout(SOKOBAN S, int lvl){
	int x, y;
	fill_screen(black);
	for(y=0;y<NOMBRE_CASES_VERTICALES; y++){
		for(x=0;x<NOMBRE_CASES_HORIZONTALES; x++){
			affiche_cases(S, x, y);
			affiche_contour_jeu();
			affiche_tous_les_boutons();
			affiche_nombre_mouvement(moves);
			affiche_niveau_actuel(lvl);
		}
	}
}

/*
int main(int argc, char* argv[]){
	
	init_graphics(LARG_FENETRE,HAUT_FENETRE);
	affiche_auto_off();
	
	int lvl;
	lvl = 15;
	
	SOKOBAN S;
	
	while(1){
		S = lit_niveau(S, lvl);
		affiche_tout(S, lvl);
		affiche_all();
	
	
	wait_escape(0);
	exit(0);
}
}
*/
