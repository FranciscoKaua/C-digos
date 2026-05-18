#include <stdio.h>
int absoluto(int num){
    return num;
}
int main()
{
    int num;
    printf("Digite um num: ");
    scanf("%d", &num);
    
    printf("%d",absoluto(num));
    return 0;
}