#include<iostream>
#include<cmath>
using namespace std;

// ## Create a function which takes 2 point objects and computes the distance between those points

class Dist;
class Point1 {
    float x1, y1;
    friend class Dist;

public:
    Point1(float a, float b) {
        x1 = a;
        y1 = b;
    }
    void displayPoint1() {
        cout<<"The point is ("<<x1<<", "<<y1<<")"<<endl;
    }
};

class Point2{
    friend class Dist;
    float x2, y2;
public:
    Point2(float a, float b) {
        x2 = a;
        y2 = b;
    }
    void displayPoint2() {
        cout<<"The point is ("<<x2<<", "<<y2<<")"<<endl;
    }
};

class Dist{
public:
    float sub3 (float x1, float x2, float y1, float y2) {
        return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    }
};

int main(){
    Point1 p(2, 3);
    p.displayPoint1();

    Point2 q(3, 5);
    q.displayPoint2();

    Dist d;
    float abc = d.sub3(2, 3, 3, 5);
    cout<<"The distance between these points is: "<<abc<<endl;

    return 0;
}