#include <bits/stdc++.h>
using namespace std;

/*
Create a class student which has data members as name, branch, roll no, marks in five subjects.
Display the details of the student who has more than 70%. Use array of objects.
*/
struct student{
    char name[10], branch[10], enrol[10];
    int marks[5];

public:
    void getData();
    void printData();
} s[5];

void student::getData(){
    cout<<"Enter name: ";
    cin>>name;
    cout<<"Enter branch: ";
    cin>>branch;
    cout<<"Enter enrollment no: ";
    cin>>enrol;
    cout<<"Enter marks of 5 subjects: ";
    for (int i = 0; i < 5; i++)
    {
        cin>>marks[i];
    }
}

void student::printData(){
    double percentage = 0;
    for (int i = 0; i < 5; i++)
    {
        percentage += marks[i];
    }
    percentage = (percentage / 500) * 100;
    if(percentage > 70){
        cout<<"\nName = "<<name<<"\n";
        cout<<"Branch: "<<branch<<"\n";
        cout<<"Enrollment no: "<<enrol<<"\n";
        cout<<"Percentage: "<<percentage<<"%\n";
    }
    else{
        cout<<"Percentage is less than 70%\n";
    }
}


/*
Print a base class basic_info with data members name, rollno, gender and two member functions getData and display.
Derive a class physical_fit from basic_info which has data members height and weight and member function getData and display.
Display all the information using object of derived class.
*/
class basic_info {
    char name[10], rollno[10], gender[10];
public:
    void getData();
    void display();
};

class physical_fit : public basic_info {
    float height;
    float weight;
public:
    void getData();
    void display();
} person;

void basic_info::getData(){
    cout<<"Enter name: ";
    cin>>name;
    cout<<"Enter enrollment no: ";
    cin>>rollno;
    cout<<"Enter gender: ";
    cin>>gender;
}

void basic_info::display(){
    cout<<"\nName: "<<name<<"\n";
    cout<<"Enrollment no: "<<rollno<<"\n";
    cout<<"Gender: "<<gender<<"\n";
}

void physical_fit::getData(){
    basic_info::getData();
    cout<<"Enter height: ";
    cin>>height;
    cout<<"Enter weight: ";
    cin>>weight;
}

void physical_fit::display(){
    basic_info::display();
    cout<<"Height: "<<height<<"\n";
    cout<<"Weight: "<<weight<<"\n";
}

int main(){
// 1)
    // for (int i = 0; i < 5; i++)
    // {
    //     s[i].getData();
    // }
    // for (int i = 0; i < 5; i++)
    // {
    //     s[i].printData();
    // }
    // return 0;

// 2)
    person.getData();
    person.display();
}