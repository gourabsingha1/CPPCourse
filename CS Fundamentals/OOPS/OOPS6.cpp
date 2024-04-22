#include <iostream>
using namespace std;

// **** 1. WAP to read and print employee information using simple inheritance ****

class SuperEmployee {
protected:
    int code;
    string name, sector;
public:
    void hello() {
        cout<<"Enter name:\n";
        getline(cin, name);
        fflush(stdin);
        cout<<"Enter sector\n";
        getline(cin, sector);
        cout<<"Enter code\n";
        cin>>code;
        cout<<"Name: "<<name<<endl;
        cout<<"Sector: "<<sector<<endl;
        cout<<"Code: "<<code<<endl;
    }
};

class SubEmployee : public SuperEmployee {
public:
    void salary() {
        float sal;
        cout<<"Enter salary:\n";
        cin>>sal;
        cout<<"Salary:"<<sal<<endl;
        cout<<"Income tax: "<<sal * 20.0 / 100.0<<endl;
    }
};

// **** 2. WAP to demonstrate example of hierarchiral inheritance ****

class Animal1 {
public:
    void eat() {
        cout<<"Animal is eating"<<endl;
    }
};

class Dog1 : public Animal1 {
public:
    void bark() {
        cout<<"Dog is barking"<<endl;
    }
};

class Cat1 : public Animal1 {
public:
    void meow() {
        cout<<"Cat is meowing"<<endl;
    }
};


// **** 3. WAP to demonstrate example of multilevel inheritance ****

class Animal2 {
public:
    void eat() {
        cout << "Animal is eating." << endl;
    }
};

class Mammal2 : public Animal2 {
public:
    void breathe() {
        cout << "Mammal is breathing." << endl;
    }
};

class Dog2 : public Mammal2 {
public:
    void bark() {
        cout << "Dog is barking." << endl;
    }
};


int main() {
// 1)
    SubEmployee emp;
    emp.hello();
    emp.salary();
    cout<<endl;

// 2)
    Dog1 myDog1;
    myDog1.eat();
    myDog1.bark();

    Cat1 myCat1;
    myCat1.eat();
    myCat1.meow();
    cout<<endl;

// 3)
    Dog2 myDog2;
    myDog2.eat();
    myDog2.breathe();
    myDog2.bark();

    return 0;
}