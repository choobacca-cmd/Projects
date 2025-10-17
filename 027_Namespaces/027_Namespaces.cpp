#include <iostream>
#include <string>
using namespace std;

// Простори імен - це область, яка дозволяє організовувати код і уникати конфліктів імен.
// Вони особливо корисні в великих проектах або при використанні бібліотек.
// В C++ простори імен визначаються за допомогою ключового слова `namespace`.
// Оголошення простору імен:
// namespace my_namespace {
//     // код
// }

namespace ns1 {
	class my_class {
	private:
		int value;
	public:

		my_class() : value(0) {}
		my_class(int v) : value(v) {}

		void set_value(int v) { value = v; }
		int get_value() const { return value; }

		void info() const {
			cout << "Value: " << value << endl;
		}
	};

	class a {
	private:
		int x;
	public:

		a() : x(0) {}
		a(int val) : x(val) {}

		void set_x(int val) { x = val; }
		int get_x() const { return x; }

		void info() const {
			cout << "x: " << x << endl;
		}
	};

	void func() {
		cout << "Function in ns1" << endl;
	}
}

namespace ns2 {
	class my_class {
	private:
		string name;
	public:

		my_class() : name("Default") {}
		my_class(string n) : name(n) {}

		void set_name(string n) { name = n; }
		string get_name() const { return name; }

		void info() const {
			cout << "Name: " << name << endl;
		}
	};

	class a {
	private:
		string address;
	public:

		a() : address("Unknown") {}
		a(string addr) : address(addr) {}

		void set_address(string addr) { address = addr; }
		string get_address() const { return address; }

		void info() const {
			cout << "Address: " << address << endl;
		}
	};

	void func() {
		cout << "Function in ns2" << endl;
	}
}

namespace point2d {
	class point {
	private:
		int x, y;
	public:

		point() : x(0), y(0) {}
		point(int x_val, int y_val) : x(x_val), y(y_val) {}

		void set_x(int x_val) { x = x_val; }
		void set_y(int y_val) { y = y_val; }

		int get_x() const { return x; }
		int get_y() const { return y; }

		void info() const {
			cout << "Point2D(" << x << ", " << y << ")" << endl;
		}
	};
}

namespace point3D {
	class point {
	private:
		int x, y, z;
	public:

		point() : x(0), y(0), z(0) {}
		point(int x_val, int y_val, int z_val) : x(x_val), y(y_val), z(z_val) {}

		void set_x(int x_val) { x = x_val; }
		void set_y(int y_val) { y = y_val; }
		void set_z(int z_val) { z = z_val; }

		int get_x() const { return x; }
		int get_y() const { return y; }
		int get_z() const { return z; }

		void info() const {
			cout << "Point3D(" << x << ", " << y << ", " << z << ")" << endl;
		}
	};
}

namespace synglelinkedlist {
	struct element {
		int data = 0;
		element* next = nullptr;
	};

	class list {
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

				tmp->next = new_element;

				size++;
			}
		}

		void delete_head() {
			if (size == 0) return;

			element* tmp = head;
			head = head->next;
			delete tmp;
			tmp = nullptr;
			size--;
		}

		void delete_tail() {
			if (size == 0) return;

			element* tmp = head;

			if (size == 1) {
				delete_head();
				return;
			}
			else {
				while (tmp->next != tail)
					tmp = tmp->next;

				delete tail;
				tail = tmp;
				tmp->next = nullptr;
				delete tmp;
				tmp = nullptr;
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
}

namespace doublylinkedlist {
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
}

namespace dynamic_memory {
	namespace list {
		struct element {
			int data = 0;
			element* next = nullptr;
		};
		class syngle_linked_list {
			element* head, * tail;
			int size;
		public:
			syngle_linked_list() {
				head = tail = nullptr;
				size = 0;
			}

			~syngle_linked_list() {
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

					tmp->next = new_element;

					size++;
				}
			}

			void delete_head() {
				if (size == 0) return;

				element* tmp = head;
				head = head->next;
				delete tmp;
				tmp = nullptr;
				size--;
			}

			void delete_tail() {
				if (size == 0) return;

				element* tmp = head;

				if (size == 1) {
					delete_head();
					return;
				}
				else {
					while (tmp->next != tail)
						tmp = tmp->next;

					delete tail;
					tail = tmp;
					tmp->next = nullptr;
					delete tmp;
					tmp = nullptr;
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
	}
}

// Використання простору імен директивою using:
using namespace ns1;

using namespace point2d;

using namespace synglelinkedlist;


int main()
{
  
	// Використання простору імен без директиви using: 
	/*ns1::my_class obj1(42);
	obj1.info();
	ns2::my_class obj2("Hello");
	obj2.info();*/

	// Використання директиви using:
	/*my_class obj1(42);
	obj1.info();
	ns2::my_class obj2("Hello");
	obj2.info();*/

	// Завдання 1:
	/*point p2d(3, 4);
	p2d.info();
	point3D::point p3d(5, 6, 7);
	p3d.info();*/

	
	// Завдання 2:
	list list1;
	list1.add_head(10);
	list1.add_tail(20);
	list1.add_pos(1, 15);
	list1.print();

	cout << "\n";

	doublylinkedlist::list list2;
	list2.add_head(30);
	list2.add_tail(40);
	list2.add_pos(1, 35);
	list2.print();

	return 0;
}
