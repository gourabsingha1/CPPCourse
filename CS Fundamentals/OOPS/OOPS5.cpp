#include <iostream>
using namespace std;

// **** 1. WAP to demonstrate example of Simple Inheritance ****

class Shape {
protected:
    int height;
    int width;
public:
    void setWidth(int w) {
        width = w;
    }
    void setHeight(int h) {
        height = h;
    }
};

class Rectangle: public Shape {
public:
    int getArea() {
        return width * height;
    }
};


// **** 2. WAP to find student information using 2 class and simple inheritance ****

class Student {
protected:
    string name;
    int enroll;
    int marks;
public:
    void setName(string n) {
        name = n;
    }
    void setEnroll(int rn) {
        enroll = rn;
    }
    void setMarks(int m) {
        marks = m;
    }
    string getName() {
        return name;
    }
    int getEnroll() {
        return enroll;
    }
    int getMarks() {
        return marks;
    }
};

class StudentInfo: public Student {
private:
    string branch;
public:
    void setBranch(string b) {
        branch = b;
    }
    string getBranch() {
        return branch;
    }
};


// **** 3. WAP to demonstrate example of Multiple Inheritance ****

// Base class 1
class Person {
protected:
    string name;
    int age;
public:
    Person(string n, int a) {
        name = n;
        age = a;
    }
};

// Base class 2 
class Employee {
protected:
    int employeeId;
    float salary;
public:
    Employee(int id, float s) {
        employeeId = id;
        salary = s;
    }
};

// Derived class
class Manager: public Person, public Employee {
private:
    string department;
public:
    Manager(string n, int a, int id, float s, string d): Person(n, a), Employee(id, s) {
        department = d;
    }
    void display() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Employee ID: " << employeeId << endl;
        cout << "Salary: " << salary << endl;
        cout << "Department: " << department << endl;
    }
};



int main() {
// 1)
    Rectangle rect;
    rect.setWidth(5);
    rect.setHeight(7);
    cout << "Total area: " << rect.getArea() << endl;

// 2)
    StudentInfo student;
    student.setName("John");
    student.setEnroll(12345);
    student.setMarks(80);
    student.setBranch("Computer Science");
    cout << "Name: " << student.getName() << endl;
    cout << "Roll Number: " << student.getEnroll() << endl;
    cout << "Marks: " << student.getMarks() << endl;
    cout << "Branch: " << student.getBranch() << endl;

// 3)
    Manager manager("Gourab Singha", 35, 12345, 75000, "Sales");
    manager.display();

   return 0;
}