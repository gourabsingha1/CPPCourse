#include<iostream>
using namespace std;

// ## Class Templates with Default Parameters

template <class T1= int, class T2= float, class T3= char>
class Gourab{
    public:
        T1 a;
        T2 b;
        T3 c;
        Gourab(T1 x, T2 y, T3 z){
            a = x;
            b = y;
            c = z;
        }
        void display(void){
            cout<<"The value of a is: "<<a<<endl;
            cout<<"The value of b is: "<<b<<endl;
            cout<<"The value of c is: "<<c<<endl;
        }
};
int main(){
    Gourab<> g(4, 6.4, 'C'); // not specified
    g.display();
    cout<<endl;
    Gourab<float, char, char> h(1.4, 'o', 'c'); //specified
    h.display();
    
    return 0;
}