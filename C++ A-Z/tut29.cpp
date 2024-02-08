#include<iostream>
using namespace std;

// ## Constructors in C++

// Constructor is a special function with same name as the class
// It is used to initialize the objects of its class

/* Characteristics of Constructors
1. It should be declared in the public section of the class
2. It is automatically invoked whenever an object is created
3. It cannot return values and it doesn't have return types
4. It can have default arguments
5. We cannot refer to their address
*/

class Complex {
    int a, b;
public:
    Complex(); // constructor declaration
    void printNumber() {
        cout<<"Your number is "<<a<<" + "<<b<<"i "<<endl;
    }
};

Complex::Complex() { // this is a default constructor as it takes no parameters
    a = 3;
    b = 4;
    cout<<"Hello world"<<endl;
} 

int main() {
    Complex c;
    c.printNumber();

    return 0;
}