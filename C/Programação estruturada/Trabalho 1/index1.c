#include <stdio.h>
int main(){
	int opcao = 0;
	int MaxPadrinho = 10;
	char NomePadrinho[MaxPadrinho][50];
	int MatriculaPadrinho[MaxPadrinho];
	int QuantidadeAfilhados[MaxPadrinho];
	
	char NomeAfilhado[MaxPadrinho][MaxPadrinho][50];
	int MatriculaAfilhado[MaxPadrinho][MaxPadrinho];
	int TotalPadrinho = 0;
	
     while(opcao != 3){
     	printf("----------------------------------------------\n");
     	printf("1 - Cadastrar padrinho\n");
     	printf("2 - Listar padrinhos\n");
     	printf("3 - Sair\n");
     	printf("Escolha: ");
     	scanf("%d", &opcao);
     	printf("----------------------------------------------\n");
     	
     	
     	switch(opcao){
     		case 1:
     			if(TotalPadrinho < MaxPadrinho){
                    printf("Nome do padrinho: ");
                    scanf("%s", NomePadrinho[TotalPadrinho]);
                    printf("Matricula do padrinho: ");
                    scanf("%d", &MatriculaPadrinho[TotalPadrinho]);
                    
                    printf("Quantidade de afilhados: ");
                    scanf("%d", &QuantidadeAfilhados[TotalPadrinho]);
                    
                    if(QuantidadeAfilhados[TotalPadrinho] > 2){
                    	printf("Só pode até 2 Afilhados");
                    }else{
		            	  for(int a = 0; a < QuantidadeAfilhados[TotalPadrinho]; a++){
		                        printf("----------------------------------------------\n");
		                        printf("Nome do afilhado %d: ", a + 1);
		                        scanf("%s", NomeAfilhado[TotalPadrinho][a]); 
		                        printf("Matricula do afilhado %d: ", a + 1);
		                        scanf("%d", &MatriculaAfilhado[TotalPadrinho][a]); 
		                    }
		                    TotalPadrinho ++;
		                    printf("Cadastro Realizado!");
                    }
                    
                } else {
                    printf("Limite máximo atingido!\n");
                }
     			break;
     			
     		case 2:
     			for(int i = 0; i < TotalPadrinho; i++) {
     			   printf("----------------------------------------------\n");
                    printf("Padrinho %d:\n", i + 1);
                    printf("  Nome: %s\n", NomePadrinho[i]);
                    printf("  Matricula: %d\n", MatriculaPadrinho[i]);
                    printf("  Afilhados: %d\n", QuantidadeAfilhados[i]);
                    for(int a = 0; a < QuantidadeAfilhados[i];a++){
                    	printf("Afilhado %d\n", a +1);
                    	printf("  Nome: %s\n", NomeAfilhado[i][a]);
                    	printf("  Matricula: %d\n", MatriculaAfilhado[i][a]);
                    }
     			}
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