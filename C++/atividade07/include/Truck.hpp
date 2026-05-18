#ifndef TRUCK_HPP
#define TRUCK_HPP

#include <string>

class Truck {
private:
    std::string model;
    double capacity;

public:
    Truck(std::string model, double capacity);
    void display() const;
};

#endif