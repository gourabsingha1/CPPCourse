#include <iostream>
#include <cmath>
using namespace std;

class point {
    int x, y;
    friend void difference(point, point);

public:
    point(int a, int b) {
        x = a;
        y = b;
    }
    void displaypoint() {
        cout<<"The point is : (" << x << "," << y << ")"<<endl;
    }
};

void difference(point o1, point o2) {
    int x_diff = o2.x - o1.x;
    int y_diff = o2.y - o1.y;
    float dist = sqrt((x_diff) * (x_diff) + (y_diff) * (y_diff));
    cout << "Distance is : " << dist << " units"<<endl;
}

int main() {
    point p1(1, 2), p2(4, 3);
    p1.displaypoint();
    p2.displaypoint();
    difference(p1, p2);

    return 0;
}