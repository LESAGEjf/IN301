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
	else return 0;
}

SOKOBAN deplace_bonhomme(SOKOBAN s){
	POINT p;
	int var1, var2;
	char c;
	p = wait_key_or_clic(&c);
	int i, j;
	i = trouve_x_bonhomme(s);
	j = trouve_y_bonhomme(s);
if(s.la_case[i][j].objet == BONHOMME){	
	if(deplacement_possible(s, p) == 1){
		var1 = s.la_case[i+1][j].objet;
		var2 = s.la_case[i+2][j].objet;
		if(var1 == CAISSE_A_BOUGER){
			if(var2 == VIDE){
				s.la_case[i][j].objet = VIDE;
				s.la_case[i+1][j].objet = BONHOMME;
				s.la_case[i+2][j].objet = CAISSE_A_BOUGER;
				moves++;
				return s;
			}
			if(var2 == CAISSE_A_BOUGER || var2 == CAISSE_PLACE || var2 == MUR){
				moves++;
				return s;
			}
			if(var2 == EMPLACEMENT){
				s.la_case[i][j].objet = VIDE;
				s.la_case[i+1][j].objet = BONHOMME;
				s.la_case[i+2][j].objet = CAISSE_PLACE;
				moves++;
				return s;
			}
		}
		if(var1 == VIDE){
					s.la_case[i][j].objet = VIDE;
					s.la_case[i+1][j].objet = BONHOMME;
					moves++;
					return s;
				}
		if(var1 == EMPLACEMENT){
					s.la_case[i][j].objet = VIDE;
					s.la_case[i+1][j].objet = EMPLACEMENTetBONHOMME;
					moves++;
					return s;
				}
		if(var1 == CAISSE_PLACE){
			if(var2 == VIDE){
				s.la_case[i][trouve_y_bonhomme(s)].objet = VIDE;
				s.la_case[i+1][j].objet = EMPLACEMENTetBONHOMME;
				s.la_case[i+2][j].objet = CAISSE_A_BOUGER;
				moves++;
				return s;
			}
			if(var2 == MUR || var2 == CAISSE_A_BOUGER || var2 == CAISSE_PLACE){
				moves++;
				return s;
			}
			if(var2 == EMPLACEMENT){
				s.la_case[i][j].objet = VIDE;
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
				s.la_case[i][j].objet = VIDE;
				s.la_case[i-1][j].objet = BONHOMME;
				s.la_case[i-2][j].objet = CAISSE_A_BOUGER;
				moves++;
				return s;
			}
			if(var2 == CAISSE_A_BOUGER || var2 == CAISSE_PLACE || var2 == MUR){
				moves++;
				return s;
			}
			if(var2 == EMPLACEMENT){
				s.la_case[i][j].objet = VIDE;
				s.la_case[i-1][trouve_y_bonhomme(s)].objet = BONHOMME;
				s.la_case[i-2][j].objet = CAISSE_PLACE;
				moves++;
				return s;
			}
		}
		if(var1 == VIDE){
					s.la_case[i][j].objet = VIDE;
					s.la_case[i-1][j].objet = BONHOMME;
					moves++;
					return s;
				}
		if(var1 == EMPLACEMENT){
					s.la_case[i][j].objet = VIDE;
					s.la_case[i-1][j].objet = EMPLACEMENTetBONHOMME;
					moves++;
					return s;
				}
		if(var1 == CAISSE_PLACE){
			if(var2 == VIDE){
				s.la_case[i][j].objet = VIDE;
				s.la_case[i-1][j].objet = EMPLACEMENTetBONHOMME;
				s.la_case[i-2][j].objet = CAISSE_A_BOUGER;
				moves++;
				return s;
			}
			if(var2 == MUR || var2 == CAISSE_A_BOUGER || var2 == CAISSE_PLACE){
				moves++;
				return s;
			}
			if(var2 == EMPLACEMENT){
				s.la_case[i][j].objet = VIDE;
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
				s.la_case[i][j].objet = VIDE;
				s.la_case[i][j+1].objet = BONHOMME;
				s.la_case[i][j+2].objet = CAISSE_A_BOUGER;
				moves++;
				return s;
			}
			if(var2 == CAISSE_A_BOUGER || var2 == CAISSE_PLACE || var2 == MUR){
				moves++;
				return s;
			}
			if(var2 == EMPLACEMENT){
				s.la_case[i][j].objet = VIDE;
				s.la_case[i][j+1].objet = BONHOMME;
				s.la_case[i][j+2].objet = CAISSE_PLACE;
				moves++;
				return s;
			}
		}
		if(var1 == VIDE){
					s.la_case[i][j].objet = VIDE;
					s.la_case[i][j+1].objet = BONHOMME;
					moves++;
					return s;
				}
		if(var1 == EMPLACEMENT){
					s.la_case[i][j].objet = VIDE;
					s.la_case[i][j+1].objet = EMPLACEMENTetBONHOMME;
					moves++;
					return s;
				}
		if(var1 == CAISSE_PLACE){
			if(var2 == VIDE){
				s.la_case[i][j].objet = VIDE;
				s.la_case[i][j+1].objet = EMPLACEMENTetBONHOMME;
				s.la_case[i][j+2].objet = CAISSE_A_BOUGER;
				moves++;
				return s;
			}
			if(var2 == MUR || var2 == CAISSE_A_BOUGER || var2 == CAISSE_PLACE){
				moves++;
				return s;
			}
			if(var2 == EMPLACEMENT){
				s.la_case[i][j].objet = VIDE;
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
				s.la_case[i][j].objet = VIDE;
				s.la_case[i][j-1].objet = BONHOMME;
				s.la_case[i][j-2].objet = CAISSE_A_BOUGER;
				moves++;
				return s;
			}
			if(var2 == CAISSE_A_BOUGER || var2 == CAISSE_PLACE || var2 == MUR){
				return s;
			}
			if(var2 == EMPLACEMENT){
				s.la_case[i][j].objet = VIDE;
				s.la_case[i][j-1].objet = BONHOMME;
				s.la_case[i][j-2].objet = CAISSE_PLACE;
				moves++;
				return s;
			}
		}
		if(var1 == VIDE){
					s.la_case[i][j].objet = VIDE;
					s.la_case[i][j-1].objet = BONHOMME;
				moves++;
					return s;
				}
		if(var1 == EMPLACEMENT){
					s.la_case[i][j].objet = VIDE;
					s.la_case[i][j-1].objet = EMPLACEMENTetBONHOMME;
					moves++;
					return s;
				}
		if(var1 == CAISSE_PLACE){
			if(var2 == VIDE){
				s.la_case[i][j].objet = VIDE;
				s.la_case[i][j-1].objet = EMPLACEMENTetBONHOMME;
				s.la_case[i][j-2].objet = CAISSE_A_BOUGER;
				moves++;
				return s;
			}
			if(var2 == MUR || var2 == CAISSE_A_BOUGER || var2 == CAISSE_PLACE){
				moves++;
				return s;
			}
			if(var2 == EMPLACEMENT){
				s.la_case[i][j].objet = VIDE;
				s.la_case[i][j-1].objet = EMPLACEMENTetBONHOMME;
				s.la_case[i][j-2].objet = CAISSE_PLACE;
				moves++;
				return s;
			}
		}
	}
}
if(s.la_case[i][j].objet == EMPLACEMENTetBONHOMME){
	if(deplacement_possible(s, p) == 1){
		var1 = s.la_case[i+1][j].objet;
		var2 = s.la_case[i+2][j].objet;
		if(var1 == CAISSE_A_BOUGER){
			if(var2 == VIDE){
				s.la_case[i][j].objet = EMPLACEMENT;
				s.la_case[i+1][j].objet = BONHOMME;
				s.la_case[i+2][j].objet = CAISSE_A_BOUGER;
				moves++;
				return s;
			}
			if(var2 == CAISSE_A_BOUGER || var2 == CAISSE_PLACE || var2 == MUR){
				moves++;
				return s;
			}
			if(var2 == EMPLACEMENT){
				s.la_case[i][j].objet = EMPLACEMENT;
				s.la_case[i+1][j].objet = BONHOMME;
				s.la_case[i+2][j].objet = CAISSE_PLACE;
				moves++;
				return s;
			}
		}
		if(var1 == VIDE){
					s.la_case[i][j].objet = EMPLACEMENT;
					s.la_case[i+1][j].objet = BONHOMME;
				moves++;
					return s;
				}
		if(var1 == EMPLACEMENT){
					s.la_case[i][j].objet = EMPLACEMENT;
					s.la_case[i+1][j].objet = EMPLACEMENTetBONHOMME;
				moves++;
					return s;
				}
		if(var1 == CAISSE_PLACE){
			if(var2 == VIDE){
				s.la_case[i][trouve_y_bonhomme(s)].objet = EMPLACEMENT;
				s.la_case[i+1][j].objet = EMPLACEMENTetBONHOMME;
				s.la_case[i+2][j].objet = CAISSE_A_BOUGER;
				moves++;
				return s;
			}
			if(var2 == MUR || var2 == CAISSE_A_BOUGER || var2 == CAISSE_PLACE){
				moves++;
				return s;
			}
			if(var2 == EMPLACEMENT){
				s.la_case[i][j].objet = EMPLACEMENT;
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
				s.la_case[i][j].objet = EMPLACEMENT;
				s.la_case[i-1][j].objet = BONHOMME;
				s.la_case[i-2][j].objet = CAISSE_A_BOUGER;
				moves++;
				return s;
			}
			if(var2 == CAISSE_A_BOUGER || var2 == CAISSE_PLACE || var2 == MUR){
				moves++;
				return s;
			}
			if(var2 == EMPLACEMENT){
				s.la_case[i][j].objet = EMPLACEMENT;
				s.la_case[i-1][trouve_y_bonhomme(s)].objet = BONHOMME;
				s.la_case[i-2][j].objet = CAISSE_PLACE;
				moves++;
				return s;
			}
		}
		if(var1 == VIDE){
					s.la_case[i][j].objet = EMPLACEMENT;
					s.la_case[i-1][j].objet = BONHOMME;
				moves++;
					return s;
				}
		if(var1 == EMPLACEMENT){
					s.la_case[i][j].objet = EMPLACEMENT;
					s.la_case[i-1][j].objet = EMPLACEMENTetBONHOMME;
				moves++;
					return s;
				}
		if(var1 == CAISSE_PLACE){
			if(var2 == VIDE){
				s.la_case[i][j].objet = EMPLACEMENT;
				s.la_case[i-1][j].objet = EMPLACEMENTetBONHOMME;
				s.la_case[i-2][j].objet = CAISSE_A_BOUGER;
				moves++;
				return s;
			}
			if(var2 == MUR || var2 == CAISSE_A_BOUGER || var2 == CAISSE_PLACE){
				moves++;
				return s;
			}
			if(var2 == EMPLACEMENT){
				s.la_case[i][j].objet = EMPLACEMENT;
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
				s.la_case[i][j].objet = EMPLACEMENT;
				s.la_case[i][j+1].objet = BONHOMME;
				s.la_case[i][j+2].objet = CAISSE_A_BOUGER;
				moves++;
				return s;
			}
			if(var2 == CAISSE_A_BOUGER || var2 == CAISSE_PLACE || var2 == MUR){
				moves++;
				return s;
			}
			if(var2 == EMPLACEMENT){
				s.la_case[i][j].objet = EMPLACEMENT;
				s.la_case[i][j+1].objet = BONHOMME;
				s.la_case[i][j+2].objet = CAISSE_PLACE;
				moves++;
				return s;
			}
		}
		if(var1 == VIDE){
					s.la_case[i][j].objet = EMPLACEMENT;
					s.la_case[i][j+1].objet = BONHOMME;
				moves++;
					return s;
				}
		if(var1 == EMPLACEMENT){
					s.la_case[i][j].objet = EMPLACEMENT;
					s.la_case[i][j+1].objet = EMPLACEMENTetBONHOMME;
				moves++;
					return s;
				}
		if(var1 == CAISSE_PLACE){
			if(var2 == VIDE){
				s.la_case[i][j].objet = EMPLACEMENT;
				s.la_case[i][j+1].objet = EMPLACEMENTetBONHOMME;
				s.la_case[i][j+2].objet = CAISSE_A_BOUGER;
				moves++;
				return s;
			}
			if(var2 == MUR || var2 == CAISSE_A_BOUGER || var2 == CAISSE_PLACE){
				moves++;
				return s;
			}
			if(var2 == EMPLACEMENT){
				s.la_case[i][j].objet = EMPLACEMENT;
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
				s.la_case[i][j].objet = EMPLACEMENT;
				s.la_case[i][j-1].objet = BONHOMME;
				s.la_case[i][j-2].objet = CAISSE_A_BOUGER;
				moves++;
				return s;
			}
			if(var2 == CAISSE_A_BOUGER || var2 == CAISSE_PLACE || var2 == MUR){
				moves++;
				return s;
			}
			if(var2 == EMPLACEMENT){
				s.la_case[i][j].objet = EMPLACEMENT;
				s.la_case[i][j-1].objet = BONHOMME;
				s.la_case[i][j-2].objet = CAISSE_PLACE;
				moves++;
				return s;
			}
		}
		if(var1 == VIDE){
					s.la_case[i][j].objet = EMPLACEMENT;
					s.la_case[i][j-1].objet = BONHOMME;
				moves++;
					return s;
				}
		if(var1 == EMPLACEMENT){
					s.la_case[i][j].objet = EMPLACEMENT;
					s.la_case[i][j-1].objet = EMPLACEMENTetBONHOMME;
				moves++;
					return s;
				}
		if(var1 == CAISSE_PLACE){
			if(var2 == VIDE){
				s.la_case[i][j].objet = EMPLACEMENT;
				s.la_case[i][j-1].objet = EMPLACEMENTetBONHOMME;
				s.la_case[i][j-2].objet = CAISSE_A_BOUGER;
				moves++;
				return s;
			}
			if(var2 == MUR || var2 == CAISSE_A_BOUGER || var2 == CAISSE_PLACE){
				moves++;
				return s;
			}
			if(var2 == EMPLACEMENT){
				s.la_case[i][j].objet = EMPLACEMENT;
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

int main(/*int argc, char* argv[]*/){
	
	init_graphics(LARG_FENETRE,HAUT_FENETRE);
	affiche_auto_off();
	
	int lvl;
	lvl = 25;
	
	SOKOBAN S;
	
	/*if(argc > 1){
		lvl = atoi(argv[1]);
	}*/
	S = lit_niveau(S, lvl);
	
	while(1){
		affiche_tout(S, lvl);
		affiche_all();
		S = deplace_bonhomme(S);
		affiche_all();
	}
	wait_escape(0);
	exit(0);
}


