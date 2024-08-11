#include <iostream>
using namespace std;

// ## Protected access modifier

class Base {
protected: // Can be inherited
    int a;
private:
    int b; // Cannot be inherited
};

/* For a protected member:
                            Public derivation   Private derivation  Protected derivation
    1. Private members      Not inherited       Not inherited       Not inherited
    2. Protected members    Protected           Private             Protected
    3. Public members       Public              Private             Protected
*/

class Derived : protected Base {

};

int main() {
    Base b;
    Derived d;
    // cout << b.a; // Will not work since a is protected in Base class
    // cout << d.a; // Will not work since a is protected in Derived class

    return 0;
}