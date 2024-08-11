#include <iostream>
using namespace std;

// ## Ambiguity Resolution in inheritance

class Base1 {
public:
    void greet(void) {
        cout << "How are you?" << endl;
    }
};

class Base2 {
public:
    void greet(void) {
        cout << "Kaise ho?" << endl;
    }
};

class Derived : public Base1, public Base2 {
    int a;

public:
    void greet() {
        Base1::greet(); // Calls greet function of Base1
    }
};

class B {
public:
    void say() {
        cout << "Hello world" << endl;
    }
};

class D : public B {
    int a; // D's new say() method will overide base class' say() method
    
public:
    void say() {
        cout << "Hello my beautiful people" << endl;
    }
};

int main()
{
    // // Ambiguity 1
    // Base1 base1obj;
    // Base2 base2obj;
    // base1obj.greet();
    // base2obj.greet();
    // Derived d;
    // d.greet();

    // Ambiguity 2
    B b;
    b.say();
    D d;
    d.say();

    return 0;
}