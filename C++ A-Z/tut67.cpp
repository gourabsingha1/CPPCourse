#include<iostream>
using namespace std;

// ## Function Templates & Function Templates with Parameters

template <class T>
    void swapp(T &a, T &b){
        T temp = a;
        a = b;
        b = temp;
    }

template <class T1, class T2>

// float funcAverage(float a, float b){
//     float avg = (a+b)/2.0;
//     return avg;
// }
float funcAverage(T1 a, T2 b){
    float avg = (a+b)/2.0;
    return avg;
}

int main(){
    float a, b= 5.2, c= 2.8;
    // a = funcAverage(5.2, 2.2);
    swapp(b, c);
    a = funcAverage<float, int>(b, c);
    printf("The average of these numbers is %.3f", a); // .3-> 3 decimels

    return 0;
}