#include <iostream>
using namespace std;

// ## classes, public, private access modifiers

class Employee // A class is a template to create objects. e.g. class = human, object = Employee
               // Memories allocate in objects and objects have thier own variables
{
private: // When not mentioned anything, by default it is private
    int a, b, c;
    string name;

public:
    int d, e;
    void setData(int a1, int b1, int c1, string name1); // takes data
    void getData() // prints data
    {
        cout << "The value of a is " << a << endl;
        cout << "The value of b is " << b << endl;
        cout << "The value of c is " << c << endl;
        cout << "The value of d is " << d << endl;
        cout << "The value of e is " << e << endl;
        cout << "The name of the employee is " << name << endl;
    }
};

void Employee::setData(int a1, int b1, int c1, string name1)
{
    a = a1;
    b = b1;
    c = c1;
    name = name1;
}

int main()
{
    Employee gourab;
    // gourab.a = 134; // This will throw error as a is private
    gourab.d = 34;
    gourab.e = 89;
    gourab.setData(1, 2, 4, "GourabSingha");
    gourab.getData();

    return 0;
}