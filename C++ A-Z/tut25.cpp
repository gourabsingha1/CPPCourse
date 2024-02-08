#include<iostream>
using namespace std;

// ## Array of objects and passing objects as function arguements 

class Employee{
    int id, salary;
public:
    void setId(){
        cout<<"Enter the id of employee"<<endl;
        cin>>id;
    }
    void getId(){
        cout<<"The id of this employee is "<<id<<endl;
    }
};

int main(){
    Employee fb[4];
    for (int i = 0; i < 4; i++)
    {
        fb[i].setId();
        fb[i].getId();
    }

    return 0;
}