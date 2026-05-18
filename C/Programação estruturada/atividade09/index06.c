#include <stdio.h>
#include <stdlib.h>

void preencher_vetor(int *v, int tamanho) {
    for(int i = 0; i < tamanho; i++) {
        printf("Posição %d: ", i);
        scanf("%d", &v[i]);
    }
}

int main() {
    int n, *vetor;
    
    printf("Quantidade de elementos: ");
    scanf("%d", &n);
    vetor = (int*)malloc(n * sizeof(int));
    if(!vetor) {
        printf("Erro de alocação\n");
        return 1;
    }
    
    preencher_vetor(vetor, n);
    
    printf("\nVetor: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
    
    free(vetor);
    return 0;
}