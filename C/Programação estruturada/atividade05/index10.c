#include <stdio.h>
void par(int vector[], int tamanho){
    for(int i = 0; i < tamanho; i++){
        if(vector[i] % 2 == 0){
            printf("%d, ", vector[i]);
        }
    }
    
}
void impa(int vector[], int tamanho){
    for(int i = 0; i < tamanho; i++){
        if(vector[i] % 2 != 0){
            printf("%d, ", vector[i]);
        }
    }
    
}
int main()
{
    int vetor[] = {2,1,9,5,10};
    int tamanho = 5;
    printf("Números pares: ");
    par(vetor, tamanho);
    printf("\nNúmeros impares: ");
    impa(vetor, tamanho);
    
    return 0;
}
