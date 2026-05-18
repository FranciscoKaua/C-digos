/*Usando while
#include <stdio.h>
int main(){
	int num;
	printf("Digite: ");
	scanf("%d", &num);
	
	int cont = 1;
	while(cont <= num){
		
		printf("%d\n", cont);
		
		cont = cont + 1;
	}
	return 0;
}*/

#include <stdio.h>
int main(){
	int num;
	printf("Digite: ");
	scanf("%d", &num);
	
	for(int cont = 1; cont <= num; cont++){
		printf("%d\n", cont);
	}
	return 0;
}