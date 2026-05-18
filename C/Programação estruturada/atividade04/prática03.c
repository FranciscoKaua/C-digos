#include <stdio.h>
int main(){
	int voto = 0;
	int nulo = 0;
	int branco= 0;
	int Jose = 0;
	int Carlos = 0;
	int Neves = 0;
	int totalVoto = 0;
	
	while(1){
		printf("1. Candidato José Queiroz\n");
		printf("2. Candidato Carlos Marques\n");
    	printf("3. Candidato Neves Rocha\n");
		printf("4. Nulo\n");
		printf("5. Branco\n");
		printf("Entre com o seu voto: ");
		scanf("%d", &voto);
		
		switch(voto){
			case 1:
				printf("Você votou no José\n");
				Jose++;
				break;
			case 2:
				printf("Você votou no Carlos\n");
				Carlos++;
				break;
			case 3:
				printf("Você votou no Neves\n");
				Neves++;
				break;
			case 4:
				printf("Votou nulo\n");
				nulo++;
				break;
			case 5:
				printf("Você votou branco\n");
				branco;
				break;
		}
		
		if(voto == 6){
			char ganhador[20];
			if(Jose >= Carlos && Jose >= Neves){
				sprintf(ganhador, "José");
			}else if(Carlos >= Jose && Carlos >= Neves){
				sprintf(ganhador, "Carlos");
			}else{
					sprintf(ganhador, "Neves");
			}
			totalVoto = nulo + branco + Jose + Carlos + Neves;
			
			float PorcenNulo = ((float)nulo * 100)/totalVoto;
			float PorcenBranco = ((float)branco * 100 )/ totalVoto;
			printf("José: %d\n", Jose);
			printf("Carlos: %d\n", Carlos);
			printf("Neves: %d\n", Neves);
			printf("Porcentagm de voto nulo: %.2f\n", PorcenNulo);
			printf("Porcentagm de voto branco: %.2f\n", PorcenBranco);
			printf("Vencedor: %s\n",  ganhador);
			break;
		}
	}
	
	return 0;
}