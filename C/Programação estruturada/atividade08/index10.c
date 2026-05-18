#include <stdio.h>

int main() {
    
    int inteiro = 10;
    float real = 3.14f;
    char caractere = 'A';
    
    int *ptr_inteiro;
    float *ptr_real;
    char *ptr_caractere;
    
  
    ptr_inteiro = &inteiro;
    ptr_real = &real;
    ptr_caractere = &caractere;
    
    
    printf("Antes:\n");
    printf("Inteiro: %d \n", inteiro);
    printf("Real: %.2f \n", real );
    printf("Caractere: %c \n", caractere);
    
    *ptr_inteiro = 100;
    *ptr_real = 9.99f;
    *ptr_caractere = 'Z';
    
    
    printf("\nDepois:\n");
    printf("Inteiro: %d\n", inteiro);
    printf("Real: %.2f\n", real);
    printf("Caractere: %c\n", caractere);
    
    return 0;
}