#include <iostream>
#include "Complexo.hpp"
int main(){

    Complexo c1(3, 4);
    Complexo c2(1, 2);
    
    Complexo soma = c1+c2;
    Complexo subtrai = c1-c2;
    

    std::cout<<soma.getReal()<<","<<soma.getImg()<<std::endl;
    std::cout<<subtrai.getReal()<<","<<subtrai.getImg();

    
    return 0;
}