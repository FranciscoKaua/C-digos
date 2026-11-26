#ifndef PESADO_H
#define PESADO_H
#include <stddef.h>

typedef struct ArestaP {
    int destino;
    double peso;
    struct ArestaP *prox;
} ArestaP;
typedef struct {
    int n, m;
    ArestaP **adj;
} GrafoP;
typedef enum {
    DIJKSTRA_VETOR = 1,
    DIJKSTRA_HEAP = 2
} MetodoDijkstra;

GrafoP *grafo_p_criar(int n);
void grafo_p_liberar(GrafoP *g);
int grafo_p_adicionar(GrafoP *g, int u, int v, double peso);

GrafoP *grafo_p_ler(const char *arquivo);
int dijkstra(
    const GrafoP *g,
    int origem,
    MetodoDijkstra metodo,
    double *dist,
    int *pai
);

void dijkstra_imprimir_caminho(
    int destino,
    const double *dist,
    const int *pai,
    int n
);

int bench(const char *arquivo, int k, const char *saida);

#endif
