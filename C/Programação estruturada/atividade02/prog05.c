#include <stdio.h>
int main(){
	int idade;
	printf("Sua idade: ");
	scanf("%d", &idade);
	
	if(idade >= 18){
		printf("Você é de maior");
	}else{
		printf("Você é de menor");
	}
	return 0;
}