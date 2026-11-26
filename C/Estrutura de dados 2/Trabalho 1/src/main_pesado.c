#define _POSIX_C_SOURCE 200809L
#include "../include/Pesado.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <float.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

static double seconds(void) {
    return (double)clock() / CLOCKS_PER_SEC;
}

/* Calcula distancias e caminhos minimos */
static int query(const char *file, int source, const char *out) {

    GrafoP *g = grafo_p_ler(file);

    if (!g) {
        fprintf(stderr, "Nao foi possivel ler o grafo.\n");
        return 1;
    }

    double *d = malloc((size_t)g->n * sizeof(double));
    int *p = malloc((size_t)g->n * sizeof(int));

    if (!d || !p) {
        grafo_p_liberar(g);
        free(d);
        free(p);
        return 1;
    }

    int r = dijkstra(g, source, DIJKSTRA_HEAP, d, p);
    if (r == -1) {

        puts("Dijkstra nao suporta pesos negativos nesta biblioteca.");
        r = 1;

    } else if (r) {
        FILE *f = out ? fopen(out, "w") : stdout;
        if (!f) {
            perror(out);
            r = 0;

        } else {
            fprintf(f, "Origem %d\n", source);
            fprintf(f, "Destino\tDistancia\tCaminho\n");            for (int v = 1; v <= g->n; v++) {
                fprintf(f, "%d\t", v);
                if (d[v - 1] == DBL_MAX) {
                    fprintf(f, "infinito\tsem caminho\n");

                } else {
                    fprintf(f, "%.10g\t", d[v - 1]);
                    int path[g->n];
                    int k = 0;
                    int x = v - 1;

                    while (x != -1 && k < g->n) {
                        path[k++] = x;
                        x = p[x];
                    }
                    for (int i = k - 1; i >= 0; i--) {
                        fprintf(f, "%s%d",
                                i == k - 1 ? "" : " -> ",
                                path[i] + 1);
                    }

                    fputc('\n', f);
                }
            }
            if (out) {
                fclose(f);
                printf("Resultado salvo em: %s\n", out);            }
        }
    }
    free(d);
    free(p);
    grafo_p_liberar(g);
    return r ? 0 : 1;
}

/* Compara Dijkstra com vetor e heap */
int bench(const char *arquivo, int k, const char *saida) {
    GrafoP *g = grafo_p_ler(arquivo);
    if (!g || k <= 0) {
        fprintf(stderr, "Arquivo/k invalido\n");
        grafo_p_liberar(g);
        return 1;
    }

    double *d = malloc((size_t)g->n * sizeof(double));
    int *p = malloc((size_t)g->n * sizeof(int));
    if (!d || !p) {

        free(d);
        free(p);
        grafo_p_liberar(g);
        return 1;
    }

    double sum[2] = {0, 0};
    srand((unsigned)time(NULL));
    for (int j = 0; j < k; j++) {
        int s = rand() % g->n + 1;
        for (int m = 1; m <= 2; m++) {
            double t = seconds();
            int r = dijkstra(g, s, (MetodoDijkstra)m, d, p);
            sum[m - 1] += seconds() - t;
            if (r <= 0) {

                fprintf(stderr, "Erro durante Dijkstra.\n");
                free(d);
                free(p);
                grafo_p_liberar(g);

                return 1;
            }
        }
    }

    FILE *f = fopen(saida, "w");

    if (f == NULL) {

        perror("Erro ao criar arquivo");

        free(d);
        free(p);
        grafo_p_liberar(g);

        return 1;
    }

    fprintf(f,
        "Grafo: %s | V=%d E=%d | k=%d\n"
        "Vetor: %.6f s total, %.6f s media\n"
        "Heap:  %.6f s total, %.6f s media\n",
        arquivo, g->n, g->m, k,
        sum[0], sum[0] / k,
        sum[1], sum[1] / k
    );

    fclose(f);

    printf("Benchmark salvo em: %s\n", saida);

    free(d);
    free(p);
    grafo_p_liberar(g);

    return 0;
}

/* Programa principal */
int main(void) {

    char arquivo[] = "../dados/rede_colaboracao.txt";

    int origem = 10;
    int k = 5;

    /* Cria a pasta de resultados */
    mkdir("resultados2", 0777);

    printf("=== GRAFOS PONDERADOS ===\n\n");

    printf("Arquivo: %s\n", arquivo);
    printf("Vertice de origem: %d\n\n", origem);

    printf("1 - Calcular caminhos minimos\n");
    printf("2 - Executar benchmark\n");

    int opcao;

    printf("\nEscolha: ");

    if (scanf("%d", &opcao) != 1) {
        printf("Entrada invalida!\n");
        return 1;
    }

    if (opcao == 1) {

        return query(
            arquivo,
            origem,
            "resultados2/dijkstra_10.txt"
        );
    }

    if (opcao == 2) {

        return bench(
            arquivo,
            k,
            "resultados2/benchmark.txt"
        );
    }

    printf("Opcao invalida!\n");

    return 1;
}