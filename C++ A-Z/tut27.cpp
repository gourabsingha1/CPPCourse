#include<iostream>
using namespace std;

// ## Friend classes and member friend functions

class Complex; // Forward declaration

class Calculator{
public:
    int sumRealComplex(Complex, Complex);
    int sumImagComplex(Complex, Complex);
};

class Complex{
    int a, b;

    // *** Individually declaring functions as friends ***
    // friend int Calculator :: sumRealComplex(Complex o1, Complex o2);
    // friend int Calculator :: sumImagComplex(Complex o1, Complex o2);
    
    // *** Aliter: Declaring the entire calculator class as friend ***
    friend class Calculator;

public:
    void setNumber(int n1, int n2){
        a = n1;
        b = n2;
    }
    
    void printNumber(){
        cout<<"Your number is "<<a<<" + "<<b<<"i "<<endl;
    }
};

int Calculator :: sumRealComplex(Complex o3, Complex o4) {
    return (o3.a + o4.a);
}
int Calculator :: sumImagComplex(Complex o3, Complex o4) {
    return (o3.b + o4.b);
}

int main(){
    Complex o1, o2;
    o1.setNumber(1,4);
    o1.printNumber();   
    o2.setNumber(5,7);
    o2.printNumber();   

    Calculator calc;
    int res1 = calc.sumRealComplex(o1, o2);
    cout<<"The sum of real parts of o1 and o2 is "<<res1<<endl;
    int res2 = calc.sumImagComplex(o1, o2);
    cout<<"The sum of imaginary parts of o1 and o2 is "<<res2<<endl;
    

    return 0;
}