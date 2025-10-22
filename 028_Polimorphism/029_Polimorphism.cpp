#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

int menu_venicle(){
	int choice;
	cout << "1. Car\n";
	cout << "2. Bus\n";
	cout << "3. Motorcycle\n";
	cout << "0. Exit\n";
	cout << "Your choice: ";
	cin >> choice;
	return choice;
}

// ���������� - �������� ���� ���
// ��������� ���������(���������� ������) 
// ��������� �� ������, � ��������� �� ��������
// � ������ ��������� ��������.

// ���� ��'�������� (Early Binding) -
// ��� ��'���� ������ �� ���� ��������� � 
// ������ ������, � ����� ����� ������, ��'�������
// �� ���� ���������.

// ��������� ��� �������� ��'������� ��������� �� ��� ��'����.

// �������� �� ����������� ���� ���� ���������
// �� ���� ���� ��'��� ���������� �����.

// ϳ�� ��'�������� (Late Binding) -
// ��� ��'���� �� ������ �� ���� ��������� �
// ������ ������, � ����� ����� ������, ��'�������
// �� ���� ��������� ��������.

// ��� ����, ��� ��������� �� �������� ��� ��'��������
// ��������� � �������� ���� ��������� ����� �� ����������
// �� ��������� ��������� ����� virtual.
// class A {
// public:
// 	virtual void func() {
// 		cout << "Class A func()" << endl;
//	}
// };
// ��� ��������� ���� ����������� �� ��� ��'����
// � ������ ��������� ��������.
// A* pA = &objB; // objB - ��'��� ����� B
// pA->func(); // ����������� ����� ����� B
// pA = &objC; // objC - ��'��� ����� C
// pA->func(); // ����������� ����� ����� C
// �� � � ����������.


// ����������� ���� - �� ����, ���� ������
// ���� � ���� ����� ���������� �����.






class A {
public:
	virtual void func() {
		cout << "Class A func()" << endl;
	}
};

class B : public A {
public:
	void func() override {
		cout << "Class B func()" << endl;
	}
};

class C : public A {
public:
	void func() {
		cout << "Class C func()" << endl;
	}
};


class venicle {
public:
	virtual void drive() {
		cout << "I am driving on venicle\n";
	}
};

class car : public venicle {
public:
	void drive() override {
		cout << "I am driving on car\n";
	}
};

class bus : public venicle {
public:
	void drive() override {
		cout << "I am driving on bus\n";
	}
};

class motorcycle : public venicle {
public:
	void drive() override {
		cout << "I am driving on motorcycle\n";
	}
};


class weapon {
public:
	virtual void shoot() {
		cout << "I am shooting with weapon\n";
	}
};

class rifle : public weapon {
public:
	void shoot() override {
		cout << "I am shooting with rifle\n";
	}
};

class pistol : public weapon {
public:
	void shoot() override {
		cout << "I am shooting with pistol\n";
	}
};

class shotgun : public weapon {
public:
	void shoot() override {
		cout << "I am shooting with shotgun\n";
	}
};

class player {
public:
	void fire(weapon* w) {
		w->shoot();
	}
};


class payment {
public:
	virtual void withdraw_money() {
		cout << "Withdrawing money from bancomat\n";
	}
};

class cash : public payment {
public:
	void withdraw_money() override {
		cout << "Withdrawing cash from bancomat\n";
	}
};

class card : public payment {
public:
	void withdraw_money() override {
		cout << "Withdrawing money to card from bancomat\n";
	}
};

class nfc : public payment {
public:
	void withdraw_money() override {
		cout << "Withdrawing money using NFC from bancomat\n";
	}
};

class bancomat {
public:
	void get_money(payment* b) {
		b->withdraw_money();
	}
};


// ����������� ����
class venicle_abs {
protected:
	string name, color;
public:

	venicle_abs() : name("Unknown"), color("Unknown") {}
	venicle_abs(string n, string c) : name(n), color(c) {}

	virtual void drive() = 0; // ����� ���������� �����
};

class car_abs : public venicle_abs {
public:

	car_abs() : venicle_abs() {}
	car_abs(string n, string c) : venicle_abs(n, c) {}

	void drive() override {
		cout << "I am driving on car. " << "Car name: " << name << ", color: " << color << endl;
	}
};

class bus_abs : public venicle_abs {
public:

	bus_abs() : venicle_abs() {}
	bus_abs(string n, string c) : venicle_abs(n, c) {}

	void drive() override {
		cout << "I am driving on bus. " << "Bus name: " << name << ", color: " << color << "\n";
	}
};

class motorcycle_abs : public venicle_abs {
public:

	motorcycle_abs() : venicle_abs() {}
	motorcycle_abs(string n, string c) : venicle_abs(n, c) {}

	void drive() override {
		cout << "I am driving on motorcycle. " << "Motocycle name: " << name << ", color: " << color << "\n";
	}
};



// ��������: 







int main()
{
	srand(time(0));

	//A a;
	//a.func();

	//B b;
	//b.func();

	//C c;
	//c.func();

	//A objA;
	//B objB;
	//C objC;

	/*A* pA = &objA;
	B* pB = &objB;
	C* pC = &objC;

	pA->func();
	pB->func();
	pC->func();*/

	//A* pA = nullptr;
	//pA = &objB;
	//pA->func();
	////pA->anotherFunc(); // Error
	//// ���������� ��������� �� ��� ��������� (A*),
	//// � �� �� ��� ��'���� (B)
	//pA = &objC;
	//pA->func();

	//A* pA = nullptr;
	//pA = &objB;
	//pA->func();
	//pA = &objC;
	//pA->func();


	/*int choice = menu_venicle();
	venicle* pV = nullptr;
	car c;
	bus b;
	motorcycle m;
	while (true) {
		system("cls");
		switch (choice)
		{
		case 0:
			cout << "Goodbye!" << endl;
			return 0;
			break;
		case 1:
			pV = &c;
			break;
		case 2:
			pV = &b;
			break;
		case 3:
			pV = &m;
			break;
		default:
			cout << "Invalid choice!" << endl;
			choice = menu_venicle();
			continue;
		}
		pV->drive();
		choice = menu_venicle();
	}*/


	/*player pl;
	rifle r;
	pistol p;
	shotgun s;
	pl.fire(&r);
	pl.fire(&p);
	pl.fire(&s);*/


	/*bancomat h;
	cash ca;
	card cd;
	nfc n;
	h.get_money(&ca);
	h.get_money(&cd);
	h.get_money(&n);*/

	/*const int size = 5;
	venicle* arr[size] = { new car(), new car(), new car(), new motorcycle(), new bus()};

	for (int i = 0; i < size; i++) {
		arr[i]->drive();
	}*/


	/*venicle_abs* v = new car_abs("BMW", "Black");
	v->drive();
	v = new bus_abs("Mercedes", "Yellow");
	v->drive();
	v = new motorcycle_abs("Yamaha", "Blue");
	v->drive();*/


	
	



	return 0;
}
