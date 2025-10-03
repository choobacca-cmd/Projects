#include <iostream>
using namespace std;

#define NAME_SIZE 100

class stud {
    char* surname;
public:
    stud() {
        surname = new char[NAME_SIZE];
    }

    stud(const char* surname) {
        this->surname = new char[strlen(surname) + 1];
        strcpy_s(this->surname, strlen(surname) + 1, surname);
    }

    // Конструктор копіювання: 
    stud(const stud& other) {
        this->surname = new char[strlen(other.surname) + 1];
        strcpy_s(this->surname, strlen(other.surname) + 1, other.surname);
    }

    void set() {
        cout << "enter surname: ";
        gets_s(surname, NAME_SIZE);
    }

    void print() {
        cout << "Surname: " << surname << "\n";
    }

    ~stud() {
        delete[] surname;
    }
};

// Конструктор копіювання викликається у 3 випадках: 
// 1) Ініціалізація одного об'єкта іншим
// 2) Передача в якості параметра об'єкта в функцію або метод по значенню
// 3) Повернення об'єкта з функції або метода по значенню

// Якщо ми виділяємо динамічну пам'ять і потім в десткрукторі її 
// звільняємо, то ми маємо описати свій конструктор копіювання

void func1(stud s) {
    s.print();
}

stud func2() {
    stud s("Orach");
    return s;
}

int main() {

    // 1 Випадок конструктора копіювання: 
    /*stud s1("John");
    s1.print();*/
    /*stud s2 = s1;
    s2.print();*/

    // 2 Випадок конструктора копіювання: 
    /*func1(s1);*/

    // 3 Випадок конструктора копіювання: 
    /*stud s2 = func2();
    s2.print();*/

    return 0;
}