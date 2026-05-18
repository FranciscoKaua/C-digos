#include <stdio.h>
int main() {
    int n;
    long long zero = 0, um = 1, proximo;
    printf("Digite: ");
    scanf("%d", &n);
    
    for(int }i = 0; i < n; i++) {
        if(i <= 1) {
            proximo = i; 
        } else {
            proximo = zero + um;
            zero = um;
            um = proximo;
        }
        printf("%lld ", proximo);
    }
    
    printf("\n");
    return 0;
}