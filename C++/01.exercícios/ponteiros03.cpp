#include <iostream>
using namespace std;
int main(){
	int*num = new int;
	cout<<"Digitei um num: ";
	cin >> *num;
	cout<<*num;
	
	delete num;

	return 0;
}