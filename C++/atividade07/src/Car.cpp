#include <iostream>
#include "Car.hpp"

Car::Car(std::string brand, int year) {
    this->brand = brand;
    this->year = year;
}

void Car::display() const {
    std::cout << "Brand: " << brand << std::endl;
    std::cout << "Year: " << year << std::endl;
}