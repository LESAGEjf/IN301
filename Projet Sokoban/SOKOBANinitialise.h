
#ifndef ___initialise_Sokoban
#define ___initialise_Sokoban

SOKOBAN initialise_Sokoban(SOKOBAN S){
	int i, j;
	for(j=0; j<30; j++){
		for(i=0; i<30; i++){
			S.la_case[i][j].hd.x = i*TAILLE_CASE+TAILLE_CASE;
			S.la_case[i][j].hd.y = j*TAILLE_CASE+TAILLE_CASE;
			S.la_case[i][j].bg.x = i*TAILLE_CASE;
			S.la_case[i][j].bg.y = j*TAILLE_CASE;
			S.la_case[i][j].objet = VIDE;
		}
	}
	return S;
}

#endif

#ifndef ___Convertie_fichier
#define ___Convertie_fichier

int Convertie_fichier(char k){
	int b;
	b = VIDE;
	if(k == '#') b = MUR;
		else if(k == '$') b = CAISSE_A_BOUGER;
			else if(k == '.') b = EMPLACEMENT;
				else if(k == ' ' || k == '\n') b = VIDE;
					else if(k == '@') b = BONHOMME;
	return b;
}

#endif

#ifndef ___lit_niveau
#define ___lit_niveau

SOKOBAN lit_niveau(SOKOBAN s, int lvl){
	FILE* fic;
	int caractereactuel = 0, b;
	int x, y;
	x = y = 0;
	
	fic = fopen("sasquatch1.xsb", "r");
	if(fic != NULL){
		for(b=-1; b<lvl;b++){
			while( (caractereactuel != ';') && (caractereactuel != EOF) ){
				caractereactuel = fgetc(fic);
				if(lvl-1 == b){
					s.la_case[x][y].objet = Convertie_fichier(caractereactuel);
					
				}
				x++; y++;
			}
		}
		fclose(fic);
	}
	else{
		printf("echec ouverture fichier\n");
		exit(EXIT_FAILURE);
	}
	
	fclose(fic);
	return s;
}

#endif
