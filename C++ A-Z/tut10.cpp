#include<iostream>
using namespace std;

// ## For, while, doWhile loops

int main(){
    /*Loops in C++:
    There are three types of loops in C++:
    1. For Loop
    2. While Loop
    3. do-While Loop
*/

//****** For loop in C++ ******
int i = 1;
cout<<i<<endl;
i++;
cout<<i<<endl;

// Syntax for for loop
// for(initialization; condition; updation)
// {
//     loop body(C++ code);
// }


for (i = 1; i <= 40; i++)
{
    cout<<i<<" ";
}
cout<<endl;
cout<<i<<endl;

//Example of infinite for loop
// for (i = 1; 34 <= 40; i++)
// {
//     cout<<i<<endl;
// }



//****** While loop in C++ ******


// Syntax for while loop
// while(condition){
//     C++ Statement;
// }

//Printing 1 to 40 using while loop
int j = 1;
while(j<=40){
    cout<<j<<" ";
    j++;
}
cout<<endl;
cout<<j<<endl;

//Example of infinite while loop
// j = 1;
// while(true){
//     cout<<j<<endl;
//     j++;
// }



//****** do While loop in C++ ******


// Syntax for do While loop
// initialization
// do{
//     C++ Statements;
// }while(condition);

//Printing 1 to 40 using while loop
int k = 1;
do{
    cout<<k<<" ";
    k++;
}while(k<=40);
cout<<endl;
cout<<k<<endl;

//Example of infinite do While loop
// k = 1;
// do{
//     cout<<k<<endl;
//     k++;
// }while(true);


//******* 6 table using any loop *******

//1. For loop

for(int i = 1; i<=10; i++){
    cout<<i*6<<" ";
}
cout<<endl;

//2. While loop

i = 1;
while(i<=10){
    cout<<i*6<<" ";
    i++;
}
cout<<endl;
//3. do While loop

i = 1;
do{
    cout<<i*6<<" ";
    i++;
}while(i<=10);
cout<<endl;

    return 0;
}