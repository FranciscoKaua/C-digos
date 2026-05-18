#include "Complexo.hpp"
#include <iostream>
#include <cmath>
Complexo::Complexo(double r, double i): real(r), img(i){}


Complexo Complexo::operator+(const Complexo& c) const{
    return Complexo(real + c.real, img + c.img);
}
Complexo Complexo::operator-(const Complexo& c) const{
    return Complexo(real - c.real, img - c.img);
}
Complexo Complexo::operator*(const Complexo& c) const{
    return Complexo(
        real * c.real - img * c.img,
        real * c.img + img * c.real
    );
}
Complexo Complexo::operator/(const Complexo& c) const{
    double deno = c.real * c.real + c.img * c.img;

    return Complexo(
        (real * c.real + img * c.img) / deno,
        (img * c.real - real * c.img) / deno
    );
}


Complexo& Complexo::operator+=(const Complexo& c) {
    real += c.real;
    img += c.img;
    return *this;
}

Complexo& Complexo::operator-=(const Complexo& c) {
    real -= c.real;
    img -= c.img;
    return *this;
}

Complexo& Complexo::operator*=(const Complexo& c) {
    *this = *this * c;
    return *this;
}

Complexo& Complexo::operator/=(const Complexo& c) {
    *this = *this / c;
    return *this;
}

bool Complexo::operator==(const Complexo& c) const {
    return real == c.real && img == c.img;
}

bool Complexo::operator!=(const Complexo& c) const {
    return !(*this == c);
}

Complexo& Complexo::operator++() {
    real++;
    img++;
    return *this;
}

Complexo Complexo::operator++(int) {
    Complexo temp = *this;
    ++(*this);
    return temp;
}

Complexo Complexo::operator-() const {
    return Complexo(-real, -img);
}

Complexo Complexo::operator~() const {
    return Complexo(real, -img);
}

std::ostream& operator<<(std::ostream& os, const Complexo& c) {
    os << c.real << " + " << c.img << "i";
    return os;
}

std::istream& operator>>(std::istream& is, Complexo& c) {
    is >> c.real >> c.img;
    return is;
}

Complexo::operator double() const {
    return std::sqrt(real*real + img*img);
}

double Complexo::getReal() const {
    return real;
}

double Complexo::getImg() const {
    return img;
}