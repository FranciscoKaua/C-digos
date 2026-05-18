#include <stdio.h>
#include <string.h>

int main() {
    char txt[]= "Bolo";
    int tamanho = strlen(txt);
    printf("Primeira letra: %c\n", txt[0]);
    printf("Ultima letra: %c\n", txt[tamanho - 1]);
    printf("Caracteres:  %d \n", tamanho);
    
    char nome1[10]= "Junior";
    char nome2[10] = "Santos";
    strcat(nome1, nome2);
    printf("Nome junto: %s", nome1);
    return 0;
}