#include <iostream>
#include "Empresa.hpp"
int main(){
	Empresa e("Tecno");
	e.adicionarFuncionario(new Funcionario("Carlos", 1500));
	e.adicionarFuncionario(new Gerente("Carlos", 2000, 1000));
	
	e.calcularFolha();
	
	return 0;
}