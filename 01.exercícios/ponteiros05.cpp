#include <iostream>
using namespace std;
int main(){
	int num;
	cout<<"Qual o tamanho: ";
	cin >> num;
	int *vetor = new int[num];
	
	for(int a = 0; a < num; a++){
	    cout<<"Numero "<<a<<endl;
	    cin>>vetor[a];
	}
	for(int a = 0; a < num; a++){
	    cout<<vetor[a]<< endl;
	}
	
	delete[] vetor;
	return 0;
}