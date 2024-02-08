#include<iostream>
using namespace std;

// ## Constructors with default arguements

class Simple{
    int data1, data2, data3;
public:
    Simple(int a, int b = 9, int c = 8){
        data1 = a;
        data2 = b;
        data3 = c;
    }
    void printData();
};

void Simple::printData(){
    cout<<"The value of data1, data2 and data3 are "<<data1<<", "<<data2<<" and "<<data3<<endl;
}

int main(){
    Simple s(5, 6);
    s.printData();

    return 0;
}