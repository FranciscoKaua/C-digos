#include <stdio.h>
int main() {
    FILE *arquivo;
    char linha[100];
    
    arquivo = fopen("teste.txt", "r");
    
    if (arquivo == NULL) {
        printf("Erro\n");
        return 1;
    }
      
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        printf(" %s", linha);
    }
    
    fclose(arquivo);
    return 0;
}