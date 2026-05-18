#include <stdio.h>
void contRegressiva(int n) {
    if (n < 0) {
        printf("Fim\n");
        return;
    }
    printf("%d\n", n);
    contRegressiva(n - 1);
}

int main() {
    printf("Contagem regressiva:\n");
    contRegressiva(5);
    return 0;
}