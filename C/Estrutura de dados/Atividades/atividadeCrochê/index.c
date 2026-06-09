#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct No {
    char carreira[MAX];
    struct No *prox;
} No;

typedef struct {
    No *inicio;
    int qtd;
} Lista;

void iniciar(Lista *l) {
    l->inicio = NULL;
    l->qtd = 0;
}

void inserirFinal(Lista *l, char texto[]) {
    No *novo = (No *) malloc(sizeof(No));
    if(novo == NULL)
        return;
    strcpy(novo->carreira, texto);
    novo->prox = NULL;
    if(l->inicio == NULL) {
        l->inicio = novo;
    } else {
        No *aux = l->inicio;
        while(aux->prox != NULL)
            aux = aux->prox;

        aux->prox = novo;
    }

    l->qtd++;
}

char simbolo(char ponto) {
    switch(ponto) {
        case 'C': return 'o'; 
        case 'B': return '.'; 
        case 'P': return 'x'; 
        case 'M': return 'T'; 
        case 'A': return 'I'; 

        default: return '?';
    }
}

void exibirGrafico(Lista *l) {
    No *aux = l->inicio;
    while(aux != NULL) {
        for(int i = 0; aux->carreira[i] != '\0'; i++) {
            printf("%c ", simbolo(aux->carreira[i]));
        }
        printf("\n");
        aux = aux->prox;
    }
}

int main() {
    Lista grafico;
    iniciar(&grafico);

    int n;
    char carreira[MAX];

    printf("Quantidade de carreiras: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {

        printf("\nCarreira %d\n", i + 1);
        printf("Digite a sequencia:\n");
        printf("C=Corrente\n");
        printf("B=Baixissimo\n");
        printf("P=Ponto Baixo\n");
        printf("M=Meio Ponto Alto\n");
        printf("A=Ponto Alto\n");

        scanf("%s", carreira);

        inserirFinal(&grafico, carreira);
    }

    exibirGrafico(&grafico);

    return 0;
}