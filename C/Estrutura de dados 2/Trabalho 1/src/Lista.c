#include <stdio.h>
#include <stdlib.h>

#include "../include/Lista.h"


GrafoLista *criar_grafo_lista(int n)
{
    int i;

    GrafoLista *grafo = malloc(sizeof(GrafoLista));

    if (grafo == NULL)
        return NULL;

    grafo->num_vertices = n;
    grafo->num_arestas = 0;

    grafo->lista = malloc(n * sizeof(No *));

    if (grafo->lista == NULL) {
        free(grafo);
        return NULL;
    }

    for (i = 0; i < n; i++)
        grafo->lista[i] = NULL;

    return grafo;
}


void liberar_grafo_lista(GrafoLista *grafo)
{
    int i;

    if (grafo == NULL)
        return;

    for (i = 0; i < grafo->num_vertices; i++) {

        No *atual = grafo->lista[i];

        while (atual != NULL) {

            No *temp = atual;

            atual = atual->prox;

            free(temp);
        }
    }

    free(grafo->lista);
    free(grafo);
}


void adicionar_aresta_lista(GrafoLista *grafo, int u, int v)
{
    No *novo;

    if (grafo == NULL)
        return;

    u--;
    v--;

    if (u < 0 || u >= grafo->num_vertices ||
        v < 0 || v >= grafo->num_vertices)
        return;

    /* Adiciona v na lista de u */

    novo = malloc(sizeof(No));

    if (novo == NULL)
        return;

    novo->vertice = v;
    novo->prox = grafo->lista[u];

    grafo->lista[u] = novo;


    /* Adiciona u na lista de v */

    novo = malloc(sizeof(No));

    if (novo == NULL)
        return;

    novo->vertice = u;
    novo->prox = grafo->lista[v];

    grafo->lista[v] = novo;

    grafo->num_arestas++;
}


GrafoLista *ler_grafo_lista(const char *nome_arquivo)
{
    FILE *arquivo;

    int n;
    int u, v;

    arquivo = fopen(nome_arquivo, "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo: %s\n",
               nome_arquivo);
        return NULL;
    }

    if (fscanf(arquivo, "%d", &n) != 1) {
        fclose(arquivo);
        return NULL;
    }

    GrafoLista *grafo = criar_grafo_lista(n);

    if (grafo == NULL) {
        fclose(arquivo);
        return NULL;
    }

    while (fscanf(arquivo, "%d %d", &u, &v) == 2)
        adicionar_aresta_lista(grafo, u, v);

    fclose(arquivo);

    return grafo;
}


void imprimir_informacoes_lista(GrafoLista *grafo)
{
    int i;
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

        No *atual = grafo->lista[i];

        while (atual != NULL) {

            grau++;

            atual = atual->prox;
        }

        if (grau < grau_min)
            grau_min = grau;

        if (grau > grau_max)
            grau_max = grau;

        soma_graus += grau;
    }

    double grau_medio =
        (double)soma_graus / grafo->num_vertices;

    printf("\n===== INFORMACOES DO GRAFO =====\n");

    printf("Numero de vertices: %d\n",
           grafo->num_vertices);

    printf("Numero de arestas: %d\n",
           grafo->num_arestas);

    printf("Grau minimo: %d\n",
           grau_min);

    printf("Grau maximo: %d\n",
           grau_max);

    printf("Grau medio: %.2f\n",
           grau_medio);
}


void salvar_informacoes_lista(GrafoLista *grafo,
                              const char *nome_arquivo)
{
    FILE *arquivo;

    int i;
    int grau;

    int grau_min = 0;
    int grau_max = 0;
    int soma_graus = 0;

    if (grafo == NULL)
        return;

    arquivo = fopen(nome_arquivo, "w");

    if (arquivo == NULL) {
        printf("Erro ao criar arquivo.\n");
        return;
    }

    if (grafo->num_vertices > 0)
        grau_min = grafo->num_vertices;

    for (i = 0; i < grafo->num_vertices; i++) {

        grau = 0;

        No *atual = grafo->lista[i];

        while (atual != NULL) {

            grau++;

            atual = atual->prox;
        }

        if (grau < grau_min)
            grau_min = grau;

        if (grau > grau_max)
            grau_max = grau;

        soma_graus += grau;
    }

    double grau_medio =
        (double)soma_graus / grafo->num_vertices;

    fprintf(arquivo,
            "Numero de vertices: %d\n",
            grafo->num_vertices);

    fprintf(arquivo,
            "Numero de arestas: %d\n",
            grafo->num_arestas);

    fprintf(arquivo,
            "Grau minimo: %d\n",
            grau_min);

    fprintf(arquivo,
            "Grau maximo: %d\n",
            grau_max);

    fprintf(arquivo,
            "Grau medio: %.2f\n",
            grau_medio);

    fclose(arquivo);
}