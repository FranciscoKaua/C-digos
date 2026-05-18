#ifndef COMPLEXO_HPP
#define COMPLEXO_HPP
#include <iostream>
#include <cmath>
class Complexo{
    private:
        double real;
        double img;
    public:
        Complexo(double r, double i);
        
        Complexo operator+(const Complexo& c) const;
        Complexo operator-(const Complexo& c) const;
        Complexo operator*(const Complexo& c) const;
        Complexo operator/(const Complexo& c) const;
        
        Complexo& operator+=(const Complexo& c);
        Complexo& operator-=(const Complexo& c);
        Complexo& operator*=(const Complexo& c);
        Complexo& operator/=(const Complexo& c);
        
        bool operator==(const Complexo& c) const;
        bool operator!=(const Complexo& c) const;
        
        Complexo& operator++();
        Complexo operator++(int);
        Complexo& operator--();
        Complexo operator--(int);
        
        Complexo operator-() const;
        Complexo operator~() const;
        
        friend std::ostream& operator<<(std::ostream& os, const Complexo& c);
        friend std::istream& operator>>(std::istream& is, Complexo& c);
        
        operator double() const;
        
        double getReal() const;
        double getImg() const;
    
};

#endif