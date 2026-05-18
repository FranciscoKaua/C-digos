#include <stdio.h>
int main(){
	int n1, n2, n3;
	printf("Lados do triângulo: ");
	scanf("%d", &n1);
	scanf("%d", &n2);
	scanf("%d", &n3);
	
	if( n1 < n2 + n3 && n2 < n1 + n3 && n3 < n1 + n2){
	  printf("Forma um triângulo\n");
	  if(n1 == n2 && n1 == n3){
	    printf("É um triângulo equilátero");
	  }else if(n1 == n2 || n1 == n3 || n3 == n2){
	  	printf("É um triângulo isósceles");
	  }else{
	  	printf("É um triângulo escaleno");
	  }
	}else{
	  printf("Triângulo inválido");
	}
	
	return 0;
}