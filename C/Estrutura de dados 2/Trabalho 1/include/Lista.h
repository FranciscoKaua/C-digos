#ifndef LISTA_H
#define LISTA_H

typedef struct No {
    int vertice;
    struct No *prox;
} No;

typedef struct {
    int num_vertices;
    int num_arestas;
    No **lista;
} GrafoLista;

GrafoLista *criar_grafo_lista(int n);

void liberar_grafo_lista(GrafoLista *grafo);

void adicionar_aresta_lista(GrafoLista *grafo, int u, int v);

GrafoLista *ler_grafo_lista(const char *nome_arquivo);

void imprimir_informacoes_lista(GrafoLista *grafo);

void salvar_informacoes_lista(GrafoLista *grafo, const char *nome_arquivo);

#endif