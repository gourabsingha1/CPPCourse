#include<iostream>
#include<vector>
using namespace std;

// ## Vector in C++ STL

template <class T>
void display(vector<T> &v){
    // cout<<"Displaying this vector "<<endl;
    for (int i = 0; i < v.size(); i++) // v.size() is the syntax of vector for adding size
    {
        // cout<<v.at(i)<<" "; // Is exactly same as
        cout<<v[i]<<" "; // " " -> adds space between elements
    }
    cout<<endl;
}

int main(){
    //Syntax of vector

    /*
    vector<int> vec1;
    int size, element;
    cout<<"Enter the size of your vector: "<<endl;
    cin>>size;
    for (int i = 0; i < size; i++)
    {
        cout<<"Enter an element to add to this vector: "<<endl;
        cin>>element;
        vec1.push_back(element); // Adds element at the end
    }
    // vec1.pop_back(); // Deletes last element (If its used within the loop, then no element will be displayed)
    display(vec1);
    
    // Syntax of iterator
    vector<int> :: iterator iter = vec1.begin(); // Points at the beginning
    // vec1.insert(iter, 566); // inserts 566 in the first position
    // vec1.insert(iter+1, 566); // inserts 566 in the second position
    vec1.insert(iter+1, 5, 566); // inserts 5 copies of 566 in the second position
    display(vec1);
    */

    vector<int> vec1; // zero length integer vector
    display(vec1);
    vector<char> vec2(4); // 4 element character vector
    vec2.push_back('5');
    display(vec2);
    vector<char> vec3(vec2); // 4 element character vector from vec2
    display(vec3);
    vector<int> vec4(4, 13); // 6-element vector of 3s
    display(vec4);
    cout<<vec4.size()<<endl;
    vector<int> vec5;
    vec5.push_back(38);
    vec5.push_back(62);
    vec5.front() = vec5.front() + vec5.back(); // s = s+a, slower
    // vec5.front() += vec5.back(); // s +=a, faster
    cout<<"vec5.front() is now: "<<vec5.front()<<endl;


    return 0;
}