#include<iostream>
#include<list>
using namespace std;

// ## List In C++ STL

void display(list<int> &lst){
    list<int> :: iterator it;
    for (it=lst.begin(); it!=lst.end() ; it++) // from first to last element
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}

int main(){
    list<int> list1; // List of 0 length
    list1.push_back(5);
    list1.push_back(7);
    list1.push_back(9);
    list1.push_back(9);
    list1.push_back(1);
    display(list1);

    // Removing elements from the list
    // list1.pop_front();
    // list1.remove(9);
    // list1.pop_back();
    // display(list1);

    // Sorting the list
    // list1.sort();
    // display(list1);

    // Reversing the list
    // list1.reverse();
    // display(list1);

    list<int> list2(3); // Empty list of size 7
    list<int> :: iterator iter;
    iter = list2.begin();
    *iter = 45;
    iter++;
    *iter = 6;
    iter++;
    *iter = 12;
    iter++;
    display(list2);

    // Merging list1 and list 2 after sorting elements
    list1.sort();
    list2.sort();
    list1.merge(list2);
    cout<<"list1 after sorting: ";
    display(list1);

    return 0;
}