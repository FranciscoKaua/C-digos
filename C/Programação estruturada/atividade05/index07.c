#include <stdio.h>
int SomarVetor(int vector[], int tamanho){
    int soma = 0;
    for(int i = 0; i < tamanho; i++){
        if(vector[i] > 0){
            soma = soma + vector[i]; 
        }
        
    }
    return soma;
}
int main()
{
    int vetor[] = {1,3,-5,7,-2,4};
    int tamanho = 6;
    printf("A soma dos positivos: %d", SomarVetor(vetor, tamanho));

    return 0;
}