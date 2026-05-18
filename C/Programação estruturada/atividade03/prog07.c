#include <stdio.h>
int main() {
 	int num = 0;
 	int soma = 0;
 	for(int cont = 1; cont <= 5; cont++){
 		printf("Digite: ");
 		scanf("%d", &num);
 		
 		soma= soma + num;
 	}
 	printf("média: %.2f", (float)soma/5);
 	return 0;
 }