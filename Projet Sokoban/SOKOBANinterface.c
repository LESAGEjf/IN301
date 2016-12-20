void affiche_contour_jeu(){
	POINT hg, hd, bd;
	hg.x = 0; hg.y = T*TAILLE_CASE + 1;
	hd.x = T*TAILLE_CASE + 1; hd.y = hg.y;
	bd.x = T*TAILLE_CASE + 1; bd.y = 0;
	
	draw_line(hg, hd, white);
	draw_line(bd, hd, white);
}

void dessine_fleche_vertical(POINT p1, POINT p2){ //fonction a finir plus tard pour l'affichage des boutons
	POINT p3, p4;
	p3.x = p1.x - 7; p3.y = p1.y - 7;
	p4.x = p1.x + 7; p4.y = p1.y - 7;
	
	draw_line(p1, p2, blanc);
	draw_line(p1, p3, blanc);
	draw_line(p1, p4, blanc);
}

void dessine_fleches(){ //fonction a finir plus tard pour l'affichage des boutons
	POINT p1, p2, p3, p4;
	p1.x = 333;
	p1.y = p2.y = 75;
	p2.x = 357;
	p3.x = p4.x = 340; p3.y = 82;
	p4.y = 68;
	
	draw_line(p1, p2, blanc);
	draw_line(p1, p3, blanc);
	draw_line(p1, p4, blanc);
	
	p1.x = 393;
	p1.y = p2.y = 75;
	p2.x = 417;
	p3.x = p4.x = 410; p3.y = 82;
	p4.y = 68;
	
	draw_line(p1, p2, blanc);
	draw_line(p2, p3, blanc);
	draw_line(p2, p4, blanc);
	
	p1.x = p2.x = 375;
	p1.y = 33; 
	p2.y = 57;
	p3.x = 368; 
	p4.x = 382;
	p3.y = p4.y = 40;
	
	draw_line(p1, p2, blanc);
	draw_line(p1, p3, blanc);
	draw_line(p1, p4, blanc);
	
	p1.x = p2.x = 375;
	p1.y = 117; 
	p2.y = 93;
	p3.x = 368; 
	p4.x = 382;
	p3.y = p4.y = 110;
	
	draw_line(p1, p2, blanc);
	draw_line(p1, p3, blanc);
	draw_line(p1, p4, blanc);
}

void affiche_bouton_deplacement(){ //pareil
	POINT p1, p2, p3, p4, p5, p6;
	p1.x = 330;
	p2.x = p4.x = 360;
	p5.x = p3.x = 390;
	p6.x = 420;
	p1.y = p5.y = 60;
	p4.y = 30;
	p2.y = p6.y = 90;
	p3.y = 120;
	
	draw_rectangle(p1, p2, white);
	draw_rectangle(p2, p3, white);
	draw_rectangle(p4, p5, white);
	draw_rectangle(p5, p6, white);
	dessine_fleches();
}
	
void affiche_ecriture(){ //pareil
}
	
