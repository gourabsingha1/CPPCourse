#include<iostream>
#include<iomanip>
using namespace std;

// ## Constants, manipulators and operator precedence

int main(){


    int a = 34;

    cout<<"the value of a was: "<<a<<endl;
    a = 45;
    cout<<"the value of a is: "<<a<<endl;

    //Constants in C++

    const int b = 3.11;
    cout<<"The value of b was: "<<b<<endl;
    // b = 45.6; //You will get an error because b is a constant
    cout<<"The value of b is: "<<b<<endl;

    
    //Manipulators in C++

    int p = 3, q = 78, r = 1233;
    cout<<"The value of a without setw is: "<<p<<endl;
    cout<<"The value of b without setw is: "<<q<<endl;
    cout<<"The value of c without setw is: "<<r<<endl;
    
    cout<<"The value of a with setw(4) is: "<<setw(4)<<p<<endl;
    cout<<"The value of b with setw(4) is: "<<setw(4)<<q<<endl;
    cout<<"The value of c with setw(4) is: "<<setw(4)<<r<<endl;


    //Operator Precedence
    
    int n = 3, m = 4, ans = ((((n*5)+m)-45)+87);

    cout<<"The value of ans is: "<<ans<<endl;






    return 0;

}