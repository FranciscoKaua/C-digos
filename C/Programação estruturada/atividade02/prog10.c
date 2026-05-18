#include <stdio.h>
int main()
{
	int num;
	printf("Digite: ");
	scanf("%d", &num);
	
	if(num == 100){
		printf("Igual a 100");
	}else{
		printf("Diferente de 100");
	}
	return 0;
}