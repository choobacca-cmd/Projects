#include <iostream>
using namespace std;

class point {
private:
    int x, y;
public:
    static int count;
    static int liveObjects;

    point() {
        x = y = 0;
        count++;
        liveObjects++;
    }

    point(int x, int y) {
        this->x = x;
        this->y = y;
        count++;
        liveObjects++;
    }

    ~point() {
        liveObjects--;
    }

    void set() {
        cout << "Enter x: ";
        cin >> x;
        cout << "Enter y: ";
        cin >> y;
    }

    void set(int x, int y) {
        this->x = x;
        this->y = y;
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

class Employee {
private:
    char* surname;
    int id;
    static int check;
public:

    Employee(const char* surname) {
        this->surname = new char[strlen(surname) + 1];
        strcpy_s(this->surname, strlen(surname) + 1, surname);
        id += check;
        check++;
    }

    Employee() {
        surname = new char[1000];
        id = check++;
    }

    void print() {
        cout << "Employee surname: " << surname << "\n" << "Employee id: " << id <<"\n";
    }

    static int get_last_id() {
        return check;
    }

};

// Статичні поля класу - це поля які використовуються спільно всіма об'єктами класу.
// Кажуть, що вони належуть не конкретному об'єкту, а класу вцілому.

int point::count = 0;
int point::liveObjects = 0;

int Employee::check = 1;



class my_math {
public:
    static const double PI;

    static int sum(int a, int b) {
        return a + b;
    }

    static int sub(int a, int b) {
        return a - b;
    }

    static int mul(int a, int b) {
        return a * b;
    }

    static int div(int a, int b) {
        return a / b;
    }

    static int square(int a) {
        return a * a;
    }
};

const double my_math::PI = 3.14;

template<class T>
class my_S {
private:
    static int count;
public:

    static double s_triangle1(T a, T h) {
        T S = (a * h) / 2;
        count++;
        return S;
    }
    static double s_triangle2(T a, T b, T angle) {
        T S = (a * b * sin(angle)) / 2;
        count++;
        return S;
    }

    static double s_rectangle(T a, T b) {
        count++;
        return a * b;
    }

    static double s_square(T a) {
        count++;
        return a * a;
    }

    static double s_rhombus(T a, T h) {
        count++;
        return a * h;
    }
};

template<class T>
int my_S<T>::count = 0;

int main() {

    /*point p1(3, 4);
    point p2(1, 0);
    point p3(-1, 9);

    {
        point p4(1, 2);
    }

    p1.set_x(1000);

    cout << point::count <<"\n";
    cout << point::liveObjects;*/


    /*Employee e1("Orach");
    Employee e2("Hcrao");
    Employee e3("OLP");
    Employee e4("PLO");
    Employee e5("dhwdshjhdslk");

    e1.print();
    e2.print();
    e3.print();
    e4.print();
    e5.print();*/

    /*cout << Employee::get_last_id();*/

    /*cout << my_math::sum(10, 2);*/

    cout << my_S<int>::s_rectangle(6, 2) << "\n";
    cout << my_S<double>::s_rhombus(3.5, 1.3) << "\n";
    cout << my_S<int>::s_square(5) << "\n";
    cout << my_S<double>::s_triangle1(9.6, 2.43) << "\n";
    cout << my_S<int>::s_triangle2(5, 7, 60) << "\n";

    return 0;
}