#include <iostream>
#include <string>
using namespace std;

template <typename T>
T maior(T a, T b){
    if(a > b){
        return a;
    }else{
        return b;
    }
}

int main(){
	cout<<maior(8,2) <<endl;
	cout<<maior(2.5, 2.9) <<endl;
	cout<<maior("Ana", "João");
	return 0;
}