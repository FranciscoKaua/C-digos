#include <stdio.h>
float media(float vector[], int tamanho){
    float soma = 0;
    for(int i = 0; i < tamanho; i++){
        soma = soma + vector[i];
    }
    return soma/tamanho;
}
int main()
{
    float notas[] = {5,6,9,5};
    int tamanho = 4;
    printf("A média das notas: %.2f\n", media(notas, tamanho));
    
    if(media(notas, tamanho) < 7.0 && media(notas, tamanho) > 4.0){
        printf("Recuperação");
    }else if(media(notas, tamanho) <= 4.0){
        printf("Reprovado");
    }else{
        printf("Aprovado");
    }

    return 0;
}