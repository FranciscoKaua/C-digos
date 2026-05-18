#include <stdio.h>
#include <stdlib.h> 
int main(){
	int total = 1000;
	int maiorSaldo = total;
	int rodadas = 0;
	int aposta = 0;
	int continuar;
	int NumJogador = 0;

	
	while(1){
		printf("Seu slado: %d\n", total);
		printf("Aposte: ");
		scanf("%d", &aposta);
		
		if(aposta < 0 || aposta > total){
			printf("Sem dinheiro\n");
		}else{
			printf("Advinhe o número de 1 a 10: ");
			scanf("%d", &NumJogador);
			
			int Bot = rand()%10 + 1;
		
			if(NumJogador == Bot){
				printf("Acertou!\n");
				total = total + aposta * 10;
			}else{
				printf("Errou!\n");
				total = total - aposta;
			}
			if(total > maiorSaldo){
				maiorSaldo = total;
			}
			rodadas ++;
			printf("Quer continuar?1 para sim, 0 para não: ");
			scanf("%d", &continuar);
			if(continuar == 0){
				printf("Seu saldo total: %d\n", total);
				printf("Total de Rodadas: %d\n", rodadas);
				printf("Seu maior saldo: %d", maiorSaldo);
				break;
			}else{
				if(total > 0){
					continue;
				}else{
					printf("Sem saldo\n");
					printf("Seu saldo total: %d\n", total);
				printf("Total de Rodadas: %d\n", rodadas);
				printf("Seu maior saldo: %d", maiorSaldo);
					break;
				}
			}
		}
		
		
	}
	
}