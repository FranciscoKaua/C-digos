#include <iostream>
using namespace std;
int main() {
    int number1;
    int number2;
    char operation;
    
    cout << "Click (+-*/): ";
    cin >> operation;
    cout <<"First number: ";
    cin >> number1;
    cout <<"Second number: ";
    cin >> number2;
    
    switch(operation){
        case '+':
            cout << number1<<" + "<<number2<<" = "<<number1 + number2;
            break;
        case '-':
            cout << number1<<" - "<<number2<<" = "<<number1 - number2;
            break;
        case '*':
            cout << number1<<" x "<<number2<<" = "<<number1 * number2;
            break;
        case '/':
            cout << number1<<" / "<<number2<<" = "<<(double)number1 / number2;
            break;
        default:
            cout <<"Just valid operations";
            break;
        
    }
    return 0;
}