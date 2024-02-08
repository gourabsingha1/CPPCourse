#include <iostream>
using namespace std;

// ## Header files and operators

//There two types of Header files
// 1. System header files: It comes with the compiler
// eg: #include <iostream>  
// 2. User defined header files: It is written by the programmers
// eg: #include "this.h"--> This will produce an error is this.h is not present in the directory

int main(){

    //Assigment operators --> used to assign values to variables
    // int a=3, b=9;
    // char d='d';
    
    int a=4, b=5;

    cout<<"Operator in C++:\n";
    cout<<"Following are the types of operators in C++\n";


    //Arithmetic operators

    cout<<"The value of a + b is "<<a+b<<endl;
    cout<<"The value of a - b is "<<a-b<<endl;
    cout<<"The value of a x b is "<<a*b<<endl;
    cout<<"The value of a / b is "<<a/b<<endl;
    cout<<"The value of a % b is "<<a%b<<endl;
    cout<<"The value of a ++ is "<<a++<<endl;
    cout<<"The value of a -- is "<<a--<<endl;
    cout<<"The value of ++a is "<<++a<<endl;
    cout<<"The value of --a is "<<--a<<endl;

   
    // Comparison operators

    cout<<"Following are the comparison operators in C++"<<endl;
    cout<<"The value of a == b is "<<(a==b)<<endl;
    cout<<"The value of a != b is "<<(a!=b)<<endl;
    cout<<"The value of a >= b is "<<(a>=b)<<endl;
    cout<<"The value of a <= b is "<<(a<=b)<<endl;
    cout<<"The value of a > b is "<<(a>b)<<endl;
    cout<<"The value of a < b is "<<(a<b)<<endl;

    //Logical operators

    cout<<"Following are the logical operators in C++"<<endl;
    cout<<"The value of this logical and operator ((a==b) && (a<b)) is: "<<((a==b) && (a<b))<<endl;
    cout<<"The value of this logical or operator ((a==b) || (a<b)) is: "<<((a==b) || (a<b))<<endl;
    cout<<"The value of this logical not operator (!(a==b)) is: "<<(!(a==b))<<endl;


    

    return 0;
}