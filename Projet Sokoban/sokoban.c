#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "uvsqgraphics.h"
#include "SOKOBANconstantes.h"
#include "SOKOBANcase.h"
#include "SOKOBANinterface.h"
#include "SOKOBANinitialise.h"
#include "SOKOBANaffiche.c"
#include "SOKOBANaffiche.h"



int main(int argc, char* argv[]){
	int lvl;
	lvl = 0;
	SOKOBAN S;
	
	S = initialise_Sokoban(S);
	
	if(argc > 1){
		lvl = atoi(argv[1]);
	}
	
	S = lit_niveau(S, lvl);
	affiche_tout(S);
	
	wait_escape(0);
}
