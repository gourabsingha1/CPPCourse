#include <iostream>
using namespace std;

// ## Variable scope and data types
// Example of data types --> int, void, float, char etc.

int glo=6;
void sum(){
    int a;
    cout<< glo;
}

int main(){
    // int a=4;
    // int b=5;
    int a=4, b=5;
    int glo=12;
    glo=72;
    float pi=3.142;
    char c='u';
    bool is_true= true;
    sum();
    cout<<glo<< is_true;
    // cout<<"This is tutorial 4.\nHere the value of a is "<<a<<". \nThe value of b is "<<b;
    // cout<<"\nThe value of pi is: "<<pi;
    // cout<<"\nThe value of c is: "<<c;

    return 0;
}