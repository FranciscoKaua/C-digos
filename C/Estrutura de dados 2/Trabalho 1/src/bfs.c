#include <stdio.h>
#include <stdlib.h>

#include "../include/bfs.h"


void bfs_matriz(GrafoMatriz *grafo,
                int inicio,
                int *pai,
                int *nivel)
{
    int n = grafo->num_vertices;

    int *visitado = calloc(n, sizeof(int));
    int *fila = malloc(n * sizeof(int));

    int inicio_fila = 0;
    int fim_fila = 0;

    int i;

    inicio--;

    for (i = 0; i < n; i++) {
        pai[i] = -1;
        nivel[i] = -1;
    }

    visitado[inicio] = 1;

    pai[inicio] = -1;
    nivel[inicio] = 0;

    fila[fim_fila++] = inicio;

    while (inicio_fila < fim_fila) {

        int atual = fila[inicio_fila++];

        for (i = 0; i < n; i++) {

            if (grafo->matriz[atual][i] == 1 &&
                !visitado[i]) {

                visitado[i] = 1;

                pai[i] = atual;

                nivel[i] = nivel[atual] + 1;

                fila[fim_fila++] = i;
            }
        }
    }

    free(visitado);
    free(fila);
}


void bfs_lista(GrafoLista *grafo,
               int inicio,
               int *pai,
               int *nivel)
{
    int n = grafo->num_vertices;

    int *visitado = calloc(n, sizeof(int));
    int *fila = malloc(n * sizeof(int));

    int inicio_fila = 0;
    int fim_fila = 0;

    int i;

    inicio--;

    for (i = 0; i < n; i++) {
        pai[i] = -1;
        nivel[i] = -1;
    }

    visitado[inicio] = 1;

    pai[inicio] = -1;
    nivel[inicio] = 0;

    fila[fim_fila++] = inicio;

    while (inicio_fila < fim_fila) {

        int atual = fila[inicio_fila++];

        No *vizinho = grafo->lista[atual];

        while (vizinho != NULL) {

            int v = vizinho->vertice;

            if (!visitado[v]) {

                visitado[v] = 1;

                pai[v] = atual;

                nivel[v] = nivel[atual] + 1;

                fila[fim_fila++] = v;
            }

            vizinho = vizinho->prox;
        }
    }

    free(visitado);
    free(fila);
}


void salvar_bfs_matriz(const char *arquivo,
                       int n,
                       int *pai,
                       int *nivel)
{
    FILE *fp = fopen(arquivo, "w");

    if (fp == NULL) {
        printf("Erro ao criar arquivo BFS.\n");
        return;
    }

    fprintf(fp, "Vertice\tPai\tNivel\n");

    for (int i = 0; i < n; i++) {

        fprintf(fp, "%d\t", i + 1);

        if (pai[i] == -1)
            fprintf(fp, "-\t");
        else
            fprintf(fp, "%d\t", pai[i] + 1);

        fprintf(fp, "%d\n", nivel[i]);
    }

    fclose(fp);
}


void salvar_bfs_lista(const char *arquivo,
                      int n,
                      int *pai,
                      int *nivel)
{
    FILE *fp = fopen(arquivo, "w");

    if (fp == NULL) {
        printf("Erro ao criar arquivo BFS.\n");
        return;
    }

    fprintf(fp, "Vertice\tPai\tNivel\n");

    for (int i = 0; i < n; i++) {

        fprintf(fp, "%d\t", i + 1);

        if (pai[i] == -1)
            fprintf(fp, "-\t");
        else
            fprintf(fp, "%d\t", pai[i] + 1);

        fprintf(fp, "%d\n", nivel[i]);
    }

    fclose(fp);
}