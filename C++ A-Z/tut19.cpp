#include <iostream>
using namespace std;

// ## Function overloading

// float sum(float a, int b){
//     cout<<"Using functions with 2 arguements"<<endl;
//     return a + b;
// }

// int sum(int a, int b, int c){
//     cout<<"Using functions with 3 arguements"<<endl;
//     return a + b + c;
// }

// Calculate the volume of a cylinder

float volume(double x, float y)
{
    return (3.14) * x * x * y;
}

// Calculate the volume of a rectangular box

float volume(float x, float y, float z)
{
    return x * y * z;
}

int main()
{

    // cout<<"The sum of 3.8 and 6 is "<<sum(3.8,6)<<endl;
    // cout<<"The sum of 3, 7 and 6 is "<<sum(3,6,7)<<endl;

    float r, h;
    cout << "Enter radius: ";
    cin >> r;
    cout << "Enter height: ";
    cin >> h;
    cout << "The volume of r = " << r << " and h = " << h << " is " << volume(r, h) << endl;

    float l, b, H;
    cout << "Enter length: ";
    cin >> l;
    cout << "Enter bredth: ";
    cin >> b;
    cout << "Enter height: ";
    cin >> H;
    cout << "The volume of length = " << l << " , bredth = " << b << " , height = " << H << " is " << volume(l, b, H) << endl;

    return 0;
}