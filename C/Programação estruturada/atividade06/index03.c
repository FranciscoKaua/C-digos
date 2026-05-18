#include <stdio.h>

long int quant_equivalente(int n_horas, char tipo){
    switch(tipo){
        case 'h':
            return n_horas;
            break;
        case 'm': 
            return n_horas * 60;
            break;
        case 's':
            return n_horas * 3600;  
            break;
        default:
            return -1;  
    }
}

int main()
{
    int horas;
    char tipo;
    
    printf("Horas: ");
    scanf("%d", &horas);
    printf("Tipo: ");
    scanf(" %c", &tipo);  
    
    printf("Quantidade equivalente: %ld", quant_equivalente(horas, tipo)); 
    return 0;
}