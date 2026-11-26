#include "../include/Pesado.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

GrafoP *grafo_p_criar(int n) {
    if (n <= 0)
        return NULL;
    GrafoP *g = calloc(1, sizeof(*g));
    if (!g)
        return NULL;
    g->n = n;
    g->adj = calloc((size_t)n, sizeof(*g->adj));

    if (!g->adj) {
        free(g);
        return NULL;
    }
    return g;
}

void grafo_p_liberar(GrafoP *g) {
    if (!g)
        return;
    for (int i = 0; i < g->n; i++) {
        ArestaP *a = g->adj[i];
        while (a) {
            ArestaP *t = a;
            a = a->prox;
            free(t);
        }
    }
    free(g->adj);
    free(g);
}

int grafo_p_adicionar(GrafoP *g, int u, int v, double w) {
    if (!g || u < 1 || u > g->n || v < 1 || v > g->n || !isfinite(w))
        return 0;
    ArestaP *a = malloc(sizeof(*a));
    ArestaP *b = malloc(sizeof(*b));

    if (!a || !b) {
        free(a);
        free(b);
        return 0;
    }
    a->destino = v - 1;
    a->peso = w;
    a->prox = g->adj[u - 1];
    g->adj[u - 1] = a;

    b->destino = u - 1;
    b->peso = w;
    b->prox = g->adj[v - 1];
    g->adj[v - 1] = b;

    g->m++;

    return 1;
}

GrafoP *grafo_p_ler(const char *nome) {
    FILE *f = fopen(nome, "r");
    if (!f) {
        perror(nome);
        return NULL;
    }

    int n, u, v;
    double w;
    if (fscanf(f, "%d", &n) != 1 || n <= 0) {
        fclose(f);
        return NULL;
    }

    GrafoP *g = grafo_p_criar(n);
    if (!g) {
        fclose(f);
        return NULL;
    }
    while (1) {
        int r = fscanf(f, "%d %d %lf", &u, &v, &w);
        if (r == EOF)
            break;

        if (r != 3 || !grafo_p_adicionar(g, u, v, w)) {
            grafo_p_liberar(g);
            fclose(f);
            return NULL;
        }
    }

    fclose(f);
    return g;
}

typedef struct {
    int v;
    double d;
} Item;

typedef struct {
    Item *a;
    int size, cap;
} Heap;

static int less(Item x, Item y) {
    return x.d < y.d;
}

static int push(Heap *h, Item x) {
    if (h->size == h->cap) {
        int c = h->cap ? h->cap * 2 : 64;
        Item *p = realloc(h->a, (size_t)c * sizeof(*p));
        if (!p)
            return 0;

        h->a = p;
        h->cap = c;
    }

    int i = h->size++;
    while (i) {
        int p = (i - 1) / 2;
        if (!less(x, h->a[p]))
            break;
        h->a[i] = h->a[p];
        i = p;
    }

    h->a[i] = x;
    return 1;
}

static Item pop(Heap *h) {
    Item ret = h->a[0];
    Item x = h->a[--h->size];
    int i = 0;

    while (2 * i + 1 < h->size) {
        int c = 2 * i + 1;
        if (c + 1 < h->size && less(h->a[c + 1], h->a[c]))
            c++;
        if (!less(h->a[c], x))
            break;

        h->a[i] = h->a[c];
        i = c;
    }

    if (h->size)
        h->a[i] = x;
    return ret;
}

int dijkstra(const GrafoP *g, int origem, MetodoDijkstra metodo,
             double *dist, int *pai) {
    if (!g || origem < 1 || origem > g->n || !dist || !pai ||
        (metodo != 1 && metodo != 2))
        return 0;

    for (int i = 0; i < g->n; i++) {
        for (ArestaP *a = g->adj[i]; a; a = a->prox) {
            if (a->peso < 0)
                return -1;
        }
    }

    char *feito = calloc((size_t)g->n, 1);
    if (!feito)
        return 0;

    for (int i = 0; i < g->n; i++) {
        dist[i] = DBL_MAX;
        pai[i] = -1;
    }

    dist[origem - 1] = 0;
    Heap h = {0};

    if (metodo == 2 && !push(&h, (Item){origem - 1, 0})) {
        free(feito);
        return 0;
    }

    for (int iter = 0; iter < g->n; iter++) {
        int u = -1;
        double du = DBL_MAX;

        if (metodo == 1) {
            for (int i = 0; i < g->n; i++) {
                if (!feito[i] && dist[i] < du) {
                    du = dist[i];
                    u = i;
                }
            }
        } else {
            while (h.size) {
                Item x = pop(&h);
                if (!feito[x.v] && x.d == dist[x.v]) {
                    u = x.v;
                    du = x.d;
                    break;
                }
            }
        }

        if (u < 0)
            break;
        feito[u] = 1;
        for (ArestaP *a = g->adj[u]; a; a = a->prox) {
            int v = a->destino;
            double nd = du + a->peso;

            if (!feito[v] && nd < dist[v]) {
                dist[v] = nd;
                pai[v] = u;
                if (metodo == 2 &&
                    !push(&h, (Item){v, nd})) {
                    free(h.a);
                    free(feito);
                    return 0;
                }
            }
        }
    }
    free(h.a);
    free(feito);
    return 1;
}

void dijkstra_imprimir_caminho(int destino, const double *dist,
                               const int *pai, int n) {
    int v = destino - 1;
    if (v < 0 || v >= n) {
        puts("vertice invalido");
        return;
    }
    if (dist[v] == DBL_MAX) {
        printf("%d: sem caminho (distancia infinita)\n", destino);
        return;
    }
    int *p = malloc((size_t)n * sizeof(int));
    if (!p) {
        puts("memoria insuficiente");
        return;
    }
    int k = 0;
    while (v != -1 && k < n) {
        p[k++] = v;
        v = pai[v];
    }
    printf("distancia=%.10g caminho=", dist[destino - 1]);
    for (int i = k - 1; i >= 0; i--) {
        printf("%s%d", i == k - 1 ? "" : " -> ", p[i] + 1);
    }
    putchar('\n');
    free(p);
}