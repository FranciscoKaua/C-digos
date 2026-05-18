#include <stdio.h>
int main() {
    FILE *arquivo;
    
    arquivo = fopen("teste.txt", "w");
    
    if (arquivo == NULL) {
        printf("Erro\n");
        return 1;
    }
      
    fprintf(arquivo, "Bom dia\n");
    fprintf(arquivo, "Onde voce mora?\n");
    
    
    fclose(arquivo);
    printf("Arquivo salvo");
    
    return 0;
}