#include<iostream>
using namespace std;

// ## Static data members and methods

class Employee{
    int id;
    static int count; // count = Employee number, default value = 0
    // count is same for all objects

public:
    void setdata(){
        cout<<"Enter the id "<<endl;
        cin>>id;
        count++;
    }
    void getdata(){
        cout<<"The id of the employee is "<<id<<" and this is employee number "<<count<<endl;
    }
    static void getCount(){ // only able to access static variables
        // cout<<id; // This will throw an error
        cout<<"The value of count is "<<count<<endl;
    }
};

int Employee::count = 1000; // count initializes with 1000, count is the static data member of Employee

int main(){
    Employee gourab, abhoy, parthiv;
    // gourab.id = 1;
    // gourab.count = 1; // Cannot do this as id and count are private

    gourab.setdata();
    gourab.getdata();
    Employee::getCount();

    abhoy.setdata();
    abhoy.getdata();
    Employee::getCount();

    parthiv.setdata();
    parthiv.getdata();
    Employee::getCount(); 

    return 0;
}