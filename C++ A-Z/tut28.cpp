#include<iostream>
using namespace std;

// ## More on C++ friend functions

class Y;
class X{
    int data;
    friend void add(X, Y);

    public:
        void setValue(void){
            cout<<"Enter data: "<<endl;
            cin>>data;
        }
        void printValue(){
            cout<<"The value of objects of X is "<<data<<endl;
        }
};

class Y{
    int num;
    friend void add(X, Y);

    public:
        void setValue(int value){
            num = value;
        }
        void printValue(){
            cout<<"The value of objects of Y is "<<num<<endl;
        }
};

void add(X o1, Y o2){
    cout<<"Summing values of X and Y objects gives me "<<o1.data + o2.num<<endl;
}


int main(){
    X a1;
    a1.setValue();
    a1.printValue();

    Y b1;
    b1.setValue(5);
    b1.printValue();

    add(a1, b1);

    return 0;
}