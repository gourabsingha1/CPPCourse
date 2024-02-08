#include<iostream>
using namespace std;

// ## Constructor overloading
/*
1. Multiple constructors within one class
2. Whichever constructor matches with the arguements, it will execute
*/

class Complex{
    int a, b;
public:
    Complex() { // constructor 1
        a = 0;
        b = 0;
    }
    Complex(int x, int y) { // constructor 2
        a = x;
        b = y;
    }
    Complex(int x) { // constructor 3
        a = x;
        b = 0;
    }
    void printNumber(){
        cout<<"Your number is "<<a<<" + "<<b<<"i "<<endl;
    }
};


int main(){
 
    Complex c1(4, 6); // constructor 2
    c1.printNumber();
    Complex c2(5); // constructor 3
    c2.printNumber();
    Complex c3; // constructor 1
    c3.printNumber();

    return 0;
}