#ifndef CAR_HPP
#define CAR_HPP

#include <string>

class Car {
private:
    std::string brand;
    int year;

public:
    Car(std::string brand, int year);
    void display() const;
};

#endif