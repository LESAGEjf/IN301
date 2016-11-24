#include "SOKOBANaffiche.c"


POINT Trouve_Bonhomme(CASE c[20][20]){
	int i,j,x,y;
	x=0; y=0;
	POINT T;
	for(j=0;j<20;j++){
		for(i=0;i<20;i++){
			if(c[i][j].objet == 5){
				x=i;
				y=j;
			}
		}
	}
	T.x = x;
	T.y = y;
	return T;
}

/*CASE Deplace(POINT Trouve_Bonhomme(CASE c[20][20]), CASE c[20][20], POINT p){
	
	//corriger la fonction
	
	CASE ech;
	int i,j;
	if(p.x<0 && c[i-1][j].objet!=1){
		ech = c[i][j];
		c[i][j] = c[i-1][j];
		c[i-1][j] = ech;
	 }
	if(p.x>0 && c[i+1][j].objet!=1){
		ech = c[i][j];
		c[i][j] = c[i+1][j];
		c[i+1][j] = ech;
	 }
	if(p.y<0 && c[i][j-1].objet!=1){
		ech = c[i][j];
		c[i][j] = c[i][j-1];
		c[i][j-1] = ech;
	 }
	if(p.y>0 && c[i][j+1].objet!=1){
		ech = c[i][j];
		c[i][j] = c[i][j+1];
		c[i][j+1] = ech;
	 }
	return c[20][20];
}

void Deplace_bonhomme(CASE c[20][20], POINT p){
	CASE BH;
	int x, y;
	x = Trouve_Bonhomme(c).x;
	y = Trouve_Bonhomme(c).y;
	BH = c[x][y];
	efface_bonhomme(BH);
	c[20][20] = Deplace(BH, c, p);
	dessine_bonhomme(BH);
}
*/	


int main(){
	init_graphics(400,400);
	CASE c[20][20];
	POINT p;
	
	c[20][20] = initialise_case(c);
	c[20][20] = level_1(c);
	affiche_tout(c);
	
	p.x = p.y = 0;
	p = get_arrow();
	
	
	

wait_escape();
exit(0);
}
