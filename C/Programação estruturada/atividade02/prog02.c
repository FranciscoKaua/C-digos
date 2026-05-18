#include <stdio.h>
int main(){
	float n1, n2, n3;
	
	printf("Digite: ");
	
	scanf("%f", &n1);
	scanf("%f", &n2);
	scanf("%f", &n3);
	
	float media = (n1 + n2 + n3)/ 3;
	
	if(media >= 7){
		printf("Aprovado, media %.2f", media);
	}else
		printf("Reprovado, media %.2f", media);
	return 0;
}