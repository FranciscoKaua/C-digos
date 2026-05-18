#include <iostream>
using namespace std;
int main() {
    int day;
    
    cout << "Day(1-7): ";
    cin >> day;
    
    switch(day){
        case 1:
            cout <<"it's sunday";
            break;
        case 2:
            cout <<"it's monday";
            break;
        case 3:
            cout <<"it's tuesday";
            break;
        case 4:
            cout <<"it's wednesday";
            break;
        case 5:
            cout <<"it's thusday";
            break;
        case 6:
            cout <<"it's friday";
            break;
        case 7:
            cout <<"it's saturday";
            break;
        default:
            cout <<"just numbers(1-7)";
            break;
    }
    return 0;
}