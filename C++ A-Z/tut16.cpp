#include<iostream>
using namespace std;

// ## Call by value and call by reference

// This will not swap

void Swap (int a, int b){
    int temp = a; // temp = 4, a = 4, b = 5
    a = b;        // temp = 4, a = 5, b = 5
    b = temp;     // temp = 4, a = 5, b = 4

    return;
}



// This will swap a and b

// ****** Call by reference using pointers ******
   
void swapPointer(int* a, int* b){ // This will swap using pointer reference
    int temp = *a; // temp = 4, a = 4, b = 5
    *a = *b;       // temp = 4, a = 5, b = 5
    *b = temp;     // temp = 4, a = 5, b = 4

    return;
}



// This will swap a and b

// ****** Call by reference using C++ reference variables ******
 
void swapReferenceVar(int &a, int &b){ // This will swap using reference variables
    int temp = a; // temp = 4, a = 4, b = 5
    a = b;        // temp = 4, a = 5, b = 5
    b = temp;     // temp = 4, a = 5, b = 4

    return;
}



// This will swap a and b

// ***** Return by reference *****

int &swapReferenceVarReturn(int &a, int &b){ // This will swap using reference variables
    int temp = a; // temp = 4, a = 4, b = 5
    a = b;        // temp = 4, a = 5, b = 5
    b = temp;     // temp = 4, a = 5, b = 4

    return a;
}

int main(){

    int x = 4, y = 5;
    cout<<"The value of x is: "<<x<<" and the value of y is: "<<y<<endl<<endl;
    

    Swap(x,y);
    cout<<"After swapping(not really) x is: "<<x<<" and y is: "<<y<<endl<<endl;
    

    swapPointer(&x,&y);
    cout<<"After swapping using pointer x is: "<<x<<" and y is: "<<y<<endl<<endl;


    swapReferenceVar(x,y);
    cout<<"After swapping with reference x is: "<<x<<" and y is: "<<y<<endl<<endl;


    swapReferenceVarReturn(x,y) = 766;
    cout<<"After swapping with reference the new x is: "<<x<<" and y is: "<<y<<endl<<endl;
   

    cout<<"The value of x is: "<<x<<" and y is: "<<y<<endl<<endl;

    return 0;
}