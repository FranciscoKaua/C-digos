#include <stdio.h>
int main(){
	int opcao = 0;
	char Alunos[20][50];
	int TotalAluno = 0;
	int presentes = 0;
	int ausentes = 0;
	int reconhecimento = 0;
	
	while(opcao != 4){
		printf("----------------------------------------\n");
		printf("1 - Cadastrar aluno\n");
        printf("2 - Fazer Reconhecimento\n");
        printf("3 - Relatorio\n");
        printf("4 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);
       printf("----------------------------------------\n");
        
        switch(opcao){
        	case 1:
        		if(TotalAluno == 20){
        			printf("Valor Máximo");
        			break;
        		}
        		printf("Nome: ");
        		scanf("%s", &Alunos[TotalAluno]);
        		
        		TotalAluno ++;
        		printf("Aluno Cadastrado!");
        		break;
        	case 2:
        		for(int e = 0; e < TotalAluno; e++){
        			printf("Nome:  %s\n", Alunos[e]);
        			printf("Rosto reconhecido?\n");
        			printf("1 - Sim\n");
        			printf("2 - Não\n");
        			printf("Escolha: ");
        			scanf("%d", &reconhecimento);
        			printf("----------------------------------------\n");
        			if(reconhecimento == 1){
        				presentes ++;
        			}else if(reconhecimento == 2){
        				ausentes ++;
        			}
        		}
        		break;
        	case 3:
        			printf("Alunos presentes: %d\n", presentes);
        			printf("Alunos ausentes: %d\n", ausentes);
        		break;
        	case 4:
        		printf("Saindo...");
        		break;
        	default:
        		printf("Opcao invalida");
        		break;
        }
	}
	return 0;
}