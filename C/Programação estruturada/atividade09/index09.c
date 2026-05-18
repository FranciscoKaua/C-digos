#include <stdio.h>
#include <stdlib.h>

void inicializarMemoria(int *mem, int capacidade) {
    for (int i = 0; i < capacidade; i++) {
        mem[i] = 0;
    }
}

void inserirValor(int *mem, int capacidade) {
    int posicao, valor;
    
    printf("Digite a posição (0 a %d): ", capacidade - 1);
    scanf("%d", &posicao);
    
    if (posicao < 0 || posicao >= capacidade) {
        printf("Erro: Posição inválida!\n");
        return;
    }
    
    printf("Digite o valor inteiro: ");
    scanf("%d", &valor);
    mem[posicao] = valor;
    printf("Valor %d armazenado na posição %d\n", valor, posicao);
}

void consultarValor(int *mem, int capacidade) {
    int posicao;
    
    printf("Digite a posição (0 a %d): ", capacidade - 1);
    scanf("%d", &posicao);
    
    if (posicao < 0 || posicao >= capacidade) {
        printf("Erro: Posição inválida!\n");
        return;
    }
    
    printf("Valor na posição %d: %d\n", posicao, mem[posicao]);
}

void mostrarMemoria(int *mem, int capacidade) {
    for (int i = 0; i < capacidade; i++) {
        printf("%7d | %p | %5d\n", i, (void*)&mem[i], mem[i]);
    }
}

int main() {
    int *memoria = NULL;
    int tamanho_bytes, capacidade;
    int opcao;
    
    printf("Tamanho do tipo int neste sistema: %ld bytes\n", sizeof(int));
    printf("Digite o tamanho total da memória em bytes (múltiplo de %ld): ", sizeof(int));
    scanf("%d", &tamanho_bytes);
    
    if (tamanho_bytes <= 0) {
        printf("Erro: Tamanho deve ser positivo!\n");
        return 1;
    }
    
    if (tamanho_bytes % sizeof(int) != 0) {
        printf("Erro: O tamanho deve ser múltiplo de %ld!\n", sizeof(int));
        return 1;
    }
    
    capacidade = tamanho_bytes / sizeof(int);
    
    memoria = (int*)malloc(tamanho_bytes);
    if (memoria == NULL) {
        printf("Erro na alocação\n");
        return 1;
    }
    
    inicializarMemoria(memoria, capacidade);
    
    printf("Capacidade: %d posições de inteiro\n", capacidade);
    printf("Tamanho total: %d bytes\n\n", tamanho_bytes);
  
    while(opcao != 0){
        printf("1. inserir valor\n");
        printf("2. Consultar valor\n");
        printf("3. Mostrar memória completa\n");
        printf("4. Informações do sistema\n");
        printf("0. Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);
        
        switch (opcao) {
            case 1:
                inserirValor(memoria, capacidade);
                break;
            case 2:
                consultarValor(memoria, capacidade);
                break;
            case 3:
                mostrarMemoria(memoria, capacidade);
                break;
            case 4:
                printf("Tamanho do int: %ld bytes\n", sizeof(int));
                printf("Memória alocada: %d bytes\n", tamanho_bytes);
                printf("Posições disponíveis: %d\n", capacidade);
                printf("Endereço: %p\n", (void*)memoria);
                break;
            case 0:
                printf("Encerrando...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
        
    }
    
    free(memoria);
    
    return 0;
}