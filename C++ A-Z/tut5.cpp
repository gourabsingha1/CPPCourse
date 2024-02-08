#include <iostream>
using namespace std;

// ## Basic input output

// << is called Insersion operator
// >> is called Extraction operator

int main()
{
    int num1, num2;
    cout << "Enter the value of num1:\n";
    cin >> num1;

    cout << "Enter the value of num2:\n";
    cin >> num2;

    cout << "The sum is " << num1 + num2;

    return 0;
}
