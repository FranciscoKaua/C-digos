#include <stdio.h>
#include "index.h"
int main() {
    No *raiz = NULL;
    int opcao, matricula;
    
    do{
        printf("-----------------\n");
        printf("SISTEMA DE ALUNOS:\n");
        printf("1 - Inserir matricula de aluno\n");
        printf("2 - Buscar matricula de aluno\n");
        printf("3 - Mostrar matriculas\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                printf("Matricula: ");
                scanf("%d", &matricula);
                raiz = inserir(raiz, matricula);
                printf("Aluno cadastrado!\n");
                break;

            case 2:
                printf("Matricula para buscar: ");
                scanf("%d", &matricula);
                if (buscar(raiz, matricula))
                    printf("Aluno encontrado!\n");
                else
                    printf("Aluno nao encontrado!\n");
                break;

            case 3:
                printf("Matriculas cadastradas:\n");
                emOrdem(raiz);
                printf("\n");
                break;

            case 0:
                printf("Encerrando...\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }

    }while(opcao != 0);
    liberar(raiz);

    return 0;
}