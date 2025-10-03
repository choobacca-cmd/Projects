#include <iostream>
using namespace std;

class Train {
private: 
    char* train_number;
    char* train_name;

    int* carriage;
    int* carriage_count;

    int train_count;
public:
    Train() {
        train_number = new char[1000];
        train_name = new char[1000];
        carriage = new int[1000];
        carriage_count = new int[1000];
    }
    Train(const Train& other) {
        this->train_number = new char[strlen(other.train_number + 1)];
        strcpy_s(this->train_number, strlen(other.train_number + 1), other.train_number);
        this->train_name = new char[strlen(other.train_name + 1)];
        strcpy_s(this->train_name, strlen(other.train_name + 1), other.train_name);
        carriage_count = new int[1000];
        for (int i = 0; i < 1000; i++)
        {
            carriage_count[i] = other.carriage_count[i];
        }
        carriage = new int[1000];
        for (int i = 0; i < 1000; i++)
        {
            carriage[i] = other.carriage[i];
        }
    }

    ~Train() {
        delete[] train_name;
        delete[] train_number;
        delete[] carriage;
        delete[] carriage_count;
    }

    void set() {
        cout << "Type train count: ";
        cin >> train_count;
        for (int i = 0; i < train_count; i++)
        {
            cout << "Type carriage count: ";
            cin >> carriage_count[i];
            for (int i = 0; i < carriage_count[i]; i++)
            {
                cout << "Type number of passengers in " << i << "carriage: ";
                cin >> carriage[i];
            }
        }
    }

    void print() {
        cout << "Train count: " << train_count << "\n";
        cout << "Carriage count: ";
        for (int i = 0; i < 1000; i++)
        {
            cout << carriage_count[i] << ", ";
            for (int i = 0; i < carriage_count[i]; i++)
            {
                cout << "Number of passengers in " << i << " carriage: "<<carriage[i];
            }
        }
    }

};

int main() {
    Train t1;
    t1.set();
    t1.print();

    return 0;
}