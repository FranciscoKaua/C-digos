#include <stdio.h>
int main() {
    int linha_torre, coluna_torre;
    printf("Digite a linha: ");
    scanf("%d", &linha_torre);
    
    printf("Digite a coluna: ");
    scanf("%d", &coluna_torre);
    
    if (linha_torre < 1 || linha_torre > 8 || coluna_torre < 1 || coluna_torre > 8) {
        printf("Posição inválida! Use linhas e colunas de 1 a 8.\n");
        return 1;
    }
    
    for (int coluna = 0; coluna <= 8; coluna++) {
        printf("%d ", coluna);
    }
    printf("\n");
    
    for(int linha = 0; linha <= 8; linha++) {
        printf("%d ", linha);
        
        for (int coluna = 1; coluna <= 8; coluna++) {
            if (linha == linha_torre && coluna == coluna_torre) {
                printf("T ");
            }
            else if (linha == linha_torre || coluna == coluna_torre) {
                printf("x ");
            }
            else {
                printf("- ");
            }
        }
        printf("\n");
    }
    
    return 0;
}