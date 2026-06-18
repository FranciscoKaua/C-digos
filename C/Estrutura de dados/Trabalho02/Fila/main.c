#include <stdio.h>
#include "Fila.h"
int main(){
	Fila clientes;
	iniciar(&clientes);
    
    int opcao;
    char nome[50];

    do{
        printf("---------------\n");
        printf("FILA DE SUPERMERCADO:\n");
        printf("1 - Entrar na fila\n");
        printf("2 - Atender cliente\n");
        printf("3 - Mostrar fila\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                printf("Nome do cliente: ");
                scanf(" %49[^\n]", nome);
                inserir(&clientes, nome);
                printf("Cliente adicionado!\n");
                break;
            case 2:
                remover(&clientes);
                printf("Cliente atendido!\n");
                break;
            case 3:
                printf("---------------\n");
                printf("Clientes na fila:\n");
                imprimir(&clientes);
                break;
            case 0:
                printf("Encerrando programa...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }

    }while(opcao != 0);

	return 0;
}