#include<iostream>
using namespace std;

// ## this pointer
// 'this' is a keyword which is a pointer which points to the object which invokes member function


class A{
    int a;
    public:
        // void setData(int a){
        //     this->a = a;
        
        A & setData(int a){
            this->a = a;
            return *this;
        }
        void getData(void){
            cout<<"The value of a is "<<a<<endl;
        }
};

int main(){
    A a;
    a.setData(4).getData();
    
    return 0;
}