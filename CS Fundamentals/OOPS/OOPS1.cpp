#include <iostream>
#include <cmath>
using namespace std;

bool checkLeapYear(int &year){
    return year % 4 == 0 && year % 100 || year % 400 == 0;
}

bool checkArmstrongNo(int armstrongNo){
    int res = 0, digits = 0, temp = armstrongNo;
    while(temp) digits++, temp /= 10;
    temp = armstrongNo;
    while(temp){
        int rem = temp % 10;
        res += pow(rem, digits);
        temp /= 10;
    }
    return res == armstrongNo;
}

bool checkParity(int &n){
    return n & 1;
}

void Swap(int &a, int &b){
    a = a + b;
    b = a - b;
    a = a - b;
}

void fib(int &l, int &r){
    int a[r - l + 1], one = 0, two = 1;
    a[0] = 0, a[1] = 1;
    for(int i = 2; i <= r; i++){
        int temp = two;
        two += one;
        one = temp;
        if(i >= l){
            a[i - l] = two;
        }
    }
    for (int i = l; i <= r; i++)
    {
        cout<<a[i - l]<<' ';
    }
    cout<<endl;
}

int main(){
    while(1){
        int key;
        cout<<"Enter 1 to check leap year! \n";
        cout<<"Enter 2 to check armstrong number! \n";
        cout<<"Enter 3 to check odd/even! \n";
        cout<<"Enter 4 to swap 2 numbers! \n";
        cout<<"Enter 5 to find fibonacci number! \n";
        cout<<"Enter 6 to find number of characters in a string! \n";
        cout<<"Enter 7 to exit! \n\n";
        cin>>key;
        string s;
        switch (key)
        {
        case 1:
            int year;
            cout<<"Enter a year: "<<endl;
            cin>>year;
            if(checkLeapYear(year)) cout<<year<<" is a leap year"<<endl;
            else cout<<year<<" is not a leap year"<<endl;
            break;
        case 2:
            int armstrongNo;
            cout<<"Enter a number: "<<endl;
            cin>>armstrongNo;
            if(checkArmstrongNo(armstrongNo)) cout<<"Armstrong no!"<<endl;
            else cout<<"Not an armstrong no!"<<endl;
            break;
        case 3:
            int n;
            cout<<"Enter a number: ";
            cin>>n;
            if(checkParity(n)) cout<<n<<" is odd!"<<endl;
            else cout<<n<<" is even!"<<endl;
            break;
        case 4:
            int a, b;
            cout<<"Enter two numbers: ";
            cin>>a>>b;
            Swap(a, b);
            cout<<"After swapping a and b, a = "<<a<<" b = "<<b<<endl;
            break;
        case 5:
            int l, r;
            cout<<"Enter a range: ";
            cin>>l>>r;
            if(l > r){
                cout<<"Invalid range\n";
                break;
            }
            cout<<"Fibonacci number from "<<l<<" to "<<r<<" is:\n";
            fib(l, r);
            break;
        case 6:
            cout<<"Enter a string: ";
            cin>>s;
            cout<<"Number of characters "<<s<<" is: "<<s.length()<<"\n";
            break;
        case 7:
            cout<<"Exited from program\n";
            break;
        default:
            cout<<"Invalid key!\n";
            return 0;
        }
        cout<<"\n";
    }

    return 0;
}