#include <iostream>
using namespace std;

void trocar(int n1, int n2, int *a, int *b)
{
    *a = n2;
    *b = n1;
}
int main()
{
    int num1 = 5;
    int num2 = 10;

    cout << num1 << " e " <<num2<< "\n";
    trocar(num1,num2,&num1, &num2);
    cout << num1 << " e " <<num2<< "\n";
    return 0;
}