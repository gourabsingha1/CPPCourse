#include<iostream>
using namespace std;

class Complex{
    int a, b; // dimensions of complex number
public:
    void setData(int v1, int v2){
        a = v1;
        b = v2;
    }
    void setDataBySum(Complex o1, Complex o2){ // takes two objects
        a = o1.a + o2.a;
        b = o1.b + o2.b;
    }
    void printNumber(){
        cout<<"Your complex number is "<<a<<" + "<<b<<"i "<<endl;
    }

    void Sum(){
        cout<<"The sum of your complex numbers is "<<a<<" + "<<b<<"i "<<endl;
    }
};

int main(){
    // Complex c1, c2, c3;
    // c1.setData(1,2); // c1 = 1 + 2i
    // c1.printNumber();
    // c2.setData(3,4); // c2 = 3 + 4i
    // c2.printNumber();
    // c3.setDataBySum(c1, c2);
    // c3.Sum();

    Complex c[4], cSum;
    for (int i = 1; i < 4; i++){
        c[i].setData(i, i + 1);
        c[i].printNumber();
        c[i + 1].setData(i + 2, i + 3);
        c[i + 1].printNumber();
        cSum.setDataBySum(c[i], c[i + 1]);
        cSum.Sum();
    }

    return 0;
}