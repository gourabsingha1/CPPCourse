#include<iostream>
using namespace std;

// ## Inline functions, default and constant arguements

inline int product (int a, int b){ // Saves time of multiple copying and puts more load on memory but doesn't change output
//     // Not recommended to use below lines with inline functions
//     static int c=0; // This executes only once
//     c = c + 1; // Next time this function runs, the value of c will be retained
//     return (a*b)+c;
    return (a*b);
}

float moneyReceived(int currentMoney, float factor=1.04){
    return currentMoney*factor;

}

int strlen(const char *p){ // "p" is constant and cannot be changed

}

int main(){
   
    // int a, b;
    // cout<<"Enter the value of a and b ";
    // cin>>a>>b;
    // cout<<"The product of a and b is "<<product(a,b)<<endl;
    // cout<<"The product of a and b is "<<product(a,b)<<endl;
    // cout<<"The product of a and b is "<<product(a,b)<<endl;
    // cout<<"The product of a and b is "<<product(a,b)<<endl;
    // cout<<"The product of a and b is "<<product(a,b)<<endl;
    // cout<<"The product of a and b is "<<product(a,b)<<endl;
    // cout<<"The product of a and b is "<<product(a,b)<<endl;

    int money = 100000;
    int p;
    cout<<"If you have "<<money<<" Rs in your bank account, you will receive "<<moneyReceived(money)<< " Rs after 1 year"<<endl;
    cout<<"For VIP, If you have "<<money<<" Rs in your bank account, you will receive "<<moneyReceived(money, 1.1)<< " Rs after 1 year"<<endl;



    return 0;
}