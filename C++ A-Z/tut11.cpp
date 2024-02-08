#include<iostream>
using namespace std;

// ## Break and continue statements

int main(){

    for (int i = 0; i<40; i++)
    {
        cout<<i<<" ";
        if(i==2){
            break;
        }
    }
    cout<<endl;

    for (int i = 0; i<40; i++)
    {
        if(i==2){
            break;
        }
        cout<<i<<" ";
    }
    cout<<endl;

    for (int i=0; i<40; i++){
        if(i<35){
            continue;
        }
        cout<<i<<" ";
    }
    cout<<endl;







    return 0;
}