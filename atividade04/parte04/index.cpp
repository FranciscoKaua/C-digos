#include <iostream>
using namespace std;

template <typename T>
class Caixa{
    private:
        T valor;
    public:
        void setValor(T valor){
            this->valor = valor;
        };
        
        T getValor() const{
            return valor;
        };
};

int main(){
	Caixa<int> c1;
    c1.setValor(5);
    cout<<c1.getValor() <<endl;

    Caixa<string> c2;
    c2.setValor("Ana");
    cout<<c2.getValor() <<endl;
	return 0;
}