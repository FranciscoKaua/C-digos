/*Letra a*/
#include <stdio.h>
int main(){
 int tam = 10;
 for (int i = 0; i < i; i = i - 1){/*Aqui tem um erro de lógica "i<i"*/
 printf("\n");/*Aqui não retorn nada*/
}
 return 0;
}

/*Letra b*/
#include <stdio.h>
int main() {
 int i = 0;
 while (i < 10) {
 printf("%d ", i);
 i--;/*Aqui vai fazer código ser executado infinitamente*/
 }
 return 0;
 }