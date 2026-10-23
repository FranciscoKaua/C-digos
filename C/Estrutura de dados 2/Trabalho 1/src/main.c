#include <stdio.h>
#include <stdlib.h>

#include "../include/Matriz.h"
#include "../include/Lista.h"
#include "../include/bfs.h"


int main()
{
    int opcao;
    int inicio;
    char arquivo[50] = "../dados/grafo_1.txt";

    printf("-----BIBLIOTECA DE GRAFOS----\n");
    
    printf("\nEscolha a representacao:\n");
    printf("1 - Matriz de adjacencia\n");
    printf("2 - Lista de adjacencia\n");
    printf("Opcao: ");

    scanf("%d", &opcao);


    if (opcao == 1) {

        GrafoMatriz *grafo =
            ler_grafo_matriz(arquivo);

        if (grafo == NULL)
            return 1;

        imprimir_informacoes_matriz(grafo);

        salvar_informacoes_matriz(
            grafo,
            "../resultados/informacoes_matriz.txt"
        );


        printf("\nDigite o vertice inicial da BFS: ");
        scanf("%d", &inicio);

        int *pai =
            malloc(grafo->num_vertices * sizeof(int));

        int *nivel =
            malloc(grafo->num_vertices * sizeof(int));


        bfs_matriz(
            grafo,
            inicio,
            pai,
            nivel
        );


        salvar_bfs_matriz(
            "../resultados/bfs_matriz.txt",
            grafo->num_vertices,
            pai,
            nivel
        );


        printf("\nBFS concluida!\n");
        printf("Resultado salvo em:\n");
        printf("resultados/bfs_matriz.txt\n");


        free(pai);
        free(nivel);

        liberar_grafo_matriz(grafo);
    }


    else if (opcao == 2) {

        GrafoLista *grafo =
            ler_grafo_lista(arquivo);

        if (grafo == NULL)
            return 1;

        imprimir_informacoes_lista(grafo);

        salvar_informacoes_lista(
            grafo,
            "../resultados/informacoes_lista.txt"
        );


        printf("\nDigite o vertice inicial da BFS: ");
        scanf("%d", &inicio);

        int *pai =
            malloc(grafo->num_vertices * sizeof(int));

        int *nivel =
            malloc(grafo->num_vertices * sizeof(int));


        bfs_lista(
            grafo,
            inicio,
            pai,
            nivel
        );


        salvar_bfs_lista(
            "../resultados/bfs_lista.txt",
            grafo->num_vertices,
            pai,
            nivel
        );


        printf("\nBFS concluida!\n");
        printf("Resultado salvo em:\n");
        printf("resultados/bfs_lista.txt\n");


        free(pai);
        free(nivel);

        liberar_grafo_lista(grafo);
    }


    else {

        printf("\nOpcao invalida!\n");

        return 1;
    }


    return 0;
}