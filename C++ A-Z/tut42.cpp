#include<iostream>
#include<cmath>
using namespace std;

// ## Exercise on C++ inheritance

/*
Create 2 classes:
    1. SimpleCalculator - Takes input of 2 numbers using a utility
    function and performs +, -, *, / and displays the results
    using another function
    2. ScientificCalculator - Takes input of 2 numbers using
    a utility function and performs any four scientific
    operation of your choice and displays the results using
    another function

    Create another class HybridCalculator and inherit it using
    these 2 classes:
    Q1. What type of Inheritance are you using? - Multiple
    Q2. What mode of Inheritance are you using? - Public
    Q3. Create an object of HybridCalculator and display results
    of simple and scientific calculator.
    Q4. How is code reusability implemented? - Functions from both base classes were reused
*/

class SimpleCalculator{
    protected:
        float a, b;
    public:
        void setData1(void){
            cout<<"Enter a: "<<endl;
            cin>>a;
            cout<<"Enter b: "<<endl;
            cin>>b;
        }
};

class ScientificCalculator{
    protected:
        float x;
    public:
        void setData2(void){
            cout<<"Enter x in degree: "<<endl;
            cin>>x;
        }
};

class HybridCalculator : public SimpleCalculator, public ScientificCalculator{
    public:
        void show(void){
            cout<<"The value of (a+b) is: "<<(a+b)<<endl;
            cout<<"The value of (a-b) is: "<<(a-b)<<endl;
            cout<<"The value of (a*b) is: "<<(a*b)<<endl;
            cout<<"The value of (a/b) is: "<<(a/b)<<endl;
            cout<<"The value of sin3x is: "<<sin(3*x)<<endl;
            cout<<"The value of cos3x is: "<<cos(3*x)<<endl;
            cout<<"The value of tan3x is: "<<tan(3*x)<<endl;
            cout<<"The value of exp(x) is: "<<exp(x)<<endl;
            cout<<"The sum of a, b and sin3x is: "<<a+b+sin(3*x)<<endl;
        }
};

int main(){
    HybridCalculator H;
    H.setData1();
    H.setData2();
    H.show();
    return 0;
}




/*
int Method;
    string p, q, r, s;
    cout<<"Enter: 'p' for plus"<<endl<<"'q' for minus"<<endl<<"'r' for multiply"<<endl<<"'s' for devide"<<endl;

    cout<<"Choose the method"<<endl;
    cin>>Method;
    switch (Method){     
        case p:
            cout<<"The value of (a+b) is: "<<(a+b)<<endl;
            break;
        case q:
            cout<<"The value of (a-b) is: "<<(a-b)<<endl;
            break;
        case r:
            cout<<"The value of (a*b) is: "<<(a*b)<<endl;
            break;
        case s:
            cout<<"The value of (a/b) is: "<<(a/b)<<endl;
            break;
        }
*/