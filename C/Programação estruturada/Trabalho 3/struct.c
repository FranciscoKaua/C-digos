#include <stdio.h>
#include <string.h>
struct Dados{
    char nome[30];
    int idade;
};

int main() {
    struct Dados pessoa ;
    
    strcpy(pessoa.nome, "Daniel");
    pessoa.idade = 20;
  
  
    printf("Nome: %s\n", pessoa.nome);
    printf("Idade: %d\n", pessoa.idade);
    
    return 0;
}