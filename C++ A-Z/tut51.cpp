#include<iostream>
using namespace std;

// ## Pointers to objects and arrow operator

class Complex{
    int real, imag;
    public:
        void setData(int x, int y){
            real = x;
            imag = y;
        }
        void getData(){
            cout<<"The real part is "<<real<<endl;
            cout<<"The imag part is "<<imag<<endl;
        }     
};

int main(){
    // Complex c1; // is exactly same as
    // Complex *ptr = &c1; // is exactly same as
    Complex *ptr = new Complex;
    
    // (*ptr).setData(1, 54); // is exactly same as 
    ptr->setData(1, 54);

    // (*ptr).getData(); // is exactly same as
    ptr->getData();
    
    // Array of objects
    Complex *ptr1 = new Complex[4];
    ptr1->setData(4, 95);
    ptr1->getData();

    return 0;
}