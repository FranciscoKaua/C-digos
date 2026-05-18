#include <iostream>

using namespace std;

const double TAXA_IMPOSTO_FEDERAL = 0.14;
const double TAXA_IMPOSTO_ESTADUAL = 0.05;
const double TAXA_PREVIDENCIA_SOCIAL = 0.06;
const double VALOR_SINDICATO_SEMANAL = 10.;
const double ADICIONAL_SEGURO_SAUDE = 35.;
const double VALOR_HORA_TRABALHADA = 16.78;

double retornaSalarioBruto(int horasTrabalhadas) {
    return horasTrabalhadas * VALOR_HORA_TRABALHADA;
}

double retornaImpostoFederal(double salarioBruto) {
    return salarioBruto * TAXA_IMPOSTO_FEDERAL;
}

double retornaImpostoEstadual(double salarioBruto) {
    return salarioBruto * TAXA_IMPOSTO_ESTADUAL;
}

double retornaPrevidenciaSocial(double salarioBruto) {
    return salarioBruto * TAXA_PREVIDENCIA_SOCIAL;
}

double retornaAdicionalSeguroSaude(int numeroDependentes) {
    if (numeroDependentes >= 3) {
        return ADICIONAL_SEGURO_SAUDE;
    }
    return 0;
}

double retornaValorDeImposto(double salarioBruto) {
    return salarioBruto * (TAXA_IMPOSTO_ESTADUAL + TAXA_IMPOSTO_FEDERAL);
}

int main() {
    int horasTrabalhadas;
    int numeroDependentes;

    cout << "Digite o número de horas trabalhadas: ";
    cin >> horasTrabalhadas;
    cout << "Digite o número de dependentes: ";
    cin >> numeroDependentes;

    double salarioBruto = retornaSalarioBruto(horasTrabalhadas);

    double impostoFederal = retornaImpostoFederal(salarioBruto);
    double impostoEstadual = retornaImpostoEstadual(salarioBruto);
    double previdenciaSocial = retornaPrevidenciaSocial(salarioBruto);

    double adicionalSeguroSaude = retornaAdicionalSeguroSaude(numeroDependentes);
    
    double salarioLiquido = salarioBruto - impostoFederal - impostoEstadual - previdenciaSocial - VALOR_SINDICATO_SEMANAL - adicionalSeguroSaude;

    double valorDeImposto = retornaValorDeImposto(salarioBruto);

    cout << "Salário Bruto: " << salarioBruto << endl;
    cout << "Imposto Federal: " << impostoFederal << endl;
    cout << "Imposto Estadual: " << impostoEstadual << endl;
    cout << "Previdência Social: " << previdenciaSocial << endl;
    cout << "Adicional Seguro Saúde: " << adicionalSeguroSaude << endl;
    cout << "Salário Líquido: " << salarioLiquido << endl;
    cout << "Valor de Imposto: " << valorDeImposto << endl;

    return 0;
}