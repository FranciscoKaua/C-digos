#include <stdio.h>
#include <stdlib.h>

float calcular_soma(float *v, int tamanho) {
    float total = 0.0;
    for (int i = 0; i < tamanho; i++) {
        total += v[i];
    }
    return total;
}

int main() {
    int n;
    float *vetor, soma;
 
    printf("Digite a quantidade de números: ");
    scanf("%d", &n);
    
    if (n <= 0) {
        printf("Quantidade inválida\n");
        return 1;
    }
    
    vetor = (float*)malloc(n * sizeof(float));
    if (vetor == NULL) {
        printf("Erro na alocação\n");
        return 1;
    }
    
    printf("Digite os %d números:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Valor %d: ", i + 1);
        scanf("%f", &vetor[i]);
    }
    
    soma = calcular_soma(vetor, n);
    
    printf("\n RESULTADO:\n");
    printf("Quantidade de elementos: %d\n", n);
    printf("Soma total: %.2f\n", soma);
    printf("Média: %.2f\n", soma / n); 
    
    free(vetor);
 
    return 0;
}