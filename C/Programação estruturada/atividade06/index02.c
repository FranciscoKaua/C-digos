#include <stdio.h>
long int n_segundos(int horas){
    return horas*3600;
}
int main()
{
    int hora;
    printf("horas: ");
    scanf("%d", &hora);
    printf("segundos: %d",n_segundos(hora));
    return 0;
}
