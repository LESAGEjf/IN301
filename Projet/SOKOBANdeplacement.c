#include "SOKOBANaffichage.c"

#ifndef ___wait_key_or_clic
#define ___wait_key_or_clic
POINT wait_key_or_clic(char* isKey){
  	int encore = 1;
	POINT dep;
	SDL_Event event;
	*isKey = 1;
	dep.x = 0;
	dep.y = 0;
	while (encore && SDL_WaitEvent(&event))
	  {
	    /* Si l'utilisateur a appuyé sur une touche */
	    if (event.type == SDL_KEYDOWN)
	      {
		if(event.key.keysym.sym == SDLK_ESCAPE) exit(0);
		else if(event.key.keysym.sym == SDLK_LEFT)  encore=0, (dep.x) = -1;
		else if(event.key.keysym.sym == SDLK_RIGHT) encore=0, (dep.x) = 1;
		else if(event.key.keysym.sym == SDLK_UP)    encore=0, (dep.y) = 1;
		else if(event.key.keysym.sym == SDLK_DOWN)  encore=0, (dep.y) = -1;
		else if(256 <= event.key.keysym.sym && event.key.keysym.sym <= 265) encore=0, *isKey = '0' + event.key.keysym.sym - 256;
		else if('a' <= event.key.keysym.sym && event.key.keysym.sym <= 'z') encore=0,  *isKey = event.key.keysym.sym;
		else *isKey = 0;
		while (SDL_WaitEvent(&event)){
		  if (event.type == SDL_KEYUP) break;
		}
	      }
	    /* Si l'utilisateur clique avec la souris */
	    else if ((event.type == SDL_MOUSEBUTTONDOWN) && (event.button.button == SDL_BUTTON_LEFT))
	      {
		*isKey = 0;
		encore = 0;
		dep.x = event.button.x;
		dep.y = HEIGHT-event.button.y;
	      }
	    /* Si l'utilisateur a demandé à fermer la fenêtre, on quitte */
	    else if (event.type == SDL_QUIT) exit(0);
	  }
	return dep;
}
#endif


int trouve_x_bonhomme(SOKOBAN s){
	int x, y;
	for(y=0;y<NOMBRE_CASES_VERTICALES; y++){
		for(x=0;x<NOMBRE_CASES_HORIZONTALES; x++){
			if(s.la_case[x][y].objet == BONHOMME|| s.la_case[x][y].objet == EMPLACEMENTetBONHOMME){
				return x;
			}
		}
	}
	return -1;
}

int trouve_y_bonhomme(SOKOBAN s){
	int x, y;
	for(y=0;y<NOMBRE_CASES_VERTICALES; y++){
		for(x=0;x<NOMBRE_CASES_HORIZONTALES; x++){
			if(s.la_case[x][y].objet == BONHOMME || s.la_case[x][y].objet == EMPLACEMENTetBONHOMME){
				return y;
			}
		}
	}
	return -1;
}

POINT clic_deplacement(POINT p){
	//bouton bas
	if( (p.x >= 513) && (p.x <= 557) && (p.y >= 23) && (p.y <= 67) ){
		p.x = 0;
		p.y = -1;
		return  p;
	}
	//bouton gauche
	if( (p.x >= 463) && (p.x <= 507) && (p.y >= 53) && (p.y <= 97) ){
		p.x = -1;
		p.y = 0;
		return  p;
	}
	//bouton droit
	if( (p.x >= 563) && (p.x <= 607) && (p.y >= 53) && (p.y <= 97) ){
		p.x = 1;
		p.y = 0;
		return  p;
	}
	//bouton haut
	if( (p.x >= 513) && (p.x <= 557) && (p.y >= 83) && (p.y <= 127) ){
		p.x = 0;
		p.y = 1;
		return  p;
	}
	//si on appuie sur une des fleches au clavier
	if( p.x == 1 || p.x == -1 || p.y == 1 || p.y == -1){
		return p;
	}
	return p;
}
	

int deplacement_possible(SOKOBAN s, POINT p){
	if(p.x == 1 && s.la_case[trouve_x_bonhomme(s) +1][trouve_y_bonhomme(s)].objet != MUR){
		return 1;
	}
	if(p.x == -1 && s.la_case[trouve_x_bonhomme(s) -1][trouve_y_bonhomme(s)].objet != MUR){
		return 2;
	}
	if(p.y == 1 && s.la_case[trouve_x_bonhomme(s)][trouve_y_bonhomme(s) +1].objet != MUR){
		return 3;
	}
	if(p.y == -1 && s.la_case[trouve_x_bonhomme(s)][trouve_y_bonhomme(s) -1].objet != MUR){
		return 4;
	}
	else return 0;
}

