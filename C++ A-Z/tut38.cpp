#include<iostream>
using namespace std;

// ## Single inheritance

class Base{
    int data1;
    public:
        int data2;
        void setData();
        int getData1();
        int getData2();
};

void Base :: setData(){
    data1 = 10;
    data2 = 20;
}
int Base :: getData1(){
    return data1; 
}
int Base :: getData2(){
    return data2; 
}

class Derived : public Base{
    int data3;
    public:
        void process();
        void display();
};

void Derived :: process(){
    data3 = data2 * getData1();
}
void Derived :: display(){
    cout<<"The value of data1 is "<<getData1()<<endl;
    cout<<"The value of data2 is "<<data2<<endl;
    cout<<"The value of data3 is "<<data3<<endl;

}

int main(){
    Derived der;
    der.setData();
    der.process();
    der.display();
    
    return 0;
}