#include <iostream>
#include "Car.hpp"
#include "Truck.hpp"

int main() {
    Car car("Toyota", 2022);
    Truck truck("Volvo FH", 18.5);

    std::cout << "=== Car ===" << std::endl;
    car.display();

    std::cout << std::endl;

    std::cout << "=== Truck ===" << std::endl;
    truck.display();

    return 0;
}