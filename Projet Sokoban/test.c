#include "graphics.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


void lit_niveau(int lvl){
	FILE* fic;
	int caractereactuel = 0, s;
	
	fic = fopen("sasquatch1.xsb", "r");
	if(fic != NULL){
		for(s=-1; s<lvl;s++){
			do{
				caractereactuel = fgetc(fic);
				if(lvl-1 == s){
					printf("%c", caractereactuel);
				}
			}
			while( (caractereactuel != ';') && (caractereactuel != EOF) );
		}
		fclose(fic);
	}
	else{
		printf("echec ouverture fichier\n");
		exit(EXIT_FAILURE);
	}
	
	fclose(fic);
}

int main(){
	
	lit_niveau(25);
	
wait_escape();
exit(0);
}
