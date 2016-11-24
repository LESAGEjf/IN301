#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sas.txt"

int main(){

    FILE* fichier = NULL;
    int caractereActuel = 0;
 
    fichier = fopen("sas.xsb", "r");
 
    if (fichier != NULL){
        while (caractereActuel != EOF){
            caractereActuel = fgetc(fichier);
            printf("%c", caractereActuel);
		}
		fclose(fichier);
    }
	return 0;
}
