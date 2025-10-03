#include <iostream>
using namespace std;

void line(int count) {
    cout << "\n";
    for (int i = 0; i < count; i++)
        cout << "-";
    cout << "\n";
}


class vector {
    int* data;
    int size;
public:
    vector() {
        data = nullptr;
        size = 0;
    }

    vector(int size) {
        for (int i = 0; i < size; i++)
        {
            add_element_end(rand() % 101 - 50);
        }
    }

    vector(const vector& other) {
        size = other.size;

        if (size > 0) {
            data = new int[size];
            for (int i = 0; i < size; i++) {
                data[i] = other.data[i];
            }
        }
        else {
            data = nullptr;
        }
    }

    ~vector() {
        delete[] data;
    }

    void print() {
        line(100);
        for (int i = 0; i < size; i++)
            cout << *(data + i) << " ";
        line(100);
    }

    void add_element_end(int number) {
        int* p = new int[size + 1];
        for (int i = 0; i < size; i++)
            p[i] = data[i];

        p[size] = number;
        delete[] data;
        data = p;
        size++;
    }



    void add_element_start(int number) {
        int* p = new int[size + 1];

        for (int i = 1; i < size + 1; i++)
            *(p + i) = *(data + i - 1);

        p[0] = number;

        delete[] data;
        data = p;
        size++;
        p = nullptr;
    }

    int& operator[](unsigned int index) {
        if (index >= size)
            throw exception("index out of range");

        return data[index];
    }

    vector operator=(const vector& other){
        if (this == &other)
            return *this;

        if (this->data){
            delete[] this->data;
        }

        this->data = new int[other.size];

        for (int i = 0; i < other.size; i++)
            this->data[i] = other.data[i];

        this->size = other.size;

        return *this;
    };

    int get_size() {
        return size;
    }

    int get_data(int i) {
        return data[i];
    }
};

ostream& operator<<(ostream& os, vector& obj) {
    for (int i = 0; i < obj.get_size(); i++)
        cout << obj.get_data(i) << " ";
    return os;
}

istream& operator>>(istream& is, vector& obj) {
    for (int i = 0; i < obj.get_size(); i++)
        is >> obj[i];
    return is;
}

int main() {
    setlocale(LC_CTYPE, "ukr");
    srand(time(0));

    /*vector v1(10);

    v1.print();

    vector v2(100);
    v2 = v1;

    v2.print();*/

    vector v(10);
    cin >> v;
    cout << v;

    


    return 0;
}