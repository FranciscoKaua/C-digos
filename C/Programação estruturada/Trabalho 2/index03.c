#include <stdio.h>
int TotalAulas = 30;
int AulasPresente;
float percentual;
    
void Texto() {
    printf("Periodo: %d dias\n", TotalAulas);
    printf("Presenca exigida: %.2d%%\n", 70);
}

int verificarQuantAula(){
	if(AulasPresente< 0 || AulasPresente > TotalAulas) {
        printf("Numero de aulas deve estar entre 0 e %d\n", TotalAulas);
        return -1; 
	}
	return 0;
}

float calcPorcento(int presentes, int total) {
    return (presentes * 100.0) / total;
}

void Situacao(float percentual) {
    if(percentual >= 75.0) {
        printf("Situacao: Presenca SATISFATORIA\n");
    } else {
        printf("Situacao: Presenca INSATISFATORIA\n");
    }
}
int main(){
    Texto();
    printf("Quantas aulas o aluno esteve presente:  ");
    scanf("%d", &AulasPresente);
    
    verificarQuantAula();
    percentual = calcPorcento(AulasPresente, TotalAulas);
    
    printf("---------------------------------------------------------\n");
    printf("Aulas presentes: %d\n", AulasPresente);
    printf("Aulas ausentes: %d\n", TotalAulas - AulasPresente);
    printf("Percentual de presenca: %.2f%%\n", percentual);  
    printf("---------------------------------------------------------\n");
    
    Situacao(percentual);
    
	return 0;
}