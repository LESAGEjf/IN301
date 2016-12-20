SOKOBAN initialise_Sokoban(SOKOBAN S){ //initialise tout les cases du sokoban a vide
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

int Convertie_fichier(char k){ //convertie le caratctere lu en objet a inserer dans les cases du sokoban
	int b;
	b = VIDE;
	if(k == '#') b = MUR;
		else if(k == '$') b = CAISSE_A_BOUGER;
			else if(k == '.') b = EMPLACEMENT;
				else if(k == ' ' || k == '\n') b = VIDE;
					else if(k == '@') b = BONHOMME;
	return b;
}
	

SOKOBAN lit_niveau(SOKOBAN s, int lvl){ //lit le fichier sasquatch et initialise le sokoban en fonction du niveau taper en argument
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


	
	
	
	
	

