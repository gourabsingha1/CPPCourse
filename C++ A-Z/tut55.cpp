#include<iostream>
using namespace std;

// ## Pointers to Derived Classes- Run time polymorphism

class BaseClass{
    public:
        int var_base;
        void display(void){
            cout<<"Displaying Base class variable var_base: "<<var_base<<endl;
        }
};

class DerivedClass : public BaseClass{
    public:
        int var_derived;
        void display(void){
            cout<<"Displaying Base class variable var_base: "<<var_base<<endl;
            cout<<"Displaying Derived class variable var_derived: "<<var_derived<<endl;
        }
};

int main(){
    BaseClass obj_base;
    DerivedClass obj_derived;

    BaseClass *base_class_pointer;
    base_class_pointer = &obj_derived; // Pointing base class pointer to derived class
    base_class_pointer->var_base=34;
    // base_class_pointer->var_derived=134; // This will throw an error
    base_class_pointer->display();
    base_class_pointer->var_base=334;
    base_class_pointer->display();

    DerivedClass * derived_class_pointer;
    derived_class_pointer = &obj_derived;
    derived_class_pointer->var_base=9448;
    derived_class_pointer->var_derived=98;
    derived_class_pointer->display();
    
    return 0;
}