#include <bits/stdc++.h>
using namespace std;

/*
1. create a class Mark which contains the marks of subjects and print all the student details using constructor
2. WAP to implement constructor overload
3, using copy constructor, find values of three objects
4. addition of number of two different numbers using friend function
*/

class Mark {
    string name, enroll;
    int phy, chem, maths;
    int marks[3];
public:
    // Mark(string name, string enroll, int phy, int chem, int maths) {
    //     this->name = name, this->enroll = enroll, this->phy = phy, this->chem = chem, this->maths = maths;
    // }
    // void display() {
    //     cout<<name<<' '<<enroll<<endl;
    //     cout<<"Physics: "<<phy<<'\n'<<"Chemistry: "<<chem<<'\n'<<"Maths: "<<maths<<'\n\n';
    // }
    Mark(string name = " ", string enroll = " ", int marks[] = {}) {
        for (int i = 0; i < 3; i++)
        {
            this->marks[i] = marks[i];
        }
    }
    void display() {
        cout<<name<<' '<<enroll<<endl;
        for (int i = 0; i < 3; i++)
        {
            cout<<"Subject #"<<i<<": "<<marks[i]<<endl;
        }
        cout<<endl;
    }
};


class ConstructorOverload {
public:
    ConstructorOverload() {}
    ConstructorOverload(int x, int n) {
        cout<<"pow("<<x<<", "<<n<<") = "<<pow(x, n)<<endl;
    }
    ConstructorOverload(string name) {
        cout<<"Name: "<<name<<endl;
    }
};


class CopyConstructor {

};



int main() {
    // Mark student1("Gourab", "21UCS056", 80, 75, 63);
    // student1.display();
    Mark *students = new Mark[5];
    for (int i = 0; i < 5; i++)
    {
        int marks[3] = {i, i + 1, i + 2};
        students[i] = Mark("Gourab", "56", marks);
    }
    for (int i = 0; i < 5; i++)
    {
        students[i].display();
    }

    // ConstructorOverload co;
    // ConstructorOverload co1(3, 4);
    // ConstructorOverload co3("Gourab");
}