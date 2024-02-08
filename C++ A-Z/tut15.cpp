#include<iostream>
using namespace std;

// ## Functions and function prototypes


// Formal parameters a and b will be taking values from actual parameters num1 and num2
int sum(int a, int b){
    int c = a + b;
    return c;
}


// ******* Function prototype ******** --> Gives assurity of getting a specific function i.e. sum
// Type function name (arguments);


int sum(int a, int b); // Acceptable
// int sum(int a, b); // Not Acceptable
int sum(int, int); // Acceptable

void g(void); // Acceptable
void g(); // Acceptable



int main(){

    int num1, num2; // num1 and num2 are actual parameters
    cout<<"Enter first number: ";
    cin>>num1;
    cout<<"Enter second number: ";
    cin>>num2;
    cout<<"The sum is: "<<sum(num1, num2)<<endl<<endl;
    g();
    
    return 0;
}


void g(){
    cout<<"Hello, Good Morning.";
}