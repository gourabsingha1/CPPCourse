#include <iostream>
using namespace std;

// ## Inheritance syntax and visibility mode

// Base class
class Employee {
public:
    int id;
    float salary;

    Employee() {}

    Employee(int inpId) {
        id = inpId;
        salary = 34.04;
    }
};

// Derived class syntax
/*
class {{derived-class-name}} : {{visibility-mode}} {{base-class-name}}
{
    members/methods/etc
};
Note:
1. Visibility mode = public --> public members of the base class becomes public members of the Derived class
2. Visibility mode = private --> public members of the base class becomes private members of the Derived class
3. Default Visibility mode is private
4. Derived classes cannot inherit private members of base classes
*/

// Creating a Programmer class derived from Employee Base class
class Programmer : public Employee {
public:
    int languageCode;

    Programmer(int inpId) {
        id = inpId;
        languageCode = 9;
    }

    void getData() {
        cout << id << endl;
    }
};

int main()
{
    Employee gourab(1), parthiv(2);
    cout << gourab.salary << endl;
    cout << parthiv.salary << endl;
    
    Programmer skillF(10);
    cout << skillF.languageCode << endl;
    cout << skillF.id << endl; // If Visibility mode is private then this will throw an error
    skillF.getData();

    return 0;
}