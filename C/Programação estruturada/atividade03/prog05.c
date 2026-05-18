#include <stdio.h>
int main() {

	 int num = 40;
	 int cont = 0;
	 int numPar = 0;
	 while(cont <= num){
	 	if(cont % 2 == 0){
	 		numPar ++;
	 	}
	 	cont ++;
	 }
	 
	 printf("Quantidade de num pares: %d", numPar);
 	return 0;

 }