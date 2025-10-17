#include <iostream>
using namespace std;


// ������� ������ - �� ���, ��� ���������� �� �����,
// ����� � ���� ��� ����� ������ ��������� �� ������� ����� �����
// � ����:
// - ��������� �� ����� �������
// - ��������� �� ������� �������
// - ��������� �� ������


// �������� �������� �������� ������:
// ������ ������� ������������ � ����� ������.
// ���� ��������� ������� ������ �� ���������,
// �� �� ������������ � ����� ����,
// ���� ������, �� � ���

// ����� ������ - �������� �����, ���� �� �� ������
// ���� - �����, �� �� �� �������
// ˳��� ������� - ������� �����, ���� ����������� ���� �� ��������� �����
// ������ ������� - ������� �����, ���� ����������� ������ �� ��������� �����
// ����������� �����, ������� �����
// ���� - �������������� �����, �� ��������� ��� ����������� ��� ��������,
// ��������� �������, ����� � �.�.


struct element {
    int key;
    element* left, * right, * parent;

    element() {
        key = 0;
        left = right = parent = nullptr;
    }
};

class tree {
    element* root;
    int count;

public:
    tree() {
        root = nullptr;
        count = 0;
    }

    void insert(int key) { // 70
        element* node = new element;
        node->key = key;

        element* ptr = nullptr, * tmp = root;

        while (tmp) {
            ptr = tmp;
            if (node->key < tmp->key)
                tmp = tmp->left;
            else
                tmp = tmp->right;
        }

        // ptr

        if (!ptr) // if (node == nullptr)
            root = node;
        else if (node->key < ptr->key)
            ptr->left = node;
        else
            ptr->right = node;

        count++;
    }


    void print(element* node) const {
        if (node) {
            print(node->left);
            cout << node->key << " ";
            print(node->right);
        }
    }

    element* get_root() const {
        return root;
    }

    element* min(element* node) const {

        if (node) {
            while (node->left)
                node = node->left;
        }

        return node;

    }

    // search
    element* search(element* node, int key) {

        while (node && node->key != key) {
            if (key < node->key) node = node->left;
            else node = node->right;
        }
        return node;
    }


};



int main() {
    srand(time(0));


    tree t;

    t.insert(100);
    t.insert(95);
    t.insert(107);
    t.insert(12);
    t.insert(99);
    t.insert(102);
    t.insert(108);


    t.print(t.get_root());

    element* min = t.min(t.get_root());
    if (min)
        cout << "\n" << min->key;

    element* result = t.search(t.get_root(), 102);

    if (result)
        cout << "\n" << result->key;
    else
        cout << "\nNot found";

    return 0;
}