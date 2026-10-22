#ifndef BFS_H
#define BFS_H

#include "Matriz.h"
#include "Lista.h"

void bfs_matriz(GrafoMatriz *grafo, int inicio,
                int *pai, int *nivel);

void bfs_lista(GrafoLista *grafo, int inicio,
               int *pai, int *nivel);
               
void salvar_bfs_matriz(const char *arquivo,
                       int n, int *pai, int *nivel);

void salvar_bfs_lista(const char *arquivo,
                      int n, int *pai, int *nivel);

#endif