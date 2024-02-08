#include<iostream>
using namespace std;

// ## Objects memory allocation and using arrays

class Shop{
    int itemId[100];    // Shop has maximum 100 items
    int itemPrice[100]; // Shop has maximum 100 items
    int counter;

public:
    void initCounter() {
        counter = 0; // Counter initializes from 0. Value of counter is 0 for all
    }
    void setPrice();
    void displayPrice();
};

void Shop::setPrice(){
    cout<<"Enter Id of your item no "<<counter + 1<<endl;
    cin>>itemId[counter];
    cout<<"Enter Price of your item "<<endl;
    cin>>itemPrice[counter];
    counter++; // counter value is incrementing as objects are being created
}

void Shop::displayPrice(){
    for(int i = 0; i < counter; i++){
        cout<<"The Price of item with Id "<<itemId[i]<<" is "<<itemPrice[i]<<endl;
    }
}

int main(){
    Shop dukaan;
    dukaan.initCounter();
    dukaan.setPrice();
    dukaan.setPrice();
    dukaan.setPrice();
    dukaan.displayPrice();

    return 0;
}