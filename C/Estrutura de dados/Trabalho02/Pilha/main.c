#include <stdio.h>
#include "Pilha.h"
int main(){
    Pilha livros;
    iniciar(&livros);
    
    int opcao;
    char livro[50];
    do {
        printf("---------------\n");
        printf("PILHA DE LIVROS:\n");
        printf("1 - Adicionar livro\n");
        printf("2 - Retirar livro\n");
        printf("3 - Mostrar pilha\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                printf("Nome do livro: ");
                scanf(" %49[^\n]", livro);
                inserir(&livros, livro);
                printf("Livro adicionado!\n");
                break;
                
            case 2:
                remover(&livros);
                printf("Livro removido!\n");
                break;
                
            case 3:
                printf("---------------\n");
                printf("Livros na pilha:\n");
                imprimir(&livros);
                break;

            case 0:
                printf("Encerrando programa...\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }

    } while(opcao != 0);

	return 0;
}