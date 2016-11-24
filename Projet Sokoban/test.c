#include "graphics.h"






int main(){
	init_graphics(400, 400);
	POINT P2, P3;
	COULEUR coul;
	coul = bleu;
	P2.x = 10; P2.y = 50;
	P3.x = 50; P3.y = 100;
	draw_fill_rectangle(P2, P3, coul);
	
	coul = jaune;
	int rayon = 25;
	
	draw_circle(P3, rayon, coul);
	
	wait_clic();
	draw_line(P2, P3, jaune);
	
	
	
wait_escape();
exit(0);
}
