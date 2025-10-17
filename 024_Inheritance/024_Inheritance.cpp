#include <iostream>
#include <string>
using namespace std;

// Наслідування - це механізм, при якому об'єкти одного класу
// отримують властивості об'єкта іншого класу,
// і добавляються властивості, які характерні тільки йому.

// Наслідування - це розширення одного класу іншим класом.

// Людина(прізвище, ім'я, вік) (базовий, батьківський, супер)
// Працівник(зар. плата, посада) (похідний, дочірній, сабкласи)

class person {
protected:
    string surname, name;
    int age;
public:

    person() {
        this->surname = "No set surname";
        this->name = "No set name";
        this->age = 0;
    }

    person(string surname, string name, int age) {
        this->surname = surname;
        this->name = name;
        this->age = age;
    }

    void set_name(string name) {
        this->name = name;
    }

    string get_name() const { return name; }

    void set_surname(string surname) {
        this->surname = surname;
    }

    string get_surname() const { return surname; }

    void set_age(int age) {
        this->age = age;
    }

    int get_age() const { return age; }

    void print() const {
        cout << "Name: " << name << "\n";
        cout << "Surname: " << surname << "\n";
        cout << "Age: " << age << "\n";
    }
};

class employee : person {
private:
    int salary;
public:

    employee() : person() {
        salary = 0;
    }

    employee(string surname, string name, int age, int salary)
        : person(surname, name, age) {
        this->salary = salary;
    }

    void set_salary(int salary) {
        this->salary = salary;
    }

    int get_salary() const { return salary; }

    void print() const {
        person::print();
        cout << "Salary: " << salary << "\n";
    }

};

class student : public person {
protected:
    string class_name;
    int* marks;
    int marks_count;
public:
    student() : person() {
        class_name = "No set class name";
        marks_count = 10;
        marks = new int[marks_count] {};
    }

    student(string surname, string name, int age, string class_name, int* marks, int marks_count)
        : person(surname, name, age) {
        this->class_name = class_name;
        this->marks_count = marks_count;
        this->marks = new int[marks_count];
        for (int i = 0; i < marks_count; i++)
            this->marks[i] = marks[i];
    }

    double get_average_mark() const {
        int sum = 0;
        for (int i = 0; i < marks_count; i++)
            sum += marks[i];
        return (double)sum / marks_count;
    }

    void print() const {
        person::print();
        cout << "Class Name: " << class_name << "\n";
        cout << "Average mark: " << get_average_mark() << "\n";
    }
};

class manager : employee {
private:
    string department;
    int team_size;
public:
    manager() : employee() {
        department = "No set department";
        team_size = 0;
    }

    manager(string surname, string name, int age, int salary, string department, int team_size)
        : employee(surname, name, age, salary) {
        this->department = department;
        this->team_size = team_size;
    }

    void set_department(string department) { 
        this->department = department; 
    }

    string get_department() const { return department; }

    void set_team_size(int team_size) { 
        this->team_size = team_size; 
    }

    int get_team_size() const { return team_size; }

    void print() const {
        employee::print();
        cout << "Department: " << department << "\n";
        cout << "Team size: " << team_size << "\n";
    }
};

class aspirant : public student {
private:
    string dyplom_title;
    int dyplom_mark;
public:
    aspirant() : student() {
        dyplom_title = "No set dyplom_title";
        dyplom_mark = 0;
    }

    aspirant(string surname, string name, int age, string class_name,
        int* marks, int marks_count, string dyplom_title, int dyplom_mark)
        : student(surname, name, age, class_name, marks, marks_count) {
        this->dyplom_title = dyplom_title;
        this->dyplom_mark = dyplom_mark;
    }

    bool has_diploma(int mark) const {
        double total = get_average_mark() + dyplom_mark;
        return total >= mark;
    }

    void print() const {
        student::print();
        cout << "Dyplom title: " << dyplom_title << "\n";
        cout << "Dyplom mark: " << dyplom_mark << "\n";
        cout << "Diploma result: " << (has_diploma(18) ? "Received " : "Not received ") << "\n";
    }
};
int main()
{
    //employee e("Snow", "John", 30, 1000);

    ///*e.set_name("Jonh");
    //e.set_surname("Show");
    //e.set_age(30);
    //e.set_salary(1000);*/
    //e.print();

    //student s("King", "Jack", 20, "MV34");

    ///*s.set_name("Jack");
    //s.set_surname("King");
    //s.set_age(20);
    //s.set_class_name("MV34");*/
    //s.print();

    /*employee e;
    e.print();
    student s;
    s.print();*/

    /*manager m("Plop", "Artem", 30, 1000, "Program", 10);
    m.print();
    cout << "\n";*/

    int marks[10] = { 4, 5, 4, 5, 5, 4, 5, 5, 5, 5};
    aspirant a("Orach", "Max", 16, "P-45", marks, 10, "C++", 15);

    a.print();


    return 0;
}