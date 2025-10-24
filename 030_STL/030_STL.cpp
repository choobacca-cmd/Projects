#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <ctime>
#include <cmath>
using namespace std;

// STL (Standard Template Library) - стандартна бібліотека шаблонів

// vector
// list
// queue
// stack
// map, multimap, set, multiset

// контейнери - це шаблони класів, які реалізують певні структури даних
// контейнери бувають двох типів: послідовні (sequence containers
// та асоціативні (associative containers)
// послідовні контейнери зберігають елементи в певному порядку
// асоціативні контейнери зберігають елементи за ключем

// ітератори - це об'єкти, які дозволяють обходити елементи контейнерів
// ітератори бувають різних типів: вказівники, об'єкти класів

// алгоритми - це функції, які виконують певні операції над елементами контейнерів
// алгоритми бувають різних типів: сортування, пошук, копіювання, зміна
// алгоритми працюють з ітераторами
// алгоритми не змінюють контейнери, а повертають нові значення або контейнери
// алгоритми визначені в заголовку <algorithm>
// приклади алгоритмів: sort, find, copy, transform

// функтори - це об'єкти, які поводяться як функції
// функтори створюються шляхом перевантаження оператора ()
// функтори використовуються в алгоритмах для визначення поведінки

template<class T>
void print_vector(const vector<T>& v) {
	for (T el : v) {
		cout << el << " ";
	}
	cout << endl;
}

template <class T>
class my_vector : public vector<T> {
public:

	void print_vector() {
		for (T el : *this) {
			cout << el << " ";
		}
		cout << "\n";
	}

};

class point {
private:
	int x, y;
public:

	point() : x(0), y(0){}
	point(int x, int y) : x(x), y(y) {}

	friend ostream& operator << (ostream& os, const point& obj);
};

ostream& operator << (ostream& os, const point& obj) {
	os << "x = " << obj.x << ", " << "y = " << obj.y << "\n";
	return os;
}

int main() {
	srand(time(0));
	setlocale(LC_ALL, "UKR");

	//vector<int> v = {10, -3, 0, 4, 11, 3, 9};

	//v.push_back(7);
	///*for (int i = 0; i < v.size(); i++)
	//{
	//	cout << v[i] << " ";
	//}*/

	//print_vector(v);

	//v[3] = 200;

	//print_vector(v);

	//v.pop_back();

	//print_vector(v);

	/*my_vector<int> v2;
	v2.push_back(00);
	v2.push_back(200);
	v2.push_back(300);
	v2.print_vector();*/


	/*vector<int>::iterator it = v.begin();*/

	/*it++;
	it--;
	it + 2;
	it - 2;

	it += 10;

	advance(it, 10);*/
	
	/*for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << "\n";


	int i = 0;
	for (vector<int>::iterator it = v.begin(); i < v.size(); i++) {
		cout << *(it + i) << " ";
	}
	cout << "\n";*/

	/*vector<int>::iterator it = v.begin();

	cout << *(it + 3) << "\n";
	it += 3;
	cout << *(it) << "\n";*/

	/*for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		*it = 100;
	}*/
	

	/*vector<int> v = { 10, -3, 0, 4, 11, 3, 9 };*/

	// advance
	// distance

	/*vector<int>::iterator it = v.begin();*/

	/*it++;
	it += 2;
	advance(it, 2);*/

	/*advance(it, 5);
	cout << distance(v.begin(), it);*/

	/*v.insert(v.begin() + 5, 500);
	v.insert(v.begin() + 5, 34);
	print_vector(v);

	v.erase(v.begin() + 5, v.begin() + 6);
	print_vector(v);*/


	// auto

	/*auto a = 10;*/

	/*vector<int> v = { 10, -3, 0, 4, 11, 3, 9 };*/

	/*auto it = v.begin();*/

	/*vector<string> countries = { "USA", "Ukraine", "France", "Spain", "Germany" };
	vector<string>::iterator it = countries.begin();

	countries.insert(it, "Italy");

	print_vector(countries);*/

	/*vector<point> points = { point(1, 2), point(4, 5), point(10, -2) };
	print_vector(points);*/

	
	/*vector<int> v;

	v.push_back(pow(1, 2));
	v.push_back(pow(2, 2));
	v.push_back(pow(3, 2));
	v.push_back(pow(4, 2));
	v.push_back(pow(5, 2));
	v.push_back(pow(6, 2));
	v.push_back(pow(7, 2));
	v.push_back(pow(8, 2));
	v.push_back(pow(9, 2));
	v.push_back(pow(10, 2));

	print_vector(v);*/

	int rows = 10, cols = 10;
	int count = 1;
	vector<vector<int>> v(rows);

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			v[i].push_back(count++);
		}
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << v[i][j] << " ";
		}
		cout << "\n";
	}













	return 0;
}

