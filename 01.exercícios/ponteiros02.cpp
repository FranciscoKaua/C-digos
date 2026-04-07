#include <iostream>

int maior(int *n1, int *n2){
    if(*n1 > *n2){
        return *n1;
    }
    return *n2;
}
int main(){
	int n1 = 15;
	int n2 = 8;
	
	std::cout <<maior(&n1,&n2);
	return 0;
}