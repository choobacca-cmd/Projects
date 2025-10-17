#include <iostream>
#include <string>
#include <cmath>
#define PI 3.14
using namespace std;

// Множинне наслідування - це наявність у класу більше одного батьківського класу.
// Приклад:
// class A {};
// class B {};
// class C : public A, public B {};
// Тут клас C наслідує як від класу A, так і від класу B. 
// Це дозволяє класу C мати доступ до членів обох батьківських класів.

// Однак, множинне наслідування може призвести до проблем, таких як "діамантова проблема",
// коли два батьківські класи мають спільного предка.
// Щоб уникнути цих проблем, можна використовувати віртуальне наслідування.
// Приклад віртуального наслідування:
// class A {};
// class B : virtual public A {};
// class C : virtual public A {};
// class D : public B, public C {};
// Тут клас A є спільним предком для класів B і C, але завдяки віртуальному наслідуванню,
// клас D матиме лише одну копію членів класу A.
// Це допомагає уникнути неоднозначностей і проблем, пов'язаних з множинним наслідуванням.

// Приклад множинного наслідування:
class car {
private:
	string wheels;
public:
	car(string wheels) {
		this->wheels = wheels;
	}
	car() { wheels = "4 Wheels"; }
	void setWheels(string w) { wheels = w; }
	string getWheels() { return wheels; }

	void drive() { 
		cout << "Driving a car with " << wheels << endl;
	}
};

class airplane {
private:
	string wings;
public:
	airplane(string wings) {
		this->wings = wings;
	}
	airplane() { wings = "2 Wings"; }
	void setWings(string w) { wings = w; }
	string getWings() { return wings; }
	void fly() { 
		cout << "Flying an airplane with " << wings << endl;
	}
};

class flying_car : public car, public airplane {\
public:
	flying_car(string wheels, string wings) : car(wheels), airplane(wings) {}
	flying_car() : car(), airplane() {}

	void drive_and_fly() {
		drive();
		fly();
	}
};

class circle {
private:
	double radius;
public:

	circle() { radius = 1.0; }
	circle(double radius) { this->radius = radius; }

	void setRadius(double r) { radius = r; }
	double getRadius() { return radius; }

	double area_circle() { return PI * pow(radius, 2); }
	double perimeter_circle() { return 2 * PI * radius; }
};

class squeare {
private:
	double side;
public:

	squeare() { side = 1.0; }
	squeare(double side) { this->side = side; }

	void setSide(double s) { side = s; }
	double getSide() { return side; }

	double area_squeare() { return pow(side, 2); }
	double perimeter_squeare() { return 4 * side; }
};

class CircleinSqueare : public circle, public squeare {
public:

	CircleinSqueare(double radius, double side) : circle(radius), squeare(side) {}
	CircleinSqueare() : circle(), squeare() {}

	void input() {
		double r, s;
		cout << "Enter radius of circle: ";
		cin >> r;
		setRadius(r);
		cout << "Enter side of squeare: ";
		cin >> s;
		setSide(s);
	}

	void output() {
		cout << "Circle radius: " << getRadius() << endl;
		cout << "Circle area: " << area_circle() << endl;
		cout << "Circle perimeter: " << perimeter_circle() << endl;
		cout << "Squeare side: " << getSide() << endl;
		cout << "Squeare area: " << area_squeare() << endl;
		cout << "Squeare perimeter: " << perimeter_squeare() << endl;
	}

	void getPerimeter() {
		cout << "Perimeter of circle: " << perimeter_circle() << endl;
		cout << "Perimeter of squeare: " << perimeter_squeare() << endl;
	}

	void getArea() {
		cout << "Area of circle: " << area_circle() << endl;
		cout << "Area of squeare: " << area_squeare() << endl;
	}
};

int main() {
	srand(time(0));
	setlocale(LC_ALL, "UKR"); 

	/*flying_car fc("4 Wheels", "2 Wings");
	fc.drive_and_fly();
		
	cout << fc.getWheels() << endl << fc.getWings() << endl;*/

	/*CircleinSqueare cs;
	cs.input();
	cs.output();
	cs.getArea();
	cs.getPerimeter();*/


	return 0;
}
