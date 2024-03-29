#include<iostream>
using namespace std;

// ## Writing our First C++ Template

template <class T> // custom datatype = T
                   // will tell later what datatype I'll be using

class vector{
    int size;
    public:
    T * arr;
        vector(int m){
            size = m;
            arr = new T[size];
        }
    T dotProduct(vector &v){
        T d = 0;
        cout<<"The sum of the vectors is: "<<endl;
        for (int i = 0; i < size; i++)
        {
            d += this->arr[i] * v.arr[i];
        }
        return d;
    }
};

int main(){
    vector <float>v1(3);
    v1.arr[0] = 1.4;
    v1.arr[1] = 3.3;
    v1.arr[2] = 0.1;
    vector <float>v2(3);
    v2.arr[0] = 0.1;
    v2.arr[1] = 1.90;
    v2.arr[2] = 4.1;
    float a = v1.dotProduct(v2);
    cout<<a<<endl;
    
    return 0;
}