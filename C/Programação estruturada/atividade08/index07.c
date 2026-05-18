#include <stdio.h>
#include <math.h>
int raizes(float a, float b, float c, float *x1, float *x2) {
    float delta;
    if (a == 0) {
        return 0;  
    }
    
    delta = b * b - 4 * a * c;
    
    if (delta < 0) {
        return 0;
    }
    else if (delta == 0) {
        *x1 = -b / (2 * a);
        *x2 = *x1;  
        return 1;
    }
    else {
        *x1 = (-b + sqrtf(delta)) / (2 * a);
        *x2 = (-b - sqrtf(delta)) / (2 * a);
        return 2;
    }
}

int main() {
    
    return 0;
}