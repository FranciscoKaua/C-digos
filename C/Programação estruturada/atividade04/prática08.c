#include <stdio.h>

int main() {
    int n;
    float S = 0.0;
    printf("Digite um valor: ");
    scanf("%d", &n);
    printf("S = ");
    for (int i = 1; i <= n; i++) {
        S += 1.0 / i;
        if (i == 1) {
            printf("1");
        } else {
            printf(" + 1/%d", i);
        }
    }
    printf("\n\nResultado: S = %.6f\n", S);
    
    return 0;
}