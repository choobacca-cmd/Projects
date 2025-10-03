#include <iostream>
using namespace std;

// Двозв'язний список - це ДСД, в якому об'єкти складаються із елементів,
// що містять певну інформацію і два вказівники
// один на попередній елемент, інший - на наступний елемент.

int menu() {
    cout << "\n\n0 - Exit\n";
    cout << "1 - Add Head\n";
    cout << "2 - Add Tail\n";
    cout << "3 - Delete Head\n";
    cout << "4 - Delete Tail\n";
    cout << "5 - Delete All\n";
    cout << "6 - Add Pos\n";
    cout << "7 - Delete Pos\n";

    int choice;
    cout << "Enter your choice: ";
    cin >> choice;
    return choice;
}

struct element {
    int data = 0;
    element* next = nullptr;
    element* prev = nullptr;
};

class list {
private:
    element* head, * tail;
    int size;
public:
    list() {
        head = tail = nullptr;
        size = 0;
    }

    ~list() {
        clear();
    }

    void add_head(int value) {
        element* new_element = new element;
        new_element->data = value;

        if (size == 0) {
            head = tail = new_element;
        }
        else {
            new_element->next = head;
            head->prev = new_element;
            head = new_element;
            new_element = nullptr;
        }

        size++;
    }

    void add_tail(int value) {
        element* new_element = new element;
        new_element->data = value;

        if (size == 0) {
            head = tail = new_element;
        }
        else {
            tail->next = new_element;
            new_element->prev = tail;
            tail = new_element;
            new_element = nullptr;
        }

        size++;
    }

    void add_pos(int pos, int value) {

        if (size == 0) add_head(value);
        else if (pos == size) add_tail(value);
        else {
            element* new_element = new element;
            new_element->data = value;

            element* tmp = head;

            int i = 0;
            while (i++ < pos - 1)
                tmp = tmp->next;

            new_element->next = tmp->next;
            new_element->prev = tmp;
            tmp->next->prev = new_element;

            tmp->next = new_element;

            size++;
        }
    }

    void delete_head() {
        if (size == 0) return;

        element* tmp = head;
        head = head->next;
        tmp->prev = nullptr;
        delete tmp;
        tmp = nullptr;
        size--;
    }

    void delete_tail() {
        if (size == 0) return;

        element* tmp = tail;

        if (size == 1) {
            delete_head();
            return;
        }
        else {
            tail = tail->prev;
            tail->next = nullptr;
            delete tmp;
            tmp = nullptr;
            size--;
            return;
        }
    }

    void delete_pos(int pos) {

        if (pos == 0)
        {
            delete_head();
        }
        else if (pos == size) {
            delete_tail();
        }
        else if (pos > size || pos < size) {
            return;
        }
        else { 
            element* tmp = head;
            element* delt = nullptr;
            int i = 0;
            while (i != pos - 1) {
                i++;
                tmp = tmp->next;
            }
            delt = tmp->next;
            tmp->next = delt->next;
            delt->next->prev = tmp;
            delete delt;
            delt = nullptr;
            size--;
            return;
        }
    }

    void clear() {
        while (size > 0)
            delete_head();
    }

    void set(int size) {
        for (int i = 0; i < size; i++) {
            add_head(rand() % 100 + 1);
            this->size = size;
        }
    }

    void print() const {
        element* tmp = head;

        while (tmp) {
            cout << tmp->data << " ";
            tmp = tmp->next;
        }
    }
};

int main() {
    srand(time(0));

    int number;

    list l;
    l.set(10);

    do {
        system("cls");
        l.print();

        int choice = menu();
        if (!choice) break;

        switch (choice)
        {
        case 1:
            cout << "Enter number: ";
            cin >> number;
            l.add_head(number);
            break;
        case 2:
            cout << "Enter number: ";
            cin >> number;
            l.add_tail(number);
            break;
        case 3:
            l.delete_head();
            break;
        case 4:
            l.delete_tail();
            break;
        case 5:
            l.clear();
            break;
        case 6:
            int pos;
            int num;
            cout << "Enter pos: ";
            cin >> pos;
            cout << "Enter num: ";
            cin >> num;
            l.add_pos(pos, num);
            break;
        case 7:
            int pos1;
            cout << "Enter pos: ";
            cin >> pos1;
            l.delete_pos(pos1);
            break;
        default:
            cout << "Incorrect input";
            break;
        }
    } while (true);


    return 0;
}