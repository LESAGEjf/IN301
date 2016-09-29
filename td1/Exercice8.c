#include <stdio.h>
#include <stdlib.h>
#include <time.h>






int main(){
	
	int n, i, rep;
	
	printf("Le nombre a tester est :");	
	scanf("%d", &n);
	
	if(n==2 || n == 1){
		printf("%d est premier.\n", n);
		return 0;
	}
	for(i=2; i<=5 ; i++){
		if(n%i == 0){
			rep = 0;
			i = 5;
		}
		else rep = 1;
	}
	if(rep==1){
		printf("%d est premier.\n", n);
	}
	if(rep==0){
		printf("%d n'est pas premier.\n", n);
	}
}	

