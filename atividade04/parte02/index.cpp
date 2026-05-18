#include <iostream>
using namespace std;

int somar(int a, int b){
    return a + b;
}

int somar(int a, int b, int c){
    return a + b + c;
}

float somar(float a, float b){
    return a + b;
}

int main(){
	cout<<somar(8,2) <<endl;
	cout<<somar(3,5,2) <<endl;
	cout<<somar(2.5f,2.5f);
	return 0;
}