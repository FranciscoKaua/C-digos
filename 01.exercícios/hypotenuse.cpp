#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double a;
    double b;
    
    cout <<"A: ";
    cin >> a;
    cout <<"B: ";
    cin >> b;
    
    double c = sqrt(pow(a,2)+pow(b,2));
    
    cout <<"Hypotenuse: "<< c;
    return 0;
}