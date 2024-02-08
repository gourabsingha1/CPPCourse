#include <iostream>
#include <string>
using namespace std;

// ## OOPs Recap and Nesting of member functions


// OOPs - classes and objects

// C++ --> initially called --> "C with classes" by stroustroup
// class --> entension of structures (in C)
// structures had limitations
//      - members are public
//      - no methods
// classes --> structures + more
// classes --> can have methods and properties
// classes --> can make few members as private & few as public
// structures in C++ are typedef
// you can declare objects along with the class declaration like this
/* class Employee{
    // Class definition
} gourab, abhoy, harshita; */
// gourab.salary = 8 makes no sense if salary is private



class binary {
    string s; // By default it is private
    // void chk_bin(); // No one can access chk_bin from outside

public:
    void read(); // reads data
    void chk_bin(); // checks if binary
    void ones_compliment(); // interchanges 1 and 0
    void display(); // displays number
    void Display(); // displays number
};

void binary::read() {
    cout << "Enter a binary number" << endl;
    cin >> s;
}

void binary::chk_bin() {
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] != '0' && s[i] != '1')
        {
            cout << "Incorrect binary format" << endl;
            exit(0);
        }
    }
}

void binary::ones_compliment() {
    // chk_bin(); // Nesting of member functions
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '0')
        {
            s[i] = '1';
        }
        else
        {
            s[i] = '0';
        }
    }
}

void binary::display() {
    cout << "Displaying your binary number " << endl;
    for (int i = 0; i < s.length(); i++)
    {
        cout << s[i];
    }
    cout << endl;
}

void binary::Display() {
    cout << "Displaying your binary number after interchanging " << endl;
    for (int i = 0; i < s.length(); i++)
    {
        cout << s[i];
    }
    cout << endl;
}

int main() {
    binary b;
    b.read();
    b.chk_bin();
    b.display();
    b.ones_compliment();
    b.Display();

    return 0;
}