#include <stdio.h>
int main(){
	char letra;
	printf("Digite letra: ");
	scanf("%s", &letra);
	
	switch(letra){
		case 'a':
			printf("É uma vogal");
			break;
		case 'e':
			printf("É uma vogal");
			break;
		case 'i':
			printf("É uma vogal");
			break;
		case 'o':
			printf("É uma vogal");
			break;
		case 'u':
			printf("É uma vogal");
			break;
		default:
		  printf("Não é uma vogal");
		  break;
	}
	return 0;
}