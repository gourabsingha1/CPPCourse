#include<iostream>
using namespace std;

// ## Revisiting pointers: New and delete keywords

int main(){
    // Basic example
    int a = 4;
    int *ptr = &a; // ptr = address. *ptr = value of address
    *ptr = 999; // reseting value of a
    cout<<"The value of a is "<<*(ptr)<<endl;

    // New operator
    int *p = new int(40); // setting new integer 40.
    cout<<"The value at address p is "<<*(p)<<endl;

    int *arr = new int[3]; // [3] = array of 3 objects
    arr[0] = 10;
    *(arr+1) = 20;
    arr[2] = 30;
    // delete[] arr; // deletes dynamically allocated block of memory
    cout<<"The value at address arr[0] is "<<arr[0]<<endl;
    cout<<"The value at address arr[1] is "<<arr[1]<<endl;
    cout<<"The value at address arr[2] is "<<arr[2]<<endl;

    return 0;
}