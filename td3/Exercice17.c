#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void echange(int *a, int *b){
	int k;
	k = *a;
	*a = *b;
	*b = k;
}

void reinitPointeur(int* (*p)){
	*p = NULL;
}

int main(){
	
	int t;
	
	t = sizeof(char); printf("char = %d\n", t);
	t = sizeof(int); printf("int = %d\n", t);
	t = sizeof(double); printf("double = %d\n", t);
	t = sizeof(char*); printf("char* = %d\n", t);
	t = sizeof(void*); printf("void* = %d\n", t);
	t = sizeof(int*); printf("int* = %d\n", t);
	t = sizeof(double*); printf("double* = %d\n", t);
	t = sizeof(int**); printf("int** = %d\n", t);
	t = sizeof(int[10]); printf("int[10] = %d\n", t);
	t = sizeof(char[7][3]); printf("char[7][3] = %d\n", t);
	//t = sizeof(int[]);
	
	
	char tab[10];
	
	t = sizeof(tab); printf("tab = %d\n", t);
	t = sizeof(tab[0]); printf("tab[0] = %d\n", t);
	t = sizeof(&tab[0]); printf("&tab[0] = %d\n", t);
	t = sizeof(*&tab); printf("*&tab = %d\n", t);
	t = sizeof(*&tab[0]); printf("*&tab[0] = %d\n", t);
	
	char (*p)[10] = &tab;
	
	t = sizeof(p); printf("p = %d\n", t);
	t = sizeof(*p); printf("p = %d\n", t);
	t = sizeof((*p)[2]); printf("p = %d\n", t);
	t = sizeof(&(*p)[2]); printf("p = %d\n", t);
	
	
	int a, b;
	a = 10; b = 54;
	printf("a = %d , b = %d\n apres echange:\n", a, b);
	echange(&a,&b);
	printf("a = %d , b = %d\n", a, b);
	
	
	int c = 1;
	int* p2 = &c;
	printf("*p2 = %p\n apres reinit:\n", p2);
	reinitPointeur(&p2);
	printf("*p2 = %p\n", p2);
	
	
	
}