SOKOBAN deplace_bonhomme(SOKOBAN s, POINT p){
	int var1, var2;
	int i, j, objet_courant;
	i = trouve_x_bonhomme(s);
	j = trouve_y_bonhomme(s);
	objet_courant = VIDE;
	
if(s.la_case[i][j].objet == BONHOMME || s.la_case[i][j].objet == EMPLACEMENTetBONHOMME){
	if(s.la_case[i][j].objet == EMPLACEMENTetBONHOMME){
		objet_courant = EMPLACEMENT;
	}
	if(deplacement_possible(s, p) == 1){
		var1 = s.la_case[i+1][j].objet;
		var2 = s.la_case[i+2][j].objet;
		if(var1 == CAISSE_A_BOUGER){
			if(var2 == VIDE){
				s.la_case[i][j].objet = objet_courant;
				s.la_case[i+1][j].objet = BONHOMME;
				s.la_case[i+2][j].objet = CAISSE_A_BOUGER;
				moves++;
				return s;
			}
			if(var2 == CAISSE_A_BOUGER || var2 == CAISSE_PLACE || var2 == MUR){
				return s;
			}
			if(var2 == EMPLACEMENT){
				s.la_case[i][j].objet = objet_courant;
				s.la_case[i+1][j].objet = BONHOMME;
				s.la_case[i+2][j].objet = CAISSE_PLACE;
				moves++;
				return s;
			}
		}
		if(var1 == VIDE){
					s.la_case[i][j].objet = objet_courant;
					s.la_case[i+1][j].objet = BONHOMME;
					moves++;
					return s;
				}
		if(var1 == EMPLACEMENT){
					s.la_case[i][j].objet = objet_courant;
					s.la_case[i+1][j].objet = EMPLACEMENTetBONHOMME;
					moves++;
					return s;
				}
		if(var1 == CAISSE_PLACE){
			if(var2 == VIDE){
				s.la_case[i][j].objet = objet_courant;
				s.la_case[i+1][j].objet = EMPLACEMENTetBONHOMME;
				s.la_case[i+2][j].objet = CAISSE_A_BOUGER;
				moves++;
				return s;
			}
			if(var2 == MUR || var2 == CAISSE_A_BOUGER || var2 == CAISSE_PLACE){
				return s;
			}
			if(var2 == EMPLACEMENT){
				s.la_case[i][j].objet = objet_courant;
				s.la_case[i+1][j].objet = EMPLACEMENTetBONHOMME;
				s.la_case[i+2][j].objet = CAISSE_PLACE;
				moves++;
				return s;
			}
		}
	}
	if(deplacement_possible(s, p) == 2){
		var1 = s.la_case[i-1][j].objet;
		var2 = s.la_case[i-2][j].objet;
		if(var1 == CAISSE_A_BOUGER){
			if(var2 == VIDE){
				s.la_case[i][j].objet = objet_courant;
				s.la_case[i-1][j].objet = BONHOMME;
				s.la_case[i-2][j].objet = CAISSE_A_BOUGER;
				moves++;
				return s;
			}
			if(var2 == CAISSE_A_BOUGER || var2 == CAISSE_PLACE || var2 == MUR){
				return s;
			}
			if(var2 == EMPLACEMENT){
				s.la_case[i][j].objet = objet_courant;
				s.la_case[i-1][j].objet = BONHOMME;
				s.la_case[i-2][j].objet = CAISSE_PLACE;
				moves++;
				return s;
			}
		}
		if(var1 == VIDE){
					s.la_case[i][j].objet = objet_courant;
					s.la_case[i-1][j].objet = BONHOMME;
					moves++;
					return s;
				}
		if(var1 == EMPLACEMENT){
					s.la_case[i][j].objet = objet_courant;
					s.la_case[i-1][j].objet = EMPLACEMENTetBONHOMME;
					moves++;
					return s;
				}
		if(var1 == CAISSE_PLACE){
			if(var2 == VIDE){
				s.la_case[i][j].objet = objet_courant;
				s.la_case[i-1][j].objet = EMPLACEMENTetBONHOMME;
				s.la_case[i-2][j].objet = CAISSE_A_BOUGER;
				moves++;
				return s;
			}
			if(var2 == MUR || var2 == CAISSE_A_BOUGER || var2 == CAISSE_PLACE){
				return s;
			}
			if(var2 == EMPLACEMENT){
				s.la_case[i][j].objet = objet_courant;
				s.la_case[i-1][j].objet = EMPLACEMENTetBONHOMME;
				s.la_case[i-2][j].objet = CAISSE_PLACE;
				moves++;
				return s;
			}
		}
	}
	if(deplacement_possible(s, p) == 3){
		var1 = s.la_case[i][j+1].objet;
		var2 = s.la_case[i][j+2].objet;
		if(var1 == CAISSE_A_BOUGER){
			if(var2 == VIDE){
				s.la_case[i][j].objet = objet_courant;
				s.la_case[i][j+1].objet = BONHOMME;
				s.la_case[i][j+2].objet = CAISSE_A_BOUGER;
				moves++;
				return s;
			}
			if(var2 == CAISSE_A_BOUGER || var2 == CAISSE_PLACE || var2 == MUR){
				return s;
			}
			if(var2 == EMPLACEMENT){
				s.la_case[i][j].objet = objet_courant;
				s.la_case[i][j+1].objet = BONHOMME;
				s.la_case[i][j+2].objet = CAISSE_PLACE;
				moves++;
				return s;
			}
		}
		if(var1 == VIDE){
					s.la_case[i][j].objet = objet_courant;
					s.la_case[i][j+1].objet = BONHOMME;
					moves++;
					return s;
				}
		if(var1 == EMPLACEMENT){
					s.la_case[i][j].objet = objet_courant;
					s.la_case[i][j+1].objet = EMPLACEMENTetBONHOMME;
					moves++;
					return s;
				}
		if(var1 == CAISSE_PLACE){
			if(var2 == VIDE){
				s.la_case[i][j].objet = objet_courant;
				s.la_case[i][j+1].objet = EMPLACEMENTetBONHOMME;
				s.la_case[i][j+2].objet = CAISSE_A_BOUGER;
				moves++;
				return s;
			}
			if(var2 == MUR || var2 == CAISSE_A_BOUGER || var2 == CAISSE_PLACE){
				return s;
			}
			if(var2 == EMPLACEMENT){
				s.la_case[i][j].objet = objet_courant;
				s.la_case[i][j+1].objet = EMPLACEMENTetBONHOMME;
				s.la_case[i][j+2].objet = CAISSE_PLACE;
				moves++;
				return s;
			}
		}
	}
	if(deplacement_possible(s, p) == 4){
		var1 = s.la_case[i][j-1].objet;
		var2 = s.la_case[i][j-2].objet;
		if(var1 == CAISSE_A_BOUGER){
			if(var2 == VIDE){
				s.la_case[i][j].objet = objet_courant;
				s.la_case[i][j-1].objet = BONHOMME;
				s.la_case[i][j-2].objet = CAISSE_A_BOUGER;
				moves++;
				return s;
			}
			if(var2 == CAISSE_A_BOUGER || var2 == CAISSE_PLACE || var2 == MUR){
				return s;
			}
			if(var2 == EMPLACEMENT){
				s.la_case[i][j].objet = objet_courant;
				s.la_case[i][j-1].objet = BONHOMME;
				s.la_case[i][j-2].objet = CAISSE_PLACE;
				moves++;
				return s;
			}
		}
		if(var1 == VIDE){
					s.la_case[i][j].objet = objet_courant;
					s.la_case[i][j-1].objet = BONHOMME;
				moves++;
					return s;
				}
		if(var1 == EMPLACEMENT){
					s.la_case[i][j].objet = objet_courant;
					s.la_case[i][j-1].objet = EMPLACEMENTetBONHOMME;
					moves++;
					return s;
				}
		if(var1 == CAISSE_PLACE){
			if(var2 == VIDE){
				s.la_case[i][j].objet = objet_courant;
				s.la_case[i][j-1].objet = EMPLACEMENTetBONHOMME;
				s.la_case[i][j-2].objet = CAISSE_A_BOUGER;
				moves++;
				return s;
			}
			if(var2 == MUR || var2 == CAISSE_A_BOUGER || var2 == CAISSE_PLACE){
				return s;
			}
			if(var2 == EMPLACEMENT){
				s.la_case[i][j].objet = objet_courant;
				s.la_case[i][j-1].objet = EMPLACEMENTetBONHOMME;
				s.la_case[i][j-2].objet = CAISSE_PLACE;
				moves++;
				return s;
			}
		}
	}
}
	return s;
}

