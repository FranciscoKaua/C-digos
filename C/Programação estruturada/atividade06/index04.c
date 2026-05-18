#include <stdio.h>
float Maior(float x, float y, float z){
    float vetor[] = {x, y, z};
    float maior = vetor[0]; 
    
    for(int i = 1; i < 3; i++){ 
        if(vetor[i] > maior){
            maior = vetor[i];
        }
    }
    return maior;
}

int main()
{
    float num1, num2, num3;
    
    printf("Digite o 1 número: ");
    scanf("%f", &num1); 
    
    printf("Digite o 2 número: ");
    scanf("%f", &num2); 
    
    printf("Digite o 3 número: ");
    scanf("%f", &num3); 
    
    printf("O maior: %.2f", Maior(num1, num2, num3));
    return 0;
}

