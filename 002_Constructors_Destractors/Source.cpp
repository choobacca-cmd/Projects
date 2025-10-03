#include <iostream>
using namespace std;

#define NAME_SIZE 100
#define GRADE_COUNT 5
#define GROUP_NAME 100
#define STUDENTS 100


// Конструктор - метод класу, який автоматично викликається 
// при створені об'кта
// Завдання конструктора
// - Ініціалізація об'єкта
// - Виділення пам'яті4

// Конструктори переваджно описують в 'public' секції

// Конструктори можна перевантажувати
// Якщо ми не описуємо свого власного конструктора, то нам надається 
// конструктор за замовчуванням

// Якщо ми описали власний конструктор, то конструктор за замовчуванням видаляється


class point {
private:
    int x, y;
public:
    // конструктори
    point() {
        x = 0;
        y = 0;
    }

    point(int x_value, int y_value) {
        x = x_value;
        y = y_value;
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

class student {
private:
    char* name;
    int age;
public:

    student() {
        name = new char[100];
        age = 0;
    }

    student(const char* name, int age) {
        this->age = age;
        
        this->name = new char[strlen(name) + 1];
        strcpy_s(this->name, strlen(name) + 1, name);
    }

    void set() {
        cout << "Enter name: " << "\n";
        gets_s(name, 100);
        cout << "Enter age: ";
        cin >> age;
    }

    void print() {
        cout << "Name: " << name << ", Age: " << age << "\n";
    }

    ~student() {
        delete[] name;
        cout << "Destructor";
    }

};

class student2 {
private:
    char* surname;
    int* grade;
public: 
    student2() {
        surname = new char[NAME_SIZE];
        grade = new int[GRADE_COUNT];
    }

    void set() {
        cout << "Enter student surname: " << "\n";
        gets_s(surname, NAME_SIZE);
        cout << "Enter grade: ";
        for (int i = 0; i < GRADE_COUNT; i++)
        {
            cin >> grade[i];
        }
        cin.ignore();
    }

    void print() {
        cout << "Surname: " << surname << "\n";
        cout << "Grade: ";
        for (int i = 0; i < GRADE_COUNT; i++)
        {
            cout << grade[i] << ", ";
        }
        cout << "\n";
    }

    ~student2() {
        delete[] surname;
        delete[] grade;
        cout << "Destructor";
    }

};

class group {
private:
    char* group_name;
    student2* students; 
    int student_count;
public:
    group(int student_count) {
        group_name = new char[GROUP_NAME];
        students = new student2[student_count];
        this->student_count = student_count;
    }
    

    void set() {
        cout << "Type group name: ";
        gets_s(group_name, NAME_SIZE);
        for (int i = 0; i < student_count; i++) {
            cout << "Enter info for student " << i + 1 << ":\n";
            students[i].set();
        }
    }

    void print() {
        cout << "Group name: " << group_name << "\n";
        for (int i = 0; i < student_count; i++) {
            students[i].print();
        }
    }

    ~group() {
        delete[] group_name;
        delete[] students; 
        cout << "Destructor";
    }


};

int main() {

    //point p1;
    //p1.print();
    
    //point p2(1, 2);
    //p2.print();


    //student s1;
    //s1.set();
    //s1.print();

    //student s2("Max", 100);
    //s2.print();

    group g1(2);
    g1.set();
    g1.print();

    group g2(3);
    g2.set();
    g2.print();

	return 0;
}
