//taille du sokoban et nombre de cases du sokoban
#define NOMBRE_CASES_VERTICALES 20
#define NOMBRE_CASES_HORIZONTALES 30

//definition des objets
#define VIDE 0
#define MUR 1
#define CAISSE_A_BOUGER 2
#define EMPLACEMENT 3
#define BONHOMME 4
#define CAISSE_PLACE 5
#define EMPLACEMENTetBONHOMME 7

//constantes d'affichage
#define TAILLE_CASE 15
#define TAILLE_INTERFACE 150
#define LARG_FENETRE (NOMBRE_CASES_HORIZONTALES*TAILLE_CASE)+TAILLE_INTERFACE+30
#define HAUT_FENETRE (NOMBRE_CASES_VERTICALES*TAILLE_CASE)+TAILLE_INTERFACE+30

//constantes pour les couleurs
#define COUL_MUR red
#define COUL_CAISSE_A_BOUGER brown
#define COUL_EMPLACEMENT yellow
#define COUL_BONHOMME pink
#define COUL_CAISSE_PLACE green
