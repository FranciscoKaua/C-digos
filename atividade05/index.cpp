#include <iostream>
#include <string>
#include <vector>
using namespace std;

class CityCar{
    public:
        
};

class Car{
    public:
        virtual void insert(string marca, int ocupantes);
};

class Truck{
    public:
        virtual void insert(int quantEixos, float pesoSuportado);
};

int main(){
    char op;
    while (true){
        cout<<"***Car Rental Management***"<<endl;
        cout<<"P = Add a passanger car"<<endl;
        cout<<"T = Add a truck"<<endl;
        cout<<"D = Display all cars"<<endl;
        cout<<"Q = Quit"<<endl;
        cout<<"Your choise: "<<endl;
        cin>>op;

        switch (op){
        case 'p':
            
            break;
        case 't':
            /* code */
            break;
        case 'd':
            /* code */
            break;
        case 'q':
            /* code */
            break;
        
        default:
            break;
        }
    }
    return 0;
}