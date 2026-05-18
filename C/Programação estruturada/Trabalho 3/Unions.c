#include <stdio.h>
union Numero {
    int inteiro;
    float flutuante;
    char caractere;
};

int main() {
    union Numero num;
    num.inteiro = 80;
    printf("Inteiro: %d\n", num.inteiro);       
    printf("Caractere: %c\n", num.caractere);     
    
   num.flutuante = 2.5;
    printf("Float: %.2f\n", num.flutuante);       
    printf("Inteiro: %d\n", num.inteiro);       
    
    return 0;
}