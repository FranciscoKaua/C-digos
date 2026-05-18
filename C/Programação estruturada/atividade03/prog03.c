#include <stdio.h>
int main() {
	int soma;
	int cont = 1;
	while(cont <= 10){
		soma = soma + cont;
		
		cont ++;
	}
	printf("%d", soma);
 	return 0;
 }