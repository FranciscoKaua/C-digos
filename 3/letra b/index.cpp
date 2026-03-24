#include <iostream>
using namespace std;

struct Node {
    int valor;
    Node* prox;
};

struct Lista {
    Node* inicio;
};

void iniciar(Lista &l) {
    l.inicio = NULL;
}

bool vazia(Lista l) {
    if (l.inicio == NULL) {
        return true;
    } else {
        return false;
    }
}

void inserir(Lista &l, int valor) {
    Node* novo = new Node;
    novo->valor = valor;
    novo->prox = NULL;

    if (l.inicio == NULL) {
        l.inicio = novo;
    } else {
        Node* aux = l.inicio;

        while (aux->prox != NULL) {
            aux = aux->prox;
        }

        aux->prox = novo;
    }
}

void remover(Lista &l, int i) {
    if (l.inicio == NULL) {
        cout << "Lista vazia\n";
        return;
    }

    Node* aux = l.inicio;
    Node* ant = NULL;

    if (i == 0) {
        l.inicio = aux->prox;
        delete aux;
        return;
    }

    int cont = 0;

    while (aux != NULL && cont < i) {
        ant = aux;
        aux = aux->prox;
        cont++;
    }

    if (aux == NULL) {
        cout << "Posicao invalida\n";
        return;
    }

    ant->prox = aux->prox;
    delete aux;
}

bool buscar(Lista l, int valor) {
    Node* aux = l.inicio;

    while (aux != NULL) {
        if (aux->valor == valor) {
            return true;
        }
        aux = aux->prox;
    }

    return false;
}