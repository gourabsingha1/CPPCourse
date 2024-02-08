#include<iostream>
using namespace std;

// ## Structures, unions and enums

struct human{ // human has five characteristics
    int age;
    string name;
    string partner;
    float money;
    int happiness;
};

typedef struct employee // typedef --> changes struct "employee" to "ep"
    //***** Requires 9 bytes *****
{
    int eId; // size = 4
    char favChar; // size = 1
    float salary; // size = 4
} ep;

union money //***** Any one of the below will be used at a time. So "union" helps allocate the maximum value for better memory management i.e. 4 bytes *****
    //***** Requires 4 bytes *****
{
    int rice; // size = 4
    char car; // size = 1
    float pounds; // size = 4
};

int main(){
    

    ep gourab; // ep = struct employee
    struct employee ritika;
    struct employee parthiv;

    gourab.eId = 1;
    gourab.favChar = 'c';
    gourab.salary = 120000000;

    cout<<"The value of Gourab's eId is "<<gourab.eId<<endl;
    cout<<"The value of Gourab's favChar is "<<gourab.favChar<<endl;
    cout<<"The value of Gourab's salary is "<<gourab.salary<<endl<<endl;

    union money m1;
    m1.rice = 15;
    m1.car = 'B';
    m1.pounds = 7.68;
    cout<<"Price of 1kg rice is: "<<m1.rice<<endl; // Doesn't execute
    cout<<"Symbol of car is: "<<m1.car<<endl; // Doesn't execute
    cout<<"10 dollars in pounds is: "<<m1.pounds<<endl<<endl; // Executes
    
    
    enum Meal{breakfast, lunch, dinner, nextBreakfast};
    Meal M1 = breakfast, M2 = lunch, M3 = dinner, M4 = nextBreakfast;

    cout<<"Breakfast: "<<breakfast<<endl;
    cout<<"Lunch: "<<lunch<<endl;
    cout<<"Dinner: "<<dinner<<endl;
    cout<<"NextBreakfast: "<<nextBreakfast<<endl<<endl;

    bool isTrue = (M3==2);
    cout<<isTrue<<endl;
    return 0;
}