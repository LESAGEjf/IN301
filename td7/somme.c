#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

double somme(char* argv[], int argc){
	double som;
	int i;
	som = 0;
	for(i=1;i<argc; i++){
		som += atof(argv[i]);
	}	
	return som;
}

int testMot(char* str){
	int taille = strlen(str);
	int i;
	int virg = 0;
	if(! (str[0] == '-' || str[0] == '.' || isdigit(str[0])) ){
		printf("char is not double\n");
		return 0;
	}
	if(str[0] == '.') virg = 1;
	
	for(i=1;i<taille;i++){
		if(! (str[i] == '.' || isdigit(str[i])) ){
			return 0;
		}
		if(str[i] == '.'){
			if(virg == 1){
				printf("too many commas\n");
				return 0;
			}
			else virg = 1;
		}
	}
	return 1;
}

int testArgs(int argc, char* argv[]){
	int i;
	for(i=1;i<argc;i++){
		if(!testMot(argv[i])) return 0;
	}
	return 1;
}




int main(int argc, char* argv[]) {
	
	double som;
	
	if(testArgs(argc, argv)){
		som = somme(argv, argc);
	}
	printf("%f\n", som);
	
	
	return 0;
}
