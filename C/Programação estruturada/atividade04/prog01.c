#include <stdio.h>
int main(){
	int base, expoente;
	printf("Base: ");
	scanf("%d", &base);
	printf("Expoente: ");
	scanf("%d", &expoente);
	
	int resultado = 1;
	for(int i = 1; i <= expoente; i++){
		resultado *= base;
	}
	printf("Resultado: %d", resultado);
	return 0;
}