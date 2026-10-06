#include <iostream> 
using namespace std;
int main(){
    int opcao;
    do{
        cout << "------------------\n";
        cout << "1-Explorar\n";
        cout << "2-Ver status\n";
        cout << "3-Inventario\n";
        cout << "4-Loja\n";
        cout << "5-Salvar\n";
        cout << "6-Sair\n";
        cout << "Opção: \n";
        cin>>opcao;
        
    }while(opcao!=0);
    return 0;
}