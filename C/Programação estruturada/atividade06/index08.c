#include <stdio.h>
#include <math.h>

float VAL(float x, int n, float t) {
    float denominador = powf(1.0f + t, n);
    return x / denominador;
}

int main() {
    float n1,n3;
    int n2;
    printf("Fluxo de caixa: ");
    scanf("%f", &n1);
    printf("Números de anos: ");
    scanf("%d", &n2);
    printf("Taxa:  ");
    scanf("%f", &n3);
    
    printf("Resultado: %.2f", VAL(n1,n2,n3));
    
    
    return 0;
}