#include<iostream>
using namespace std;

// ## Code example demonstrating Virtual base class

// Student --> Test + Sports --> Result
// Variables of Student can be inherited by one class at a time


class Student{ // Virtual base class
    protected:
        int roll_no;
    public:
        void set_roll_number(int a){
            roll_no = a;
        }
};

class Test : virtual public Student{
    protected:
        float maths, physics;
    public:
        void set_marks(float m1, float m2){
            maths = m1;
            physics = m2;
        }
};

class Sports : virtual public Student{
    protected:
        float score;
    public:
        void set_score(float sc){
            score = sc;
        } 
};

class Result : public Test, public Sports{
    public:

        void show(void){
            cout<<"Your roll no is "<<roll_no<<endl;
            cout<<"Your result is here: "<<endl
                <<"Maths: "<<maths<<endl
                <<"Physics: "<<physics<<endl;
            cout<<"Your PT score is: "<<score<<endl;
            cout<<"Your result is: "<<(maths+physics+score)<<endl;
        }
};


int main(){
    Result Gourab;
    Gourab.set_roll_number(56);
    Gourab.set_marks(80.84, 83.92);
    Gourab.set_score(78.47);
    Gourab.show();
    
    return 0;
}