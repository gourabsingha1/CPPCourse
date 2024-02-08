#include<iostream>
using namespace std;

// ## Dynamic initialization of objects using constructors

class BankDeposit{
    int principal, years;
    float interestRate, returnValue;
public:
    BankDeposit() {} // Default constructor, so that object can be made even when p, y, r values are not set
    BankDeposit(int, int, float); // r can be a value like 0.04
    BankDeposit(int, int, int); // r can be a value like 14
    void show(){
        cout<<"Principal amount was "<<principal<<endl
        <<"Return value after "<<years
        <<" years is "<<returnValue<<endl;
    }
};

BankDeposit::BankDeposit(int p, int y, float r){ // if interestRate (r) is fraction
    principal = p;
    years = y;
    interestRate = r;
    returnValue = principal;
    for(int i = 0; i < y; i++){
        returnValue = returnValue * (1 + interestRate);
    }
}
BankDeposit::BankDeposit(int p, int y, int r){ // if interestRate (r) is percentage
    principal = p;
    years = y;
    interestRate = float(r) / 100;
    returnValue = principal;
    for(int i = 0; i < y; i++){
        returnValue = returnValue * (1 + interestRate);
    }
}

int main(){
    int p, y, R;
    float r;
    cout<<"Enter the value of p, y and r (in fraction): "<<endl;
    cin>>p>>y>>r;
    BankDeposit bd1 = BankDeposit(p, y, r); // Aliter
    bd1.show();

    cout<<"Enter the value of p, y and R (in percentage): "<<endl;
    cin>>p>>y>>R;
    BankDeposit bd2 = BankDeposit(p, y, R); // Aliter
    bd2.show();

    return 0;
}