#include <iostream>
using namespace std;

class Ponto{
    private:
        float x;
        float y;
    public:
        Ponto(float x, float y):x(x), y(y){};
        
        Ponto operator+(Ponto& p){
            return Ponto(x + p.x, y + p.y);
        };
        
        friend ostream& operator<<(ostream& os, const Ponto& p){
        os << "(" << p.x << ", " << p.y << ")";
        return os;
        };
};


int main(){
	Ponto p1(2,3);
	Ponto p2(1,2);
	
	Ponto p3 = p1 + p2;
	
	cout<<p3;
	return 0;
}