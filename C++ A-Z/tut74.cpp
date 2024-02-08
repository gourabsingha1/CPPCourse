#include<iostream>
#include<algorithm>
using namespace std;

// ## Function Objects (Functors) In C++ STL

// Function Objects (Functor): Functions wrapped in a class so that it is available like an object

int main(){
    int arr[] = {1, 73, 4, 2, 54, 16};
    // sort(arr, arr+6); // Ascending
    sort(arr, arr+6, greater<int>()); // Descending
    for (int i = 0; i < 6; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    return 0;
} 