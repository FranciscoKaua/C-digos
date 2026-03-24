#include <iostream>
using namespace std;

struct conta{
    string nome;
    int saldo;
}

conta criaConta(string nome){
    conta c;
    c.nome = nome;
    c.saldo = 0;
    return c;
}

string consultaNome(conta c){
    return c.nome;
}
int consultaSaldo(conta c){
    return c.saldo;
}

void depositar(conta c, int valor){
    if(valor > 0){
        c.saldo += valor;
    }
}

void sacar(conta c, int valor){
    if(valor > 0 && c.saldo >= valor){
        c.saldo -= c.saldo;
    }
}

struct Contas {
    Conta lista[50];
    int total;
};

void iniciaContas(Contas c) {
    c.total = 0;
}

void adicionarConta(Contas c, string nome) {
    if (c.total < MAX) {
        c.lista[c.total] = criarConta(nome);
        c.total++;
    }
}

Conta* consultarConta(Contas c, int indice) {
    if (indice >= 0 && indice < c.total) {
        return c.lista[indice];
    }
}

void transferencia(contas &c, int cont1, int cont2, int valor){
    Conta* origem = getConta(contas, conta1);
    Conta* destino = getConta(contas, conta2);

    if (origem != nullptr && destino != nullptr) {
        if (sacar(*origem, valor)) {
            depositar(*destino, valor);
            cout << "Transferência realizada com sucesso!\n";
        } else {
            cout << "Saldo insuficiente!\n";
        }
    } else {
        cout << "Conta inválida!\n";
    }
}

int main() {
    cout << "Hello, World!";
    return 0;
}