#include <iostream>
using namespace std;


/*
1. Create a class student which has data members as name, branch, roll no, marks in five subjects.
Display the details of the student who has more than 70%. Use array of objects.
*/

struct student {
    string name, branch, enrol;
    int marks[5];

public:
    void getData();
    void display();
    float getPercentage();
};

void student::getData() {
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

void student::display() {
    cout<<"\nName = "<<name<<"\n";
    cout<<"Branch: "<<branch<<"\n";
    cout<<"Enrollment no: "<<enrol<<"\n";
    cout << "Marks: ";
    for (int i = 0; i < 5; i++) {
        cout << marks[i] << " ";
    }
    cout << endl;
}

float student::getPercentage() {
    float total = 0;
    for (int i = 0; i < 5; i++)
    {
        total += marks[i];
    }
    return total / 5.0;
}



/*
2. Print a base class basic_info with data members name, rollno, gender and two member functions getData and display.
Derive a class physical_fit from basic_info which has data members height and weight and member function getData and display.
Display all the information using object of derived class.
*/


class basic_info {
protected:
    string name;
    int rollno;
    char gender;
public:
    void getData() {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter rollno: ";
        cin >> rollno;
        cout << "Enter gender (M/F): ";
        cin >> gender;
    }
    void display() {
        cout << "Name: " << name << endl;
        cout << "Rollno: " << rollno << endl;
        cout << "Gender: " << gender << endl;
    }
};

class physical_fit : public basic_info {
private:
    double height;
    double weight;
public:
    void getData() {
        basic_info::getData();
        cout << "Enter height (in meters): ";
        cin >> height;
        cout << "Enter weight (in kilograms): ";
        cin >> weight;
    }
    void display() {
        basic_info::display();
        cout << "Height: " << height << " meters" << endl;
        cout << "Weight: " << weight << " kilograms" << endl;
    }
};


int main(){
// 1)
    int n = 2;
    student students[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter details for student " << (i + 1) << ":" << endl;
        students[i].getData();
    }
    
    cout << endl << "Details of students with more than 70% marks:" << endl;
    for (int i = 0; i < n; i++)
    {
        if(students[i].getPercentage() >= 70.0) {
            students[i].display();
        }
    }

// 2)
    physical_fit student;
    cout << endl;
    student.getData();
    cout << endl << "Student information:" << endl;
    student.display();

    return 0;
}