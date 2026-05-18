#include <stdio.h>
int main() {
    int linhas = 5;
    for(int linha = 1; linha <= linhas; linha++) {
        for(int coluna = 1; coluna <= linha; coluna++) {
            printf("%d ", coluna);
        }
        printf("\n");
    }
    
    return 0;
}