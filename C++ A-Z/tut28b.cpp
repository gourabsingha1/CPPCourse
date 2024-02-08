#include<iostream>
using namespace std;

// swapping

class c2;
class c1{
    int val1;
    friend void exchange (c1 &, c2 &);
    public:
        void indata(int a){
            val1 = a;
        }
        void disB1(){
                cout<<"The value of c1 is: "<<val1<<endl;
        }
        void display(){
                cout<<val1<<endl;
        }
};

class c2{
    int val2;
    friend void exchange (c1 &, c2 &);
    public:
        void indata(int a){
            val2 = a;
        }
        void disB2(){
                cout<<"The value of c2 is: "<<val2<<endl;
        }
        void display(){
                cout<<val2<<endl;
        }
};

/* Trick to swap 2 numbers a and b:
temp = a;
a = b;
b = temp;
*/

void exchange(c1 & x, c2 & y){
    int tmp = x.val1;
    x.val1 = y.val2;
    y.val2 = tmp;
}

int main(){
    c1 oc1;
    c2 oc2;
    
    oc1.indata(34);
    oc1.disB1();
    oc2.indata(67);
    oc2.disB2();

    exchange(oc1, oc2);
    cout<<"The value of c1 after exchanging becomes: ";
    oc1.display();
    cout<<"The value of c2 after exchanging becomes: ";
    oc2.display();


    return 0; 
}