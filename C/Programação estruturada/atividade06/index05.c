#include <stdio.h>
int impar(int x){
    
    if(x % 2 != 0){
        return 1;
    }else{
        return 0;
    }
}
int main()
{
    int num;
    printf("Digite um número: ");
    scanf("%d",&num);
    
    if(impar(num)){
        printf("Verdade");
    }else{
        printf("Falso");
    }
    
    return 0;
}