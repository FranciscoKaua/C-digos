#include <stdio.h>
#include <math.h>
int main(){
	int n;
	printf("Digite: ");
	scanf("%d", &n);
	
	if(n >= 0){
		int raiz = sqrt(n);
		printf("A raiz quadrada de %d é %d", n , raiz);
	}else
		printf("Número inválido");
	return 0;
}