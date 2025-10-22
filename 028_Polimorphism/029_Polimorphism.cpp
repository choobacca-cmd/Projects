#include <iostream>
#include <string>
using namespace std;

// Поліморфізм - здатність коду при
// постійному інтерфейсі(зовнішньому вигляді) 
// працювати по різному, в залежності від ситуації
// в момент виконання програми.

class A {
public:
	void func() {
		cout << "Class A func()" << endl;
	}
};

class B : public A {
public:
	void func() {
		cout << "Class B func()" << endl;
	}
};

class C : public A {
public:
	void func() {
		cout << "Class C func()" << endl;
	}
};

int main()
{
	srand(time(0));

	A a;
	a.func();

	B b;
	b.func();

	C c;
	c.func();



	return 0;
}
