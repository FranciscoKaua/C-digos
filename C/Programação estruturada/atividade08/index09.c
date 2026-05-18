#include <stdio.h>
void trocar(int *x, int *y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int main() {
    int a, b;
    printf("Digite o valor a: ");
    scanf("%d", &a);
    
    printf("Digite o valor b: ");
    scanf("%d", &b);
  
    trocar(&a, &b);
    
    printf("\nTroca:\n");
    printf("a = %d\n", a);
    printf("b = %d\n", b);
    
    return 0;
}