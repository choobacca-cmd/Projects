#include <iostream>
using namespace std;

class point {
private:
    int x, y;
public:
    point() {
        x = y = 0;
    }

    point(int a, int b) {
        x = a;
        y = b;
    }

    void set() {
        cout << "Enter x: ";
        cin >> x;
        cout << "Enter y: ";
        cin >> y;
    }

    void set(int x_value, int y_value) {
        x = x_value;
        y = y_value;
    }

    void set_x(int x_value) {
        x = x_value;
    }

    void set_y(int y_value) {
        y = y_value;
    }
    int get_x() {
        return x;
    }

    int get_y() {
        return y;
    }

    void print() {
        cout << "X: " << x << ", Y:" << y << "\n";
    }
};

int main() {

    /*point p1(1, 2);
    p1.print();*/

    /*int a = 5;
    int* p = &a;*/

    /*point p1(1, 2);
    p1.print();
    point* pointer_p1 = &p1;

    pointer_p1->set_x(1000000);
    pointer_p1->print();*/

    /*point* p1 = new point(2, 3);
    p1->print();*/
    
    // Статичні масиви з об'єктів: 
    /*point points[3];
    points[0].set();
    points[0].print();*/

    /*point points1[3] = { point(10, 20), point(20, 10), point(-1488, -52) };
    point points2[3] = { {10, 20}, {20, 10}, {-1488, -52} };*/

    // Динамічні масиви з об'єктів: 
    //point* points1 = new point[0];
    //int size = 3;
    //point* points2 = new point[size]{ {10, 20}, {0, 2}, {-4, 7} };
    //
    //for (int i = 0; i < size; i++) {
    //    /*points2[i].print();*/
    //    /*(points2 + i)->print();*/
    //    (*(points2 + i)).print();
    //}


    return 0;
}