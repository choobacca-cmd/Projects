#include <iostream>
#include <string>
using namespace std;


// Стек - ДСД, яка містить набір еелментів, доступ до яких 
// відюувається за принципом LIFO(Last In First Out),
// тобто додавання нового елемента та видалення вже існуючих елементів
// відбувається з одного кінця(вершини стеку).


void line(int count) {
    cout << "\n";
    for (int i = 0; i < count; i++)
        cout << "-";
    cout << "\n";
}


template<typename T>
class vector {
private:
    T* data;
    int size;

public:
    vector() {
        data = nullptr;
        size = 0;
    }

    // УВАГА: Цей конструктор та метод set_random коректно працюватимуть
    // лише для числових типів, які можна присвоїти з int.
    vector(int size) {
        data = nullptr;
        this->size = 0;
        for (int i = 0; i < size; i++)
            add_element_end(rand() % 101 - 50);
    }

    vector(const vector<T>& other) {
        this->data = new T[other.size];
        this->size = other.size;

        for (int i = 0; i < other.size; i++)
        {
            this->data[i] = other.data[i];
        }
    }

    void print_v() const {
        line(100);
        for (int i = 0; i < size; i++)
            cout << *(data + i) << " ";
        line(100);
    }

    // УВАГА: коректно працюватиме лише для числових типів.
    void set_random(int size) {
        // Очищуємо старі дані перед заповненням
        if (this->data) {
            delete[] this->data;
            data = nullptr;
            this->size = 0;
        }
        for (int i = 0; i < size; i++) {
            add_element_end(rand() % 101 - 50);
        }
    }

    void add_element_start(const T& number) {
        T* p = new T[size + 1];

        for (int i = 1; i < size + 1; i++)
            *(p + i) = *(data + i - 1);

        p[0] = number;

        delete[] data;
        data = p;
        size++;
        p = nullptr;
    }

    void add_element_end(const T& number) {
        T* p = new T[size + 1];

        for (int i = 0; i < size; i++)
            *(p + i) = *(data + i);

        p[size] = number;
        delete[] data;
        data = p;
        size++;
        p = nullptr;
    }

    void add_element_need(int wher, const T& number) {
        T* p = new T[size + 1];

        for (int i = 0; i < wher; i++) {
            p[i] = data[i];
        }

        p[wher] = number;

        for (int i = wher; i < size; i++) {
            p[i + 1] = data[i];
        }

        delete[] data;
        data = p;
        size++;
        p = nullptr;
    }

    void deletee_element_last() {
        if (size <= 0) return;
        size--;
        T* p = new T[size];
        for (int i = 0; i < size; i++) {
            p[i] = data[i];
        }
        delete[] data;
        data = p;
        p = nullptr;
    }

    void deletee_element_first() {
        if (size <= 0) return;
        size--;
        T* p = new T[size];
        for (int i = 0; i < size; i++) {
            p[i] = data[i + 1];
        }
        delete[] data;
        data = p;
        p = nullptr;
    }

    void delete_element_position(int position) {
        if (position < 0 || position >= size) return;
        T* p = new T[size - 1];
        for (int i = 0, j = 0; i < size; i++) {
            if (i != position) {
                p[j++] = data[i];
            }
        }
        delete[] data;
        data = p;
        size--;
        p = nullptr;
    }

    int search_element_position(const T& element) {
        for (int i = 0; i < size; i++)
            if (data[i] == element) // Потребує, щоб тип T підтримував оператор ==
                return i;
        return -1;
    }

    void delete_search_element(const T& element) {
        int position = search_element_position(element);
        if (position != -1)
            delete_element_position(position);
        else {
            cout << "Element not found";
        }
    }

    void delete_elements_from_position(int count, int position) {
        for (int i = 0; i < count; i++)
            delete_element_position(position);
    }

    void delete_array() {
        delete[] data;
        data = nullptr;
        size = 0;
    }

    void change_element_by_value(const T& number, const T& change_number) {
        int position = search_element_position(number);
        if (position != -1)
            data[position] = change_number;
        else {
            cout << "Not found";
        }
    }

    void change_element_by_position(int position, const T& change_number) {
        if (position >= 0 && position < size)
            data[position] = change_number;
    }

    void reverse_array() {
        for (int i = 0; i < size / 2; i++) {
            swap(data[i], data[size - i - 1]);
        }
    }

