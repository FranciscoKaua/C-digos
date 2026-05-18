#include <stdio.h>
int maior(int vector[], int tamanho){
    int maior = 0;
    for(int i = 0; i < tamanho; i++){
        if(vector[i] > maior){
            maior = vector[i];
        }
    }
    return maior;
}
int main()
{
    int numeros[] = {2,1,9,5,10};
    int tamanho = 5;
    printf("O maior número do vetor: %d\n", maior(numeros, tamanho));
    
    return 0;
}
