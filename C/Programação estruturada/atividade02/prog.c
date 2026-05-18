#include <stdio.h>
int main(){
	int a, b, c;
	printf("Digite: ");
	scanf("%d", &a);
	scanf("%d", &b);
	scanf("%d", &c);
	
	if(a + b > c){
		printf("soma de a e b é maior que c");
	}	
	return 0;
}