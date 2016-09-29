#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// X × Y = (X/2) × (2Y ) 	X pair
//(X − 1) × Y + Y 			X impair


int main(){

	int X, Y, Z, m;
	
	scanf("%d", &X);
	scanf("%d", &Y);
	Z = 0;
	
	
	while( X>1){
		if( X%2==0){
			X = X/2;
			Y = 2*Y;
		}
		if( X%2==1){
			X = X-1;
			Z = Z + Y;
		}
	}
	m = X * Y + Z;
	printf("%d\n", m);
}
