#include<iostream>
using namespace std;

// ## Parameterized and Default Constructors

class Complex{
    int a, b;
public:
    Complex(int x, int y){ // this is parameterized constructor as it accepts two parameters
        a = x;
        b = y;
        cout<<"Hello world"<<endl;
    }
    void printNumber(){
        cout<<"Your number is "<<a<<" + "<<b<<"i "<<endl;
    }
};

int main(){
    // Implicit call
    Complex a(4, 6);
    a.printNumber();
    
    // Explicit call
    Complex b = Complex(5, 7);
    b.printNumber();
    
    return 0;
}