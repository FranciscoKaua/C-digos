#include <stdio.h>
int main() {
    int numero;
    int dentro_intervalo = 0;
    int fora_intervalo = 0;
    
    for (int i = 1; i <= 10; i++) {
        printf("Digite: ");
        scanf("%d", &numero);
        
        if (numero >= 10 && numero <= 20) {
            dentro_intervalo++;
        } else {
            fora_intervalo++;
        }
    }
    printf("Dentro do intervalo: %d\n", dentro_intervalo);
    printf("Fora do intervalo: %d\n", fora_intervalo);
    
    return 0;
}