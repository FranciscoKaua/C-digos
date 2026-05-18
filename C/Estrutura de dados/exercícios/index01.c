#include <stdio.h>
#include <string.h>
typedef struct{
    int idade;
    char nome[50];
    float nota;
}Aluno;

int main() {
    Aluno a1;
    strcpy(a1.nome, "kaua");
    a1.idade = 21;
    a1.nota = 8.5;
    
    printf("Nome: %s\n", a1.nome);
    printf("Idade: %d\n", a1.idade);
    printf("Nota: %.1f\n", a1.nota);
    return 0;
}