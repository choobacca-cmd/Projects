#include <iostream>
using namespace std;
#define RECT_SIZE 4

// Об'єктно-орієнтоване програмування(ООП) - це вид прогрумування,
// в якому програма реалізується у вигляді об'єктів, 
// що взаємодіють між собою
// ООП реалізується на основі 3 базовий принципів:
// - Інкапсуляція - це обєднання даних та методів роботи з цими данимо
// в одне єдине ціле - об'єкт. Основна властивість інкапсуляції
// - приховування даних.
// - Наслідування
// - Поліморфізм

// Клас - це спеціальна конструкція, яка використовується для групування
// повязаних між собою даних та функції. Дані називаються поля, а функції
// - методами.

// Функціональне програмування(С)
//struct point {
//    int x;
//    int y;
//};
//
//void set_point(point &p) {
//    cout << "Enter x: ";
//    cin >> p.x;
//    cout << "Enter y: ";
//    cin >> p.y;
//}
//
//void print_point(point p) {
//    cout << "X: " << p.x << ", Y:" << p.y << "\n";
//}

// ООП
class point {
    // дані, поля
private:
    int x, y;

    // функції, методи
public:

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

    // Методи аксесори

    // Модифікатори
    void set_x(int x_value) {
        x = x_value;
    }

    void set_y(int y_value) {
        y = y_value;
    }

    // Інспектори
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

class rectangle {

    point points[RECT_SIZE];

public:

    void set() {
        for (int i = 0; i < RECT_SIZE; i++)
        {
            points[i].set();
        }
    }

    void print() {
        for (int i = 0; i < RECT_SIZE; i++)
        {
            points[i].print();
        }
    }

};



class person {
    char name[100];
    float height;
public:

    void set(const char* name_value, float height_value) {
        strcpy_s(name, name_value);
        height = height_value;
    }

    void print() {
        cout << "Name: " << name << " | Height: " << height << "\n";
    }
};


class fraction {
    int numerator, denominator;
public:
    void set(int n, int d) {
        numerator = n;
        denominator = d;
    }

    void set() {
        cout << "Enter numerator: ";
        cin >> numerator;
        cout << "Enter denominator: ";
        cin >> denominator;
    }

    int get_integer() {
        return numerator / denominator;
    }

    double get_double() {
        return (double)numerator / denominator;
    }

    fraction add(fraction other) {
        
        int res_numerator =
            this->numerator * other.denominator + this->denominator * other.numerator;

        int res_denominator = this->denominator * other.denominator;

        fraction res;
        res.set(res_numerator, res_denominator);

        return res;
    }



    void print() {
        cout << numerator << "/" << denominator << "\n";
    }

};



int main() {

    // C
   /* point p1;

    set_point(p1);
    print_point(p1);*/
   

    // C++
   /* point p1;
    p1.set();
    p1.print();

    point p2;
    p2.set();
    p2.print();*/

   /* point p3;
    p3.set(100, 200);
    p3.print();

    p3.set_y(1000);
    p3.print();*/

    /*point p4;
    p4.set(10, 20);

    cout << p4.get_x();*/


    /*person p1;
    p1.set("john", 185);
    p1.print();*/

  /*  rectangle r;
    r.set();
    r.print();*/


    //fraction f1;
    //f1.set(5, 4); 
    //f1.print();


    //cout << f1.get_integer() << "\n";
    //cout << f1.get_double();

    fraction f1;
    f1.set(2, 3);

    fraction f2;
    f2.set(3, 4);


    fraction f3 = f1.add(f2);
    f3.print();

    cout << f3.get_double();




    return 0;
}
