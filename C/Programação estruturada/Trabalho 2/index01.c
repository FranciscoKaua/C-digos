#include <stdio.h>
 int MaxPadrinho = 10;
char NomePadrinho[10][50];
int MatriculaPadrinho[10];
int QuantidadeAfilhados[10];
	
char NomeAfilhado[10][2][50];
int MatriculaAfilhado[10][2];
int TotalPadrinho = 0;

void Menu() {
    printf("----------------------------------------------\n");
    printf("1 - Cadastrar padrinho\n");
    printf("2 - Listar padrinhos\n");
    printf("3 - Sair\n");
    printf("Escolha: ");
}

void cadastrarAfilhado(int index) {
    for(int a = 0; a < QuantidadeAfilhados[index]; a++) {
        printf("----------------------------------------------\n");
        printf("Nome do afilhado %d: ", a + 1);
        scanf("%s", NomeAfilhado[index][a]);
        
        printf("Matricula do afilhado %d: ", a + 1);
        scanf("%d", &MatriculaAfilhado[index][a]);
    }
}

void cadastrarPadrinho() {
    if(TotalPadrinho < MaxPadrinho) {
        printf("----------------------------------------------\n");
        printf("Nome do padrinho: ");
        scanf("%s", NomePadrinho[TotalPadrinho]);
        
        printf("Matricula do padrinho: ");
        scanf("%d", &MatriculaPadrinho[TotalPadrinho]);
        
        printf("Quantidade de afilhados: ");
        scanf("%d", &QuantidadeAfilhados[TotalPadrinho]);
        
        if(QuantidadeAfilhados[TotalPadrinho] > 2) {
            printf("Só pode ter até 2 afilhado\n");
        } else {
            cadastrarAfilhado(TotalPadrinho);
            TotalPadrinho++;
            printf("Cadastro feito\n");
        }
    } else {
        printf("Limite máximo atingido\n");
    }
}

void listaPadrinho(){
	for(int i = 0; i < TotalPadrinho; i++) {
        printf("----------------------------------------------\n");
        printf("Padrinho %d:\n", i + 1);
        printf("  Nome: %s\n", NomePadrinho[i]);
        printf("  Matricula: %d\n", MatriculaPadrinho[i]);
        printf("  Quantidade de Afilhados: %d\n", QuantidadeAfilhados[i]);
        
        for(int a = 0; a < QuantidadeAfilhados[i]; a++) {
            printf("  Afilhado %d:\n", a + 1);
            printf("    Nome: %s\n", NomeAfilhado[i][a]);
            printf("    Matricula: %d\n", MatriculaAfilhado[i][a]);
        }
	}
}

int main(){
     int opcao = 0;
     while(opcao != 3){
     	Menu();
     	scanf("%d", &opcao);
     	
     	switch(opcao){
     		case 1:
                cadastrarPadrinho();
     			break;
     		case 2:
     			listaPadrinho();
     			break;
     		case 3:
     			printf("Saindo...");
     			break;
     		default:
     			printf("Erro");
     			break;
     	}
     }
     return 0;
}
