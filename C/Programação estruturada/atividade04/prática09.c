#include <stdio.h>
int main(){
	int num;
	int total = 1;
	printf("Digite: ");
    scanf("%d", &num);
    for(int i = num; i >= 1; i--){
    	printf("%d x ", i);
    	total = total * i;
    }
    printf(" = %d", total);
	return 0;
}