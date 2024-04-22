#include <iostream>
#include <cmath>
using namespace std;


// **** 1. create a class Mark which contains the marks of 5 subjects and print the student details using constructor ****

class Mark {
    string name, enroll;
    float oops, daa, flat, maths, mpmc;
public:
    Mark(string name, string enroll, float oops, float daa, float flat, float maths, float mpmc) {
        this->name = name, this->enroll = enroll, this->oops = oops, this->daa = daa, this->flat = flat, this->maths = maths, this->mpmc = mpmc;
    }
    void display() {
        cout<<"Name: "<<name<<", Enroll: "<<enroll<<endl;
        cout<<"OOPS: "<<oops<<"\nDAA: "<<daa<<"\nFLAT: "<<flat<<"\nMaths: "<<maths<<"\nMPMC: "<<mpmc<<"\n\n";
    }
};



// **** 2. WAP to implement constructor overload ****

class ConstructorOverload {
public:
    ConstructorOverload() {}
    ConstructorOverload(int x, int n) {
        cout<<"pow("<<x<<", "<<n<<") = "<<pow(x, n)<<endl;
    }
    ConstructorOverload(string name) {
        cout<<"Name: "<<name<<endl;
    }
    ConstructorOverload(int age) {
        cout<<"Age: "<<age<<endl;
    }
};



// **** 3. using copy constructor, find values of three objects ****

class Example {
    int value;
public:
    Example(int v) {
        value = v;
    }
    Example(const Example& other) {
        value = other.value;
    }
    int getValue() {
        return value;
    }
};



// **** 4. addition of member of two different classes using friend function ****

class ClassB; // Forward declaration

class ClassA {
    int a;
public:
    ClassA(int x) {
        a = x;
    }
    friend int addMembers(ClassA, ClassB);
};

class ClassB {
    int b;
public:
    ClassB(int x) {
        b = x;
    }
    friend int addMembers(ClassA, ClassB);
};

int addMembers(ClassA obj1, ClassB obj2) {
    return (obj1.a + obj2.b);
}


int main() {
// 1)
    Mark student1("Gourab", "21UCS056", 15, 17, 14, 14, 11);
    student1.display();

// 2)
    ConstructorOverload co;
    ConstructorOverload co1(3, 4);
    ConstructorOverload co2("Gourab");
    ConstructorOverload co3(21); cout<<endl;
    
// 3)
    Example obj1(10); // Create object using constructor
    Example obj2(obj1); // Create object using copy constructor
    Example obj3 = obj1; // Create object using copy constructor (alternate syntax)
    cout << "Value of object 1: " << obj1.getValue() << endl;
    cout << "Value of object 2: " << obj2.getValue() << endl;
    cout << "Value of object 3: " << obj3.getValue() << endl;

// 4)
    ClassA o1(5);
    ClassB o2(10);
    int sum = addMembers(o1, o2);
    cout << "Sum of members: " << sum << endl;

    return 0;
}