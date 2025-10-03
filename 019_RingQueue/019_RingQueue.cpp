#include <iostream>
using namespace std;


// Черга - ДСД, яка містить набір еелментів, доступ до яких 
// відюувається за принципом FIFO(First In First Out),
// тобто додавання нового елемента відбувається 
// з одного кінця(кінця черги)
// а видалення
// відбувається з ішого кінця(початку черги).

void line(int count) {
    cout << "\n";
    for (int i = 0; i < count; i++)
        cout << "-";
    cout << "\n";
}

class vector {
private:
    int* data;
    int size;

public:
    vector() {
        data = nullptr;
        size = 0;
    }

    vector(int size) { // 10
        // this->data = new int[size];
        for (int i = 0; i < size; i++)
            add_element_end(rand() % 101 - 50);
    }

    vector(const vector& other) {
        this->data = new int[other.size];
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
            cout << *(data + i) << " ";
        line(100);
    }

    void set_random(int size) {
        for (int i = 0; i < size; i++) {
            add_element_end(rand() % 101 - 50);
        }
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

    void add_element_end(int number) {
        int* p = new int[size + 1];

        for (int i = 0; i < size; i++)
            *(p + i) = *(data + i);

        p[size] = number;
        delete[] data;
        data = p;
        size++;
        p = nullptr;
    }

    void add_element_need(int wher, int number) {
        int* p = new int[size + 1];

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
        int* p = new int[size];

        for (int i = 0; i < size; i++) {
            p[i] = data[i];
        }

        delete[] data;
        data = p;
        p = nullptr;
    }

    void deletee_element_first() {
        size--;
        int* p = new int[size];

        for (int i = 0; i < size; i++) {
            p[i] = data[i + 1];
        }

        delete[] data;
        data = p;
        p = nullptr;
    }

    void delete_element_position(int position) {
        int* p = new int[size - 1];

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

    int search_element_position(int element) {
        for (int i = 0; i < size; i++)
            if (data[i] == element)
                return i;
        return -1;
    }

    void delete_search_element(int element) {
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

    void change_element_by_value(int number, int change_number) {
        int position = search_element_position(number);
        if (position != -1)
            data[position] = change_number;
        else {
            cout << "Not found";

        }
    }

    void change_element_by_position(int position, int change_number) {
        data[position] = change_number;
    }

    void reverse_array() {
        for (int i = 0; i < size / 2; i++) {
            swap(data[i], data[size - i - 1]);
        }
    }

    int get_max() {
        if (size == 0) {
            cout << "Array is empty\n";

            return 0;
        }
        int max_val = data[0];
        for (int i = 1; i < size; i++)
            if (data[i] > max_val)
                max_val = data[i];
        return max_val;
    }

    int get_min() {
        if (size == 0) {
            cout << "Array is empty\n";

            return 0;
        }
        int min_val = data[0];
        for (int i = 1; i < size; i++)
            if (data[i] < min_val)
                min_val = data[i];
        return min_val;
    }

    int get_size() const {
        return size;
    }

    int get_element(int index) {
        if (index < 0 || index >= size) {
            cout << "Incorrect index!\n";

            return 0;
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
        for (int i = 0; i < size; i++)
            cout << *(data + i) << "\n";
        cout << "\t";
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

        int value = get_element(index);
        cout << "Element at index " << index << " is: " << value << endl;

    }




    vector operator=(const vector& other) {
        if (this == &other)
            return *this;

        if (this->data) {
            delete[] this->data;
        }
        this->data = new int[other.size];

        for (int i = 0; i < other.size; i++)
        {
            this->data[i] = other.data[i];
        }
        this->size = other.size;

        return *this;
    }

    int& get_element_by_index(unsigned int index) {
        if (index >= size)
            throw exception("index out of range");

        return data[index];
    }

    int& operator[](unsigned int index) {
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

istream& operator>> (istream& is, vector& obj) {
    obj.set_random(10);
    return is;
}



// Основні операції над чергою:
// 1. Додавання нового елмента в кінець черги
// 2. Перегляд елемента на початку без його видалення
// 3. Перегляд елемента на початку з його видаленням
// 4. Перевірка, чи черга пуста
// 5. Очищення черги


class ring_queue {
    vector data;
public:

    void push(int value) {
        data.add_element_end(value);
    }

    void print() const {
        data.print_v();
    }

    int top() {
        if (!is_empty())
            return data[0];

        throw exception("Queue is empty");
    }


    bool is_empty() const {
        return data.is_empty();
    }

    int pop() {
        if (!is_empty()) {
            int tmp = data[0];
            data.deletee_element_first();
            data.add_element_end(tmp);
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

   

    ring_queue q1;
    ring_queue q2;
    ring_queue q3;

    for (int i = 1; i <= 4; i++)
    {
        q1.push(i);
        q2.push(i);
        q3.push(i);
    }

    cout << "Press enter for play: ";
    getchar();

    for (int i = 0; i <= 4; i++)
    {
        for (int j = 0; j <= rand() % 4 + 1; j++)
        {
            q1.pop();
        }
        for (int h = 0; h <= rand() % 4 + 1; h++)
        {
            q2.pop();
        }
        for (int g = 0; g <= rand() % 4 + 1; g++)
        {
            q2.pop();
        }
    }

    q1.print();
    q2.print();
    q3.print();

    if (q1.top() == q2.top() && q2.top() == q3.top())
        cout << "You win" << "\n";
    else 
        cout << "You lose" << "\n";





    return 0;
}