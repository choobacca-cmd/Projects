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

    // ����������� ���������: 
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

// ����������� ��������� ����������� � 3 ��������: 
// 1) ����������� ������ ��'���� �����
// 2) �������� � ����� ��������� ��'���� � ������� ��� ����� �� ��������
// 3) ���������� ��'���� � ������� ��� ������ �� ��������

// ���� �� �������� �������� ���'��� � ���� � ����������� �� 
// ���������, �� �� ���� ������� ��� ����������� ���������

void func1(stud s) {
    s.print();
}

stud func2() {
    stud s("Orach");
    return s;
}

int main() {

    // 1 ������� ������������ ���������: 
    /*stud s1("John");
    s1.print();*/
    /*stud s2 = s1;
    s2.print();*/

    // 2 ������� ������������ ���������: 
    /*func1(s1);*/

    // 3 ������� ������������ ���������: 
    /*stud s2 = func2();
    s2.print();*/

    return 0;
}