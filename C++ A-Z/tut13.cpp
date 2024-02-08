#include<iostream>
using namespace std;

// ## Arrays and pointers arithmetic

int main(){

    //***** Array example *****


    int mathMarks[4];
    mathMarks[0] = 2278;
    mathMarks[1] = 738;
    mathMarks[2] = 227;
    mathMarks[3] = 28;

    cout<<"These are mathMarks"<<endl;
    cout<<mathMarks[0]<<" ";
    cout<<mathMarks[1]<<" ";
    cout<<mathMarks[2]<<" ";
    cout<<mathMarks[3]<<" "<<endl<<endl;


    int marks[] = {23, 45, 56, 8, 9};
    // marks --> address of first block

    cout<<"These are marks"<<endl;
    cout<<marks[0]<<" ";
    cout<<marks[1]<<" ";
    // You can change the value of an array
    marks[2] = 455;
    cout<<marks[2]<<" ";
    cout<<marks[3]<<" "<<endl<<endl;
    

    
    // **Using for loop**

    for (int i = 0; i<4; i++)
    {
        cout<<"The value of marks "<<i<<" is "<<marks[i]<<endl;
    }
    cout<<endl;

    // **Using while loop**

    int i = 0;
    while(i<4){
        cout<<"The value of marks "<<i<<" is "<<marks[i]<<endl;
        i++;
    }
    cout<<endl;
    
    // **Using doWhile loop**
    
    i = 0;
    do{
        cout<<"The value of marks "<<i<<" is " <<marks[i]<<endl;
        i++;
    }while(i<4);
    cout<<endl;


    // Pointers and arrays

    // marks[] = 23, 45, 455, 8, 9
    int *p = marks;
    cout<<*(p++)<<endl; // *p = 23 After executing this line, p = 45
    cout<<*(++p)<<endl<<endl; // *p = 455, ++p = pre increament
    
    cout<<"The value of *p is "<<*p<<endl; // *p = 455
    cout<<"The value of *(p+1) is "<<*(p+1)<<endl; // 8
    cout<<"The value of *(p+2) is "<<*(p+2)<<endl; // 9
    cout<<"The value of *(p+3) is "<<*(p+3)<<endl; // *p > size of array

    
    
    return 0;
}