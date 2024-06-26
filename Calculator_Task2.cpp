#include <iostream>
using namespace std;

class Calc{
public:                                                         //I am using double for it. and only 2 numbers
    double add(double a, double b){
        return a+b;
    }
    
    double subtract(double a, double b){
        return a-b;
    }

    double multiply(double a, double b) {
        return a * b;
    }

    double divide(double a, double b) {
        if (b != 0)
            return a /b;
        else {
            cerr << "Error: Division by zero!" << endl;
            return 0;
        }
    }
};

int main() {
    Calc c;
    double n1, n2;
    char operation;

    cout << "Enter First No.: ";
    cin >> n1;
    cout << "Enter Second No.: ";
    cin >> n2;
    cout << "Enter the operator (+, -, *, /): ";
    cin >> operation;

    if (operation == '+' ){
        cout << "Result: " << c.add(n1, n2) << endl;
    }

    else if (operation == '-'){
        cout << "Result: " << c.subtract(n1, n2) << endl;
    }

    else if (operation == '*'){
        cout << "Result: " << c.multiply(n1, n2) << endl;
    }

    else if (operation == '/'){
        cout << "Result: " << c.divide(n1, n2) << endl;
    }
        
    else{
        cout << "Error: Invalid operator!" << endl;
    }   
}
