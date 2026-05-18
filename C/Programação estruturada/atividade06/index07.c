#include <stdio.h>
void quadrado(int x, int y){
    if(x == y*y){
        printf("Verdade");
    }else{
        printf("Falso");
    }
}
int main()
{
    int x;
    int y;
    printf("Digite o 1: ");
    scanf("%d", &x);
    printf("Digite o 2: ");
    scanf("%d", &y);
    
    quadrado(x, y);
    return 0;
}