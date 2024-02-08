#include<iostream>
#include<fstream>
#include<string>

using namespace std;

// ## File I/O: open() and eof() functions -> eof = end of file

int main(){
    ofstream out;
    out.open("sample62.txt");
    out<<"This is ME MYSELF AND I\nTheres fire in my soul\nBy Bebe Rexha";
    out.close();

    ifstream in;
    string st;
    in.open("sample62.txt");

    while (in.eof()==0){
        getline(in, st);
        cout<<st<<endl;
    }
    
    // for (int i = 0; in.eof()==0; i++)
    // {
    //     getline(in, st);
    //     cout<<st<<endl;
    // }
    

    in.close();
    
    
    return 0;
}