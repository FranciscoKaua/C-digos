#include <stdio.h>
#include <stdlib.h>
#include "../include/matriz.h"

GrafoMatriz *criar_grafo_matriz(int n){
    int i, j;
    GrafoMatriz *grafo = malloc(sizeof(GrafoMatriz));

    if (grafo == NULL)
        return NULL;

    grafo->num_vertices = n;
    grafo->num_arestas = 0;
    grafo->matriz = malloc(n * sizeof(int *));

    if (grafo->matriz == NULL) {
        free(grafo);
        return NULL;
    }

    for (i = 0; i < n; i++) {

        grafo->matriz[i] = malloc(n * sizeof(int));

        if (grafo->matriz[i] == NULL) {

            for (j = 0; j < i; j++)
                free(grafo->matriz[j]);

            free(grafo->matriz);
            free(grafo);

            return NULL;
        }

        for (j = 0; j < n; j++)
            grafo->matriz[i][j] = 0;
    }

    return grafo;
}


void liberar_grafo_matriz(GrafoMatriz *grafo){
    int i;
    if (grafo == NULL)
        return;

    for (i = 0; i < grafo->num_vertices; i++)
        free(grafo->matriz[i]);

    free(grafo->matriz);
    free(grafo);
}


void adicionar_aresta_matriz(GrafoMatriz *grafo, int u, int v){
    if (grafo == NULL)
        return;

    u--;
    v--;

    if (u < 0 || u >= grafo->num_vertices ||
        v < 0 || v >= grafo->num_vertices)
        return;

    if (grafo->matriz[u][v] == 0) {

        grafo->matriz[u][v] = 1;
        grafo->matriz[v][u] = 1;

        grafo->num_arestas++;
    }
}


GrafoMatriz *ler_grafo_matriz(const char *nome_arquivo){
    FILE *arquivo;
    int n;
    int u, v;

    arquivo = fopen(nome_arquivo, "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo: %s\n", nome_arquivo);
        return NULL;
    }

    if (fscanf(arquivo, "%d", &n) != 1) {
        fclose(arquivo);
        return NULL;
    }

    GrafoMatriz *grafo = criar_grafo_matriz(n);

    if (grafo == NULL) {
        fclose(arquivo);
        return NULL;
    }

    while (fscanf(arquivo, "%d %d", &u, &v) == 2)
        adicionar_aresta_matriz(grafo, u, v);

    fclose(arquivo);

    return grafo;
}


void imprimir_informacoes_matriz(GrafoMatriz *grafo){
    int i, j;
    int grau;
    int grau_min = 0;
    int grau_max = 0;
    int soma_graus = 0;

    if (grafo == NULL)
        return;

    if (grafo->num_vertices > 0)
        grau_min = grafo->num_vertices;

    for (i = 0; i < grafo->num_vertices; i++) {

        grau = 0;

        for (j = 0; j < grafo->num_vertices; j++)
            grau += grafo->matriz[i][j];

        if (grau < grau_min)
            grau_min = grau;

        if (grau > grau_max)
            grau_max = grau;

        soma_graus += grau;
    }

    double grau_medio =
        (double)soma_graus / grafo->num_vertices;

    printf("\n===== INFORMACOES DO GRAFO =====\n");
    printf("Numero de vertices: %d\n", grafo->num_vertices);
    printf("Numero de arestas: %d\n", grafo->num_arestas);
    printf("Grau minimo: %d\n", grau_min);
    printf("Grau maximo: %d\n", grau_max);
    printf("Grau medio: %.2f\n", grau_medio);
}


void salvar_informacoes_matriz(GrafoMatriz *grafo,
                               const char *nome_arquivo){
    FILE *arquivo;

    int i, j;
    int grau;
    int grau_min = 0;
    int grau_max = 0;
    int soma_graus = 0;

    if (grafo == NULL)
        return;

    arquivo = fopen(nome_arquivo, "w");

    if (arquivo == NULL) {
        printf("Erro ao criar arquivo de saida.\n");
        return;
    }

    if (grafo->num_vertices > 0)
        grau_min = grafo->num_vertices;

    for (i = 0; i < grafo->num_vertices; i++) {

        grau = 0;

        for (j = 0; j < grafo->num_vertices; j++)
            grau += grafo->matriz[i][j];

        if (grau < grau_min)
            grau_min = grau;

        if (grau > grau_max)
            grau_max = grau;

        soma_graus += grau;
    }

    double grau_medio =
        (double)soma_graus / grafo->num_vertices;

    fprintf(arquivo, "Numero de vertices: %d\n",
            grafo->num_vertices);

    fprintf(arquivo, "Numero de arestas: %d\n",
            grafo->num_arestas);

    fprintf(arquivo, "Grau minimo: %d\n",
            grau_min);

    fprintf(arquivo, "Grau maximo: %d\n",
            grau_max);

    fprintf(arquivo, "Grau medio: %.2f\n",
            grau_medio);

    fclose(arquivo);
}