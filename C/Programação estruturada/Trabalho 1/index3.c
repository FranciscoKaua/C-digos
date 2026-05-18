#include <stdio.h>
int main(){
	int TotalAulas = 30; 
    int AulasPresente;
    float percentual;
    
    printf("Periodo: %d dias\n", TotalAulas);
    printf("Presenca exigida: 75 porcento\n");
    
    printf("Numero de aulas em que o aluno esteve presente: ");
    scanf("%d", &AulasPresente);
    
    if(AulasPresente < 0 || AulasPresente > 30) {
        printf("Numero de aulas deve estar entre 0 e 30\n");
        return 1;
    }
    
    percentual = (AulasPresente * 100.0) / TotalAulas;
    printf("---------------------------------------------------------\n");
    printf("Aulas presentes: %d\n", AulasPresente);
    printf("Aulas ausentes: %d\n", TotalAulas - AulasPresente);
    printf("Percentual de presenca: %.2f%%\n", percentual);  
    printf("---------------------------------------------------------\n");
    
    if(percentual >= 75.0) {
        printf("Situacao: Presenca SATISFATORIA\n");
    } else {
        printf("Situacao: Presenca INSATISFATORIA\n");
    }
    
	return 0;
}