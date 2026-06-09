#include <stdio.h>
#include "Lista.h"

int main(){
    Lista tarefas;
    Lista mercado;
    Lista contatos;
    iniciar(&tarefas);
    iniciar(&mercado);
    iniciar(&contatos);
   
    int opcaoMenu = 0;
    int opcaoSubmenu = 0;
    char valor[50];
    
    while(opcaoMenu != 4){
        printf("\n--------------\n");
        printf("1- Lista de tarefas\n");
        printf("2- Lista de supermercado\n");
        printf("3- Lista de contatos\n");
        printf("4- Sair\n");
        printf("Opção: ");
        scanf("%d", &opcaoMenu);
        switch(opcaoMenu){
            case 1:
                menuSublista("tarefas");
                scanf("%d", &opcaoSubmenu);
                if(opcaoSubmenu == 1){
                    printf("Digite: ");
                    scanf(" %49[^\n]", valor);
                    adicionarFinal(&tarefas, valor);
                }else if(opcaoSubmenu == 2){
                    exibir(&tarefas);
                }
                break;
            case 2:
                menuSublista("supermercado");
                scanf("%d", &opcaoSubmenu);
                if(opcaoSubmenu == 1){
                    printf("Digite: ");
                    scanf(" %49[^\n]", valor);
                    adicionarFinal(&mercado, valor);
                }else if(opcaoSubmenu == 2){
                    exibir(&mercado);
                }
                break;
            case 3:
                menuSublista("contatos");
                scanf("%d", &opcaoSubmenu);
                if(opcaoSubmenu == 1){
                    printf("Digite: ");
                    scanf(" %49[^\n]", valor);
                    adicionarFinal(&contatos, valor);
                }else if(opcaoSubmenu == 2){
                    exibir(&contatos);
                }
                break;
            case 4:
                break;
            default:
                printf("Valor inválido");
        }
    }
    printf("Programa finalizado...");
    return 0;
}