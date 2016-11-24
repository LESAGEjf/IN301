#include "SOKOBANinitialise.c"


int main(int argc, char* argv[]){
	
	SOKOBAN S;
	S = initialise_Sokoban(S);
	S = lit_niveau(S, argv[1]);
	affiche_tout(S);
	
	
	wait_escape(0);
}
