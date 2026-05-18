#include <stdio.h>
int main() {
	int soma = 0;
	for(int cont = 0; cont <= 10; cont++){
		if(cont % 2 == 0){
			soma = soma + cont;
		}
	}
	printf("Soma dos pares: %d", soma);
	return 0;
 }