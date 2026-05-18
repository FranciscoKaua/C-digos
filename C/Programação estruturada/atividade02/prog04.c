#include <stdio.h>
int main(){
	float salario;
	printf("Seu salário: ");
	scanf("%f", &salario);
	
	if(salario < 600){
		float novoSalario = ((salario*34)/100) + salario;
		printf("Seu novo salario: %.2f",  novoSalario);
	}else{
		printf("Você não tem direito ao aumento");
	}
	return 0;
}