#include <stdio.h>
int main()
{
	int num;
	printf("Digite: ");
	scanf("%d", &num);
	
	switch (num){
		case 1:
			printf("Maçã");
			break;
		case 2:
			printf("Uva");
			break;
		case 3:
			printf("Pera");
			break;
		case 4:
			printf("Banana");
			break;
		case 5:
			printf("Manga");
			break;
		default:
			printf("Fruta inválida");
			break;
		
	}
	return 0;
}