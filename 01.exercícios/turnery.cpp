#include <iostream>

int main() {
    double grade;
    std::cout << "Your grade: ";
    std::cin >> grade;
    
    grade >= 7.0 ? std::cout<<"Aproved" : std::cout <<"failed";
    return 0;
}