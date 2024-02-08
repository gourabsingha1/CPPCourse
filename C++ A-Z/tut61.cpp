#include<iostream>
#include<fstream>
using namespace std;

// ## File I/O: Read/Write in the Same Program & Closing Files

int main(){
    ofstream hout("sample61.txt");
    cout<<"Enter your name:"<<endl;
    string name;
    cin>>name;

    hout<<"Hello "<<name;
    hout.close();
    
    ifstream hin("sample61.txt");
    string content;
    getline(hin, content);
    cout<<"The content of this file is: "<<content<<endl;
    hin.close();

    return 0;
}