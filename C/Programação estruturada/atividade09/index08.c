#include <stdio.h>
#include <stdlib.h>

void lerNumeros(int vetor[], int tamanho, char *mensagem) {
    printf("%s\n", mensagem);
    for(int i = 0; i < tamanho; i++) {
        printf("Número %d: ", i + 1);
        scanf("%d", &vetor[i]);
    }
}

int contarAcertos(int sorteio[], int bilhete[], int tamanho) {
    int acertos = 0;
    for(int i = 0; i < tamanho; i++) {
        for(int j = 0; j < tamanho; j++) {
            if(bilhete[i] == sorteio[j]) {
                acertos++;
                break;
            }
        }
    }
    return acertos;
}

int* encontrarCorretos(int sorteio[], int bilhete[], int tamanho, int acertos) {
    if(acertos == 0) return NULL;
    
    int *corretos = (int*)malloc(acertos * sizeof(int));
    if(corretos == NULL) return NULL;
    
    int pos = 0;
    for(int i = 0; i < tamanho; i++) {
        for(int j = 0; j < tamanho; j++) {
            if(bilhete[i] == sorteio[j]) {
                corretos[pos] = bilhete[i];
                pos++;
                break;
            }
        }
    }
    return corretos;
}

int main() {
    const int TAMANHO = 6;
    int numerosSorteados[6];
    int meuBilhete[6];
    int *numerosCorretos;
    int acertos;
    
    lerNumeros(numerosSorteados, TAMANHO, "Digite os 6 números sorteados:");
    lerNumeros(meuBilhete, TAMANHO, "\nDigite os 6 números do seu bilhete:");
    
    acertos = contarAcertos(numerosSorteados, meuBilhete, TAMANHO);
    
    numerosCorretos = encontrarCorretos(numerosSorteados, meuBilhete, TAMANHO, acertos);
       
    printf("Números sorteados: ");
    for(int i = 0; i < TAMANHO; i++) {
        printf("%d ", numerosSorteados[i]);
    }
    printf("\n");
    
    printf("Seus números:      ");
    for(int i = 0; i < TAMANHO; i++) {
        printf("%d ", meuBilhete[i]);
    }
    printf("\n\n");
    
    printf("Acertos: %d\n", acertos);
    
    if(acertos > 0) {
        printf("Números corretos: ");
        for(int i = 0; i < acertos; i++) {
            printf("%d ", numerosCorretos[i]);
        }
        printf("\n");
    }
    
    if(acertos > 0) {
        free(numerosCorretos);
    }
    
    return 0;
}