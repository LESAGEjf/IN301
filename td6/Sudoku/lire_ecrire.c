#include "constantes.h"
#include "sudoku.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void ecrire(SUDOKU S){
	//int x, y;
	
}

SUDOKU lire(char* str){
	FILE* fic;
	SUDOKU S;
	int x, y, k;
	
	fic = fopen(str, "r");
	if(fic == NULL){
		printf("echec ouverture fichier %s\n", str);
		exit(EXIT_FAILURE);
	}
	
	S.mode = JOUER;
	for (y=N-1 ; y>=0 ; y--){
		for (x=0 ; x<N ; x++) {
			fscanf(fic, "%d ", &k); 
// fscanff ne renvoie pas la valeur lu il faut pas faire k = fscanf...
// "%d " : l'espace sert a dire qu'il prend l'entier et l'espace donc le prochain appelle commence direct au chiffre
//pour le projet il faudra faire fscanf("%c") ou fgetc qui lit un char par un char
			S.la_case[x][y].val = k;
		}
	}
	for (y=N-1 ; y>=0 ; y--){
		for (x=0 ; x<N ; x++) {
			fscanf(fic, "%d ", &k); 
			S.la_case[x][y].modifiable = k;
		}
	}
	
	fclose(fic);
	return S;
}
