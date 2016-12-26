#include <stdio.h>
#include <stdlib.h>
#include "graphics.h"
#include "SOKOBANconstantes.h"

struct Case{
	int objet;
	POINT bg, hd;
};
struct Case typedef CASE;

struct Sokoban{
	CASE la_case[NOMBRE_CASE_HORIZONTAL][NOMBRE_CASE_VERTICAL];
};
struct Sokoban typedef SOKOBAN;

void affiche_contour_jeu(){
	POINT hg, hd, bd;
	hg.x = 0; hg.y = NOMBRE_CASE_VERTICAL*TAILLE_CASE + 1;
	hd.x = NOMBRE_CASE_HORIZONTAL*TAILLE_CASE + 1; hd.y = hg.y;
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
}

void affiche_tout(SOKOBAN S){
	int x, y;
	fill_screen(black);
	for(y=0;y<NOMBRE_CASE_VERTICAL; y++){
		for(x=0;x<NOMBRE_CASE_HORIZONTAL; x++){
			affiche_cases(S, x, y);
			affiche_contour_jeu();
		}
	}
}

SOKOBAN initialise_Sokoban(SOKOBAN S){
	int x, y;
	for(y=0;y<NOMBRE_CASE_VERTICAL; y++){
		for(x=0;x<NOMBRE_CASE_HORIZONTAL; x++){
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

int trouve_x_bonhomme(SOKOBAN s){
	int x, y;
	for(y=0;y<NOMBRE_CASE_VERTICAL; y++){
		for(x=0;x<NOMBRE_CASE_HORIZONTAL; x++){
			if(s.la_case[x][y].objet == BONHOMME){
				return x;
			}
		}
	}
	return -1;
}

int trouve_y_bonhomme(SOKOBAN s){
	int x, y;
	for(y=0;y<NOMBRE_CASE_VERTICAL; y++){
		for(x=0;x<NOMBRE_CASE_HORIZONTAL; x++){
			if(s.la_case[x][y].objet == BONHOMME){
				return y;
			}
		}
	}
	return -1;
}

int deplacement_possible(SOKOBAN s, POINT p){
	if(p.x > 0 && s.la_case[trouve_x_bonhomme(s) +1][trouve_y_bonhomme(s)].objet != MUR){
		return 1;
	}
	if(p.x < 0 && s.la_case[trouve_x_bonhomme(s) -1][trouve_y_bonhomme(s)].objet != MUR){
		return 2;
	}
	if(p.y > 0 && s.la_case[trouve_x_bonhomme(s)][trouve_y_bonhomme(s) +1].objet != MUR){
		return 3;
	}
	if(p.y < 0 && s.la_case[trouve_x_bonhomme(s)][trouve_y_bonhomme(s) -1].objet != MUR){
		return 4;
	}
}

SOKOBAN deplace_bonhomme(SOKOBAN s){
	POINT p;
	p = 
}

int main(/*int argc, char* argv[]*/){
	
	init_graphics(LARG_FENETRE,HAUT_FENETRE);
	affiche_auto_off();
	
	int lvl;
	lvl = 1;
	
	SOKOBAN S;
	
	/*if(argc > 1){
		lvl = atoi(argv[1]);
	}*/
	while(1){
		S = lit_niveau(S, lvl);
		affiche_tout(S);
		affiche_all();
	}
	
	wait_escape(0);
}
