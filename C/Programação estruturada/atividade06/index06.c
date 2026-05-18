#include <stdio.h>

void Entre(int x, int limite_inferior, int limite_superior){
    if(x >= limite_inferior && x <= limite_superior){
        printf("Está dentro do limite");
    }else{
        printf("Não está dentro do limite");
    }
}

int main()
{
    int num, superior, inferior;
    
    printf("Número: ");
    scanf("%d", &num);
    printf("Limite superior: ");
    scanf("%d", &superior);
    printf("Limite inferior: ");
    scanf("%d", &inferior);
    
    Entre(num, inferior, superior);
    
    return 0;
}