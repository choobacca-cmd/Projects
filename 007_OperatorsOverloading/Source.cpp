#include <iostream>
#include <iomanip>
using namespace std;

#define ROWS 4
#define COLS 3

class Matrix {
private:
    int data[ROWS][COLS] = {
        {10, 2, 4},
        {-3, 12, 4},
        {10, 55, 51},
        {-2, 2, 5},
    };
public:

    void print() const {
        for (int i = 0; i < ROWS; i++)
        {
            for (int j = 0; j < COLS; j++)
            {
                cout << setw(5) << data[i][j];
            }
            cout << "\n";
        }
    }

    int& operator()(unsigned int row_index, unsigned int col_index) {
        return data[row_index][col_index];
    }

};

class my_class {
private:
    double x;
public:

    my_class() {
        x = 0;
    }

    my_class(double x) {
        this->x = x;
    }

    void print() const {
        cout << "x = " << x << "\n";
    }

    void set(double x) {
        this->x = x;
    }

    double get_x() const {
        return x;
    }

    /*my_class operator+(const my_class& other) {
        my_class res;
        res.x = this->x + other.x;
        return res;
    }*/

    operator int() {
        return int(x);
    }

};

my_class operator+(const my_class& obj1, const my_class& obj2) {
    return my_class(obj1.get_x() + obj2.get_x());
}

my_class operator-(const my_class& obj1, const my_class& obj2) {
    return my_class(obj1.get_x() - obj2.get_x());
}

bool operator==(const my_class& obj1, const my_class& obj2) {
    return obj1.get_x() == obj2.get_x();
}

bool operator!=(const my_class& obj1, const my_class& obj2) {
    return obj1.get_x() != obj2.get_x();
}

// 1 - метод
// 2 - функція

ostream& operator<<(ostream& os, const my_class& obj) {
    os << "x = " << obj.get_x() << "\n";
    return os;
}

istream& operator>>(istream& is, my_class& obj) {
    double x;
    is >> x;
    obj.set(x);
    return is;
}

int main() {

    /*my_class a(5);
    my_class b(4);

    my_class res = a + b;
    res.print();*/

    /*Matrix m;*/

    /*m.print();
    m(2, 1) = 1000;
    cout << "\n";
    m.print();*/

    my_class obj;

    cin >> obj;

    cout << obj;

    /*double d = 3.12;
    double a = int(d);*/

    cout << int(obj);

    return 0;
}