    // УВАГА: Наступні методи (get_max, get_min, sort) коректно працюватимуть 
    // лише для типів, що підтримують оператори порівняння (<, >).
    T get_max() {
        if (size == 0) {
            cout << "Array is empty\n";
            return T(); // Повертає значення за замовчуванням для типу T
        }
        T max_val = data[0];
        for (int i = 1; i < size; i++)
            if (data[i] > max_val)
                max_val = data[i];
        return max_val;
    }

    T get_min() {
        if (size == 0) {
            cout << "Array is empty\n";
            return T();
        }
        T min_val = data[0];
        for (int i = 1; i < size; i++)
            if (data[i] < min_val)
                min_val = data[i];
        return min_val;
    }

    int get_size() const {
        return size;
    }

    T get_element(int index) {
        if (index < 0 || index >= size) {
            cout << "Incorrect index!\n";
            return T();
        }
        return data[index];
    }

    void sort_asc() {
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (data[j] > data[j + 1])
                    swap(data[j], data[j + 1]);
            }
        }
    }

    void sort_desc() {
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (data[j] < data[j + 1])
                    swap(data[j], data[j + 1]);
            }
        }
    }

    void print() {
        line(100);
        for (int i = 0; i < size; i++)
            cout << *(data + i) << " ";
        line(100);
    }

    void print_info_max() {
        cout << "\n======= ARRAY INFO =======\n";
        if (size == 0) {
            cout << "Array is empty!\n";
            return;
        }
        cout << "Max element: " << get_max() << endl;
    }

    void print_info_min() {
        cout << "\n======= ARRAY INFO =======\n";
        if (size == 0) {
            cout << "Array is empty!\n";
            return;
        }
        cout << "Min element: " << get_min() << endl;
    }

    void print_info_size() {
        cout << "\n======= ARRAY INFO =======\n";
        if (size == 0) {
            cout << "Array is empty!\n";
            return;
        }
        cout << "Size: " << size << endl;
    }

    void print_info_index() {
        if (size == 0) {
            cout << "Array is empty!\n";
            return;
        }
        cout << "\n======= ARRAY INFO =======\n";
        int index;
        cout << "Enter index: ";
        cin >> index;

        T value = get_element(index);
        cout << "Element at index " << index << " is: " << value << endl;
    }

    vector<T>& operator=(const vector<T>& other) {
        if (this == &other)
            return *this;
        if (this->data) {
            delete[] this->data;
        }
        this->data = new T[other.size];
        for (int i = 0; i < other.size; i++)
        {
            this->data[i] = other.data[i];
        }
        this->size = other.size;
        return *this;
    }

    T& get_element_by_index(unsigned int index) {
        if (index >= size)
            throw exception("index out of range");
        return data[index];
    }

    T& operator[](unsigned int index) {
        if (index >= size)
            throw exception("index out of range");
        return data[index];
    }

    bool is_empty() const {
        return size == 0;
    }

    ~vector() {
        delete[] data;
    }
};

template<typename T>
ostream& operator<< (ostream& os, const vector<T>& obj) {
    obj.print_v();
    return os;
}

template<typename T>
istream& operator>> (istream& is, vector<T>& obj) {
    obj.set_random(10);
    return is;
}


template<typename T>
class stack {
    vector<T> data;
public:
    void push(const T& value) {
        data.add_element_start(value);
    }

    void print() const {
        data.print_v();
    }

    T top() {
        if (!is_empty())
            return data[0];
        throw exception("Stack is empty");
    }

    bool is_empty() const {
        return data.is_empty();
    }

    T pop() {
        if (!is_empty()) {
            T tmp = data[0];
            data.deletee_element_first();
            return tmp;
        }
        throw exception("Stack is empty");
    }

    void clear() {
        data.delete_array();
    }
};

bool is_correct(string str) {
    stack<char> s;
    string opened_brackets = "([{";
    string closed_brackets = ")]}";

    for (int i = 0; i < str.size(); i++) {
        for (int j = 0; j < opened_brackets.size(); j++) {
            if (str[i] == opened_brackets[j]) {
                s.push(str[i]);
            }
            else if (str[i] == closed_brackets[j]) {
                if (s.is_empty()) return false;
                if (s.top() == opened_brackets[j]) {
                    s.pop();
                    break;
                }
                else {
                    return false;
                }
            }
        }
    }

    return s.is_empty();
}

int main() {
    srand(time(0));

    string str = "({x-y-z}[x+2y]-(z+4x))";
    cout << is_correct(str) << "\n";


    return 0;
}