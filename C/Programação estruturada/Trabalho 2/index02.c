#include <stdio.h>
char Alunos[20][50];
int TotalAluno = 0;
int presentes = 0;
int ausentes = 0;
int reconhecimento = 0;

void Menu(){
	printf("----------------------------------------\n");
	printf("1 - Cadastrar aluno\n");
    printf("2 - Fazer Reconhecimento\n");
    printf("3 - Relatorio\n");
    printf("4 - Sair\n");
    printf("Escolha: ");
}

void cadastrarAluno() {
    if(TotalAluno == 20) {
        printf("Valor Máximo\n");
        return;
    }
    printf("Nome: ");
    scanf("%49s", Alunos[TotalAluno]); 
    TotalAluno++;
    printf("Aluno Cadastrado\n");
}

void Reconhecimento() {
    for(int e = 0; e < TotalAluno; e++) {
        printf("Nome: %s\n", Alunos[e]);
        printf("Rosto reconhecido?\n");
        printf("1 - Sim\n");
        printf("2 - Não\n");
        printf("Escolha: ");
        scanf("%d", &reconhecimento);
        printf("----------------------------------------\n");
        
        if(reconhecimento == 1) {
            presentes++;
        } else if(reconhecimento == 2) {
            ausentes++;
        } 
    }
    printf("Reconhecimento Feito\n");
}

void Resultado(){
	printf("Alunos presentes: %d\n", presentes);
    printf("Alunos ausentes: %d\n", ausentes);
}
int main(){
	int opcao = 0;
	while(opcao != 4){
		Menu();
        scanf("%d", &opcao);
       
        switch(opcao){
        	case 1:
        	    cadastrarAluno();
        		break;
        	case 2:
        		Reconhecimento();
        		break;
        	case 3:
        		Resultado();
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