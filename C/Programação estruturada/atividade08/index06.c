#include <stdio.h>
#include <math.h>

void calc_esfera(float R, float *area, float *volume) {
    float p = 3.14;
    
    *area = 4 * p * powf(R, 2);
    
    *volume = (4.0f / 3.0f) * p * powf(R, 3);
}


int main() {
    float raio, area, volume;
    
    printf("Digite o raio da esfera: ");
    scanf("%f", &raio);
    
    calc_esfera(raio, &area, &volume);
    
    printf("\nRaio: %.2f:\n", raio);
    printf("Área: %.2f\n", area);
    printf("Volume: %.2f\n", volume);
    
    return 0;
}