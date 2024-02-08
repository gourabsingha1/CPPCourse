#include<iostream>
using namespace std;

// ## Array of objects using pointers

class ShopItem{
    int id;
    float price;
    public:
        void setData(int a, float b){
            id = a;
            price = b;
        }
        void getData(void){
            cout<<"Code of this item is "<<id<<endl;
            cout<<"Price of this item is "<<price<<endl;
        }
};

int main(){
    int size = 3;
    /*
    general item
    veggies item
    hardware item
    */

    // int *ptr = &size; // store address of blocks then point next memories by using ptr++
    // int *ptr = new int [34]; // allocate memories worth 34 integers

    ShopItem *ptr = new ShopItem [size]; // Requesting compiler to allocate memory to create 3 Shop objects
                                 // and ptr will point memory from the first object
                                 // then continue pointing with ptr++
    ShopItem *ptrTemp = ptr;

/*
    1   2   3       // The first loop points using ptr
                    // The second loop points using ptrTemp
    ^
    |
    |
    ptr
    ^
    |
    |
    ptrTemp
*/

int a, b;
for (int i = 0; i < size; i++)
{
    cout<<"Enter the id and price of item number: "<<(i+1)<<endl;
    cin>>a>>b;
    // (*ptr).setData(p, q); // is exactly same as
    ptr->setData(a, b);
    ptr++;
}

for (int i = 0; i < size; i++)
{
    cout<<"Item number: "<<(i+1)<<endl;
    ptrTemp->getData();
    ptrTemp++;
}

    return 0;
}