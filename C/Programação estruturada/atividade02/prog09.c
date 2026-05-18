#include <stdio.h>
int main() {
 	int idade;
 	printf("Sua idade: ");
 	scanf("%d", &idade);
 	
 	if(idade <= 12){
 	 	printf("Criança");
 	 }else if(idade >= 13 && idade <= 17){
 	  	printf("Adolescente");
 	 }else if(idade >= 18 && idade <= 59){
 	  	printf("Adulto");
 	 }else{
 	 	printf("Idoso");
 	 }
    
    return 0;
}