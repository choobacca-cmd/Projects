#include <iostream>
using namespace std;


// Черга з пріоритетами - це черга, в якій додавання або видалення
// елементів відбувається в залежності до їх пріоритетів





void line(int count) {
    cout << "\n";
    for (int i = 0; i < count; i++)
        cout << "-";
    cout << "\n";
}


class priority_item {
private:
    int data;
    int priority;
public:

    priority_item() {
        data = 0;
        priority = 0;
    }

    priority_item(int data, int priority) {
        this->data = data;
        this->priority = priority;
    }

    void print() const {
        cout << "Data: " << data <<  "      ||      " << "Priority: " << priority << "\n";
    }

    int get_priority() const {
        return priority;
    }

};


ostream& operator<< (ostream& os, const priority_item& obj) {
    obj.print();
    return os;
}



class vector {
private:
    priority_item* data;
    int size;

public:
    vector() {
        data = nullptr;
        size = 0;
    }



    vector(const vector& other) {
        this->data = new priority_item[other.size];
        this->size = other.size;

        for (int i = 0; i < other.size; i++)
        {
            this->data[i] = other.data[i];
            // *(this->data + i) = *(other.data + i);
        }
    }

    void print_v() const {
        line(100);
        for (int i = 0; i < size; i++)
            cout << *(data + i);
        line(100);
    }



    void add_element_start(priority_item number) {
        priority_item* p = new priority_item[size + 1];

        for (int i = 1; i < size + 1; i++)
            *(p + i) = *(data + i - 1);

        p[0] = number;

        delete[] data;
        data = p;
        size++;
        p = nullptr;
    }

    void add_element_end(priority_item number) {
        priority_item* p = new priority_item[size + 1];

        for (int i = 0; i < size; i++)
            *(p + i) = *(data + i);

        p[size] = number;
        delete[] data;
        data = p;
        size++;
        p = nullptr;
    }

    void add_element_need(int wher, priority_item number) {
        priority_item* p = new priority_item[size + 1];

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
        size--;
        priority_item* p = new priority_item[size];

        for (int i = 0; i < size; i++) {
            p[i] = data[i];
        }

        delete[] data;
        data = p;
        p = nullptr;
    }

    void deletee_element_first() {
        size--;
        priority_item* p = new priority_item[size];

        for (int i = 0; i < size; i++) {
            p[i] = data[i + 1];
        }

        delete[] data;
        data = p;
        p = nullptr;
    }

    void delete_element_position(int position) {
        priority_item* p = new priority_item[size - 1];

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





    void delete_elements_from_position(int count, int position) {
        for (int i = 0; i < count; i++)
            delete_element_position(position);
    }

    void delete_array() {
        delete[] data;
        data = nullptr;
        size = 0;
    }




    int get_size() const {
        return size;
    }


    void print() {
        line(100);
        for (int i = 0; i < size; i++)
            cout << *(data + i) << " ";
        line(100);
    }


    void print_info_size() {
        cout << "\n======= ARRAY INFO =======\n";

        if (size == 0) {
            cout << "Array is empty!\n";
            return;
        }
        cout << "Size: " << size << endl;

    }


    vector operator=(const vector& other) {
        if (this == &other)
            return *this;

        if (this->data) {
            delete[] this->data;
        }
        this->data = new priority_item[other.size];

        for (int i = 0; i < other.size; i++)
        {
            this->data[i] = other.data[i];
        }
        this->size = other.size;

        return *this;
    }

    priority_item& get_element_by_index(unsigned int index) {
        if (index >= size)
            throw exception("index out of range");

        return data[index];
    }

    priority_item& operator[](unsigned int index) {
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


ostream& operator<< (ostream& os, const vector& obj) {
    obj.print_v();
    return os;
}



// Основні операції над стеком:
// 1. Додавання нового елмента в кінець черги
// 2. Перегляд елемента на початку без його видалення
// 3. Перегляд елемента на початку з його видаленням
// 4. Перевірка, чи черга пуста
// 5. Очищення черги


class queue {
    vector data;
public:

    void push(priority_item value) {
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

    priority_item top() {
        if (!is_empty())
            return data[0];

        throw exception("Queue is empty");
    }


    bool is_empty() const {
        return data.is_empty();
    }

    priority_item pop() {
        if (!is_empty()) {
            priority_item tmp = data[0];
            data.deletee_element_first();
            return tmp;
        }
        throw exception("Queue is empty");
    }

    void clear() {
        data.delete_array();
    }
};



int main() {
    srand(time(0));

    queue q;

    q.push(priority_item(100, 3));
    q.push(priority_item(200, 1));
    q.push(priority_item(500, 2));
    q.push(priority_item(24300, 5));
    q.push(priority_item(777, 4));

    q.print();









    return 0;
}