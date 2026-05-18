#include <stdio.h>
void numero(int num){
    if(num > 0){
        printf("positivo");
    }else{
        printf("negativo");
    }
}
int main()
{
    int num;
    printf("Digite um número: ");
    scanf("%d", &num);
    numero(num);
    return 0;
}