#include <iostream>
#include <exception>
#include <string>
using namespace std;

void line(int count) {
    cout << "\n";
    for (int i = 0; i < count; i++)
        cout << "-";
    cout << "\n";
}

template<class T>
class priority_item {
    T data;
    int priority;
public:
    priority_item() {
        data = T();
        priority = 0;
    }

    priority_item(T data, int priority) {
        this->data = data;
        this->priority = priority;
    }

    int get_priority() const {
        return priority;
    }

    T get_data() const {
        return data;
    }

    void print() const {
        cout << "Data: " << data << "\t \t" << "Priority: " << priority << "\n";
    }
};

template<class T>
ostream& operator<< (ostream& os, const priority_item<T>& obj) {
    obj.print();
    return os;
}


template<class T>
class vector {
private:
    T* data;
    int size;

public:
    vector() {
        data = nullptr;
        size = 0;
    }

    vector(const vector<T>& other) {
        this->data = new T[other.size];
        this->size = other.size;

        for (int i = 0; i < other.size; i++)
            this->data[i] = other.data[i];
    }

    bool is_empty() const {
        return size == 0;
    }

    void print_v() const {
        line(50);
        for (int i = 0; i < size; i++)
            cout << data[i];
        line(50);
    }

    void add_element_start(T number) {
        T* p = new T[size + 1];

        for (int i = 1; i < size + 1; i++)
            p[i] = data[i - 1];

        p[0] = number;

        delete[] data;
        data = p;
        size++;
    }

    void add_element_end(T number) {
        T* p = new T[size + 1];

        for (int i = 0; i < size; i++)
            p[i] = data[i];

        p[size] = number;
        delete[] data;
        data = p;
        size++;
    }

    void add_element_need(int where, T number) {
        T* p = new T[size + 1];

        for (int i = 0; i < where; i++) {
            p[i] = data[i];
        }

        p[where] = number;

        for (int i = where; i < size; i++) {
            p[i + 1] = data[i];
        }

        delete[] data;
        data = p;
        size++;
    }

    void deletee_element_first() {
        if (size == 0) return;
        T* p = new T[size - 1];

        for (int i = 0; i < size - 1; i++) {
            p[i] = data[i + 1];
        }

        delete[] data;
        data = p;
        size--;
    }

    void delete_array() {
        delete[] data;
        data = nullptr;
        size = 0;
    }

    int get_size() const {
        return size;
    }

    T& operator[](unsigned int index) {
        if (index >= size)
            throw exception("index out of range");
        return data[index];
    }

    ~vector() {
        delete[] data;
    }
};

template<class T>
ostream& operator<< (ostream& os, const vector<T>& obj) {
    obj.print_v();
    return os;
}


template <class T>
class queue {
    vector<priority_item<T>> data;
public:

    void push(priority_item<T> value) {
        if (is_empty())
            data.add_element_start(value);
        else {
            int count = 0;
            while (count < data.get_size() && data[count].get_priority() <= value.get_priority())
                count++;

            data.add_element_need(count, value);
        }
    }

    void print() const {
        data.print_v();
    }

    priority_item<T> top() {
        if (!is_empty())
            return data[0];

        throw exception("Queue is empty");
    }

    bool is_empty() const {
        return data.is_empty();
    }

    priority_item<T> pop() {
        if (!is_empty()) {
            priority_item<T> tmp = data[0];
            data.deletee_element_first();
            return tmp;
        }
        throw exception("Queue is empty");
    }

    void clear() {
        data.delete_array();
    }
};

class client {
private:
    string name, surname;
    int age;
public:

    client() {
        name = surname = "Null";
        age = 0;
    }

    client(string name, string surname, int age) {
        this->name = name;
        this->surname = surname;
        this->age = age;
    }

    void print() const {
        cout << "Name: " << name << "\t \t" << "Surname: " << surname << "\t" << "Age: " << age << "\n";
    }

    string getName() const {
        return name;
    }
    string getSurname() const {
        return surname;
    }
    int getAge() const {
        return age;
    }
};

ostream& operator<<(ostream& os, const client& c) {
    os << "Name: " << c.getName()
        << "\tSurname: " << c.getSurname()
        << "\t \tAge: " << c.getAge();
    return os;
}


int main() {
    srand(time(0));

    /*queue<int> q;

    q.push(priority_item<int>(100, 3));
    q.push(priority_item<int>(200, 1));
    q.push(priority_item<int>(500, 2));
    q.push(priority_item<int>(24300, 5));
    q.push(priority_item<int>(777, 4));

    q.print();*/

    queue<client> q;

    q.push(priority_item<client>(client("suig", "sadyi", 1065), 3));
    q.push(priority_item<client>(client("dsjhl", "dkj", 3278), 1));
    q.push(priority_item<client>(client("seduifg", "dswjho", 2367), 2));
    q.push(priority_item<client>(client("sjdho", "ghk", 10921), 5));
    q.push(priority_item<client>(client("amsl", "igas", 1278), 4));

    q.print();



    return 0;
}
