#include<iostream>
using namespace std;

// ## Copy constructor

class Number {
    int a = 0;
public:
    Number() {}
    Number (int num) {
        a = num;
    }
    // When no copy constructor is found, compiler supplies its own copy constructor
    Number (Number& obj) {
        cout<<"Copy constructor called!"<<endl;
        a = obj.a;
    }
    void display() {
        cout<<"The number for this object is "<<a<<endl;
    }
};

int main(){
    Number x, y, z(45), z2;
    x.display(), y.display(), z.display();

    Number z1(z); // Copy constructor invoked
    z1.display(); // z1 should exactly resemble z or x or y

    z2 = z; // Copy constructor not called because the object is already made

    Number z3 = z; // Copy constructor invoked
    z3.display();

    return 0;
}