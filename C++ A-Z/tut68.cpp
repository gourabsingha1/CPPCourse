#include<iostream>
using namespace std;

// ## Member Function Templates & Overloading Template Functions

template <class T>
class Gourab{
    public:
        T data;
        Gourab(T a){
            data = a;
        }
        void display();
};

template <class T>
void Gourab<T> :: display(){
    cout<<data;
}

void func1(int a){
    cout<<"I am the first func1() "<<a<<endl;
}

template <class T>
void func1(T a){
    cout<<"I am the templatised func1() "<<a<<endl;
}

template <class T>
void func2(T a){
    cout<<"I am the templatised func2() "<<a<<endl;
}

int main(){
    // Gourab<int> g(67);
    // Gourab<float> g(5.7);
    // Gourab<char> g('c');
    // cout<<g.data<<endl; // is exactly same as
    // g.display();
    
    func1(4); // Exact match has higher priority.
    func2('c'); // When no exact match is there.
    
    return 0;
}