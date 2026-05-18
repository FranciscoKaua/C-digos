#include <stdio.h>
int main() {

	 int num;
	 printf("Digite: ");
	 scanf("%d", &num);
	 
	 int cont = 1;
	 while(cont <= num){
	 	if(cont % 2 != 0){
	 		printf("%d\n", cont);
	 	}
	 	cont ++;
	 }
	 
	 
 	return 0;

 }