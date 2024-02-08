#include<iostream>
#include<map>
#include<string>
using namespace std;

// ## Map In C++ STL

// Map is an associated array

int main(){
    map<string, int> marksMap;
    marksMap["Harry"] = 98;
    marksMap["Jack"] = 59;
    marksMap["Rohan"] = 2;

    // Inserting
    marksMap.insert({{"Soham", 68}, {"Shubham", 73}});

    map<string, int> :: iterator iter;
    for (iter=marksMap.begin(); iter!=marksMap.end(); iter++)
    {
        cout<<(*iter).first<<" "<<(*iter).second<<"\n"; // *iter finds the values inside iterator. And .first .second accesses pair of first and second parts
    }
    cout<<"The size is: "<<marksMap.size()<<endl;
    cout<<"The maximum size is: "<<marksMap.max_size()<<endl;
    cout<<"The empty's return value is: "<<marksMap.empty()<<endl;

    return 0;
}