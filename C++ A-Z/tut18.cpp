#include <iostream>
using namespace std;

// ## Recursions and recursive functions

// int factorial (int n){
//     if (n <= 1){
//         return 1;
//     }
//     return n * factorial(n - 1);
//}

// Step by step calculation of factorial 4
// factorial(4) = 4 * factorial(3)
// factorial(4) = 4 * 3 * factorial(2)
// factorial(4) = 4 * 3 * 2 * factorial(1)
// factorial(4) = 4 * 3 * 2 * 1
// factorial(4) = 24

// **** O(2^n) ****

int fibRecur(int n)
{
    if (n < 2)
    {
        return 1;
    }
    return fib(n - 1) + fib(n - 2);
}

// Step by step calculation of fibonacci at position 4
// fib(4)
// fib(3) + fib(2)
// fib(2) + fib(1)   +   fib(1) + fib(0)
// fib(1) + fib(0)   +     1            1        1
//   1        1            1            1        1
// 5

// **** O(n) ****

int fib(int n){
    int one = 1, two = 1;
    for(int i=2; i<n; ++i){
        int temp = one;
        one = one + two;
        two = temp;
    }
    return one;
}

int main()
{

    // Factorial of a number:
    // 6! = 6*5*4*3*2*1 = 720
    // 0! = 1 by definition
    // 1! = 1 by definition
    // n! = n*(n - 1)! by definition

    int a;

    cout << "Enter a number" << endl;
    cin >> a;
    // cout<<"The factorial of "<<a<<" is "<<factorial(a);
    cout << "The term fibonacci sequence at position " << a << " is " << fib(a) << endl;

    return 0;
}