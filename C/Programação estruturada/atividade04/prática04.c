#include <stdio.h>
int main(){
	int num = 0;
	float soma = 0;
	int cont = 0;
	while(1){
		printf("Digite: ");
		scanf("%d", &num);
		
		if(num < 0){
			printf("Número inválido\n");
		}else if(num == 0){
			printf("Total de números entrados: %d\n", cont);
			printf("Média: %2.f", soma/cont);
			break;
		}else{
			soma = soma + num;
			cont ++;
		}
	}

}