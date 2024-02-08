#include<iostream>
using namespace std;

// ## Reference variables and typecasting

int c = 45;

int main(){


    //*********** Build in data types ************
    int a,b,c;

    cout<<"Enter the value of a:"<<endl;
    cin>>a;
    cout<<"Enter the value of b:"<<endl;
    cin>>b;
    c = a + b;

    cout<<"The sum is:"<<c<<endl;
    cout<<"The global c is "<<::c<<endl;
    
    
    
    //*********** Float, double and long double literals ***********
    float d=34.4f;
    long double e=34.4l;
    cout<<"The size of 34.4 is:"<<sizeof(34.4)<<endl;
    cout<<"The size of 34.4f is:"<<sizeof(34.4f)<<endl;
    cout<<"The size of 34.4F is:"<<sizeof(34.4F)<<endl;
    cout<<"The size of 34.4l is:"<<sizeof(34.4l)<<endl;
    cout<<"The size of 34.4L is:"<<sizeof(34.4L)<<endl;

    cout<<"The value of d is:"<<d<<endl<<"The value of e is:"<<e<<endl;




    //********** Reference variables ************

    //Rohan ---> Monty ----> Rohu -----> Dangerous coder

    float x = 455;
    float & y = x;
    cout<<x<<endl;
    cout<<y<<endl;


    //********** Typecasting ************
    
    int p = 45;
    float q = 45.46;
    cout<<"The value of p is "<<(float)p<<endl;
    cout<<"The value of p is "<<float(p)<<endl;
    
    cout<<"The value of q is "<<(int)q<<endl;
    cout<<"The value of q is "<<int(q)<<endl;

    int r = int(q);

    cout<<"The expression is "<<p + q<<endl;
    cout<<"The expression is "<<p + int(q)<<endl;
    cout<<"The expression is "<<p + (int)q<<endl;






    return 0;
}