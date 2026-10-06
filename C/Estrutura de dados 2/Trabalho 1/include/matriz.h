#ifndef MATRIZ_H
#define MATRIZ_H

typedef struct {
    int num_vertices;
    int num_arestas;
    int **matriz;
} GrafoMatriz;


GrafoMatriz *criar_grafo_matriz(int n);


void liberar_grafo_matriz(GrafoMatriz *grafo);


void adicionar_aresta_matriz(GrafoMatriz *grafo, int u, int v);

GrafoMatriz *ler_grafo_matriz(const char *nome_arquivo);
void imprimir_informacoes_matriz(GrafoMatriz *grafo);

void salvar_informacoes_matriz(GrafoMatriz *grafo, const char *nome_arquivo);

#endif