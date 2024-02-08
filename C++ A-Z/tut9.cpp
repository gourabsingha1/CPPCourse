#include<iostream>
using namespace std;

// ## Control structures, If else and switch case statements

int main(){

    int age;

    cout<<"Tell me your age:"<<endl;
    cin>>age;



    // Selection control structure: If-else-if-else ladder

    if((age<18) && (age>0)){
        cout<<"You cannot come to my party"<<endl;
    }
    else if(age<1){
        cout<<"You are not yet born";
    }
    else if(age==18){
        cout<<"You are a kid and you will get a kid pass to the party"<<endl;
    }
    else{
        cout<<"You can come to my party"<<endl;
    }



    // Selection control structure: Switch Case statements

    switch (age)
    {
    case 18:
        cout<<"You are 18"<<endl;
        break;
    case 22:
         cout<<"You are 22"<<endl;
        break;
    
    case 2:
         cout<<"You are 2"<<endl;
        break;

    default:
    cout<<"No special cases"<<endl;
        break;
    }
    cout<<"Done with switch case";


    return 0;
}