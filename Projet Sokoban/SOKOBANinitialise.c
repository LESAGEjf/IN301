#include "SOKOBANaffiche.c"

SOKOBAN initialise_Sokoban(SOKOBAN S){
	int i, j;
	for(j=0; j<20; j++){
		for(i=0; i<20; i++){
			S.la_case[i][j].hd.x = i*TAILLE_CASE+TAILLE_CASE;
			S.la_case[i][j].hd.y = j*TAILLE_CASE+TAILLE_CASE;
			S.la_case[i][j].bg.x = i*TAILLE_CASE;
			S.la_case[i][j].bg.y = j*TAILLE_CASE;
			S.la_case[i][j].objet = VIDE;
		}
	}
	return S;
}

int Convertie_fichier(char k){
	int b;
	if(k == '#') b = MUR;
	if(k == '$') b = CAISSE_A_BOUGER;
	if(k == '.') b = EMPLACEMENT;
	if(k == ' ') b = VIDE;
	if(k == '@') b = BONHOMME;
	else b = VIDE;
	return b;
}
	

SOKOBAN lit_niveau(SOKOBAN s, char* str){
	FILE* fic;
	int x, y;
	char obj;
	
	fic = fopen("sasquatch1.xsb", "r");
	if(fic == NULL){
		printf("echec ouverture fichier %s\n", str);
		exit(EXIT_FAILURE);
	}
	
	while(fgetc(fic) != *str);
	
	for(y=0;y<T;y++){
		for(x=0;x<T;x++){
			obj = fgetc(fic);
			s.la_case[x][y].objet = Convertie_fichier(obj);
		}
	}
	fclose(fic);
	return s;
}


	
	
	
	
	

