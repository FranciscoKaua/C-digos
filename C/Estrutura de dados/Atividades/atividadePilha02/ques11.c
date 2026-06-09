typedef struct No{
    int valor;
    struct No *ant;
    struct No *prox;
}No;

typedef struct{
    No *inicio;
    No *fim;
    int qtd;
}Fila;
void iniciar(Fila *f);
int vazio(Fila *f);
int inserir(Fila *f, int valor);
int remover(Fila *f, int *valor);
int primeiro(Fila *f, int *valor);
int ultimo(Fila *f, int *valor);
int tamanho(Fila *f);
void imprimir(Fila *f);
void destruir(Fila *f);