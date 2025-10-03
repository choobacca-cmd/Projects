#include <iostream>
using namespace std;

// Шаблонні класи

//template<class T>
//class my_class {
//private:
//	T a;
//public:
//	my_class() { a = 0; }
//	my_class(T a) { this->a = a; }
//	void set_a(T a) { this->a = a; }
//	T get_a() const { return a; }
//	void print() const { cout << a << "\n"; }
//}; 

template<class P>
class Point {
private:
	P x, y, z;
public:
	Point() { x = 0; y = 0; z = 0; }
	Point(P x, P y, P z) {
		this->x = x;
		this->y = y;
		this->z = z;
	}
	template<class P>
	friend double func(Point<P> obj1, Point<P> obj2);

	void set() {
		cout << "Type x: ";
		cin >> x;
		cout << "Type y: ";
		cin >> y;
		cout << "Type z: ";
		cin >> z;
	}

	void print() {
		cout << "X: " << x << "\n" << "Y: " << y << "\n" << "Z: " << z << "\n";
	}
};
template<class P>
double func(Point<P> obj1, Point<P> obj2) {
	return sqrt(pow(obj2.x - obj1.x, 2) +
		pow(obj2.y - obj1.y, 2) +
		pow(obj2.z - obj1.z, 2));
}


int main() {
	setlocale(LC_CTYPE, "ukr");
	srand(time(0));

	/*my_class<int> obj(100);
	obj.print();
	my_class<double> obj2(12.382);
	obj2.print();
	my_class<char> obj3('a');
	obj3.print();*/

	Point<int> p1(1, 3, 5);
	Point<int> p2(2, 4, 6);

	cout << func(p1, p2) << "\n";

	Point<double> p3(1.84, 4.49, 18.6);
	Point<double> p4;
	p4.set();

	cout << func(p3, p4) << "\n";



	return 0;
}