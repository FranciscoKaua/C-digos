#include <iostream>
using namespace std;

void dobra(int *n, int tamanho){
    for(int a = 0; a < tamanho; a++){
        *(n + a) = *(n + a) * 2;
    }
}
int main(){
	int num;
	cout<<"Qual o tamanho: ";
	cin >> num;
	int *vetor = new int[num];
	
	for(int a = 0; a < num; a++){
	    cout<<"Numero "<<a<<endl;
	    cin>>vetor[a];
	}
	
	dobra(vetor, num);
	for(int a = 0; a < num; a++){
	    cout<<"Num "<<vetor[a]<< endl;
	}
	
	delete[] vetor;
	return 0;
}