#include <iostream>
using namespace std;

struct Lista {
    int dados[50];
    int tamanho;
};

void inicializar(Lista &l) {
    l.tamanho = 0;
}

bool vazia(Lista l) {
    return l.tamanho == 0;
}

bool inserir(Lista &l, int valor) {
    if (l.tamanho >= 50) {
        return false;
    }
    l.dados[l.tamanho] = valor;
    l.tamanho++;
    return true;
}

bool remover(Lista &l, int i) {
    if (i < 0 || i >= l.tamanho) {
        return false;
    }

    for (int j = i; j < l.tamanho - 1; j++) {
        l.dados[j] = l.dados[j + 1];
    }

    l.tamanho--;
    return true;
}
