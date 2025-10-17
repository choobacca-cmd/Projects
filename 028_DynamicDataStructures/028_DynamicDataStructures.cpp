#include <iostream>
#include <string>
using namespace std;

namespace dynamic_memory {
	namespace vector {
		class vector {
			int* data;
			int size;
		public:
			vector() {
				data = nullptr;
				size = 0;
			}

			vector(int size) {
				for (int i = 0; i < size; i++)
				{
					add_element_end(rand() % 101 - 50);
				}
			}

			vector(const vector& other) {
				size = other.size;

				if (size > 0) {
					data = new int[size];
					for (int i = 0; i < size; i++) {
						data[i] = other.data[i];
					}
				}
				else {
					data = nullptr;
				}
			}

			~vector() {
				delete[] data;
			}

			void print() {
				for (int i = 0; i < size; i++)
					cout << *(data + i) << " ";
				cout << "\n";
			}

			void add_element_end(int number) {
				int* p = new int[size + 1];
				for (int i = 0; i < size; i++)
					p[i] = data[i];

				p[size] = number;
				delete[] data;
				data = p;
				size++;
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

			int& operator[](unsigned int index) {
				if (index >= size)
					throw exception("index out of range");

				return data[index];
			}

			vector operator=(const vector& other) {
				if (this == &other)
					return *this;

				if (this->data) {
					delete[] this->data;
				}

				this->data = new int[other.size];

				for (int i = 0; i < other.size; i++)
					this->data[i] = other.data[i];

				this->size = other.size;

				return *this;
			};

			int get_size() {
				return size;
			}

			int get_data(int i) {
				return data[i];
			}
		};

		ostream& operator<<(ostream& os, vector& obj) {
			for (int i = 0; i < obj.get_size(); i++)
				cout << obj.get_data(i) << " ";
			return os;
		}

		istream& operator>>(istream& is, vector& obj) {
			for (int i = 0; i < obj.get_size(); i++)
				is >> obj[i];
			return is;
		}
	}
	namespace list {
		namespace syngle_linked_list {

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
		namespace doubly_linked_list {
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
	}
	namespace stack {
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

			vector(int size) {
				for (int i = 0; i < size; i++)
					add_element_end(rand() % 101 - 50);
			}

			vector(const vector& other) {
				this->data = new int[other.size];
				this->size = other.size;

				for (int i = 0; i < other.size; i++)
				{
					this->data[i] = other.data[i];
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
				line(100);
				for (int i = 0; i < size; i++)
					cout << *(data + i) << " ";
				line(100);
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

		class stack {
		private:
			vector data;
		public:

			void push(int value) {
				data.add_element_start(value);
			}

			void print() {
				data.print_v();
			}

			int top() {
				if (!is_empty())
					return data[0];

				throw exception("Stack is empty!");
			}

			bool is_empty() const {
				return data.is_empty();
			}

			int pop() {
				if (!is_empty()) {
					int tmp = data[0];
					data.deletee_element_first();
					return tmp;
				}
				throw exception("Stack is empty");
			}

			void clear() {
				data.delete_array();
			}
		};
	}
	namespace queue {
		namespace simple_queue {
			struct element {
				int data = 0;
				element* next = nullptr;
			};
			class queue {
			private:
				element* head, * tail;
				int size;
			public:
				queue() {
					head = tail = nullptr;
					size = 0;
				}
				~queue() {
					clear();
				}
				void enqueue(int value) {
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
				void dequeue() {
					if (size == 0) return;
					element* tmp = head;
					head = head->next;
					delete tmp;
					tmp = nullptr;
					size--;
				}
				void clear() {
					while (size > 0)
						dequeue();
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
		namespace circular_queue {
			struct element {
				int data = 0;
				element* next = nullptr;
			};
			class queue {
			private:
				element* head, * tail;
				int size;
			public:
				queue() {
					head = tail = nullptr;
					size = 0;
				}
				~queue() {
					clear();
				}
				void enqueue(int value) {
					element* new_element = new element;
					new_element->data = value;
					if (size == 0) {
						head = tail = new_element;
						tail->next = head;
					}
					else {
						tail->next = new_element;
						tail = new_element;
						tail->next = head;
						new_element = nullptr;
					}
					size++;
				}
				void dequeue() {
					if (size == 0) return;
					element* tmp = head;
					head = head->next;
					tail->next = head;
					delete tmp;
					tmp = nullptr;
					size--;
				}
				void clear() {
					while (size > 0)
						dequeue();
				}
				void print() const {
					if (size == 0) return;
					element* tmp = head;
					do {
						cout << tmp->data << " ";
						tmp = tmp->next;
					} while (tmp != head);
				}
			};
		}
		namespace priority_queue {
			struct element {
				int data = 0;
				int priority = 0;
				element* next = nullptr;
			};
			class queue {
			private:
				element* head, * tail;
				int size;
			public:
				queue() {
					head = tail = nullptr;
					size = 0;
				}
				~queue() {
					clear();
				}
				void enqueue(int value, int priority) {
					element* new_element = new element;
					new_element->data = value;
					new_element->priority = priority;
					if (size == 0) {
						head = tail = new_element;
					}
					else if (priority < head->priority) {
						new_element->next = head;
						head = new_element;
					}
					else {
						element* tmp = head;
						while (tmp->next && tmp->next->priority <= priority) {
							tmp = tmp->next;
						}
						new_element->next = tmp->next;
						tmp->next = new_element;
						if (new_element->next == nullptr) {
							tail = new_element;
						}
					}
					size++;
				}
				void dequeue() {
					if (size == 0) return;
					element* tmp = head;
					head = head->next;
					delete tmp;
					tmp = nullptr;
					size--;
				}
				void clear() {
					while (size > 0)
						dequeue();
				}
				void print() const {
					element* tmp = head;
					while (tmp) {
						cout << "(" << tmp->data << ", " << tmp->priority << ") ";
						tmp = tmp->next;
					}
				}
			};
		}
		namespace deque {
			struct element {
				int data = 0;
				element* next = nullptr;
				element* prev = nullptr;
			};
			class deque {
			private:
				element* head, * tail;
				int size;
			public:
				deque() {
					head = tail = nullptr;
					size = 0;
				}
				~deque() {
					clear();
				}
				void add_front(int value) {
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
				void add_back(int value) {
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
				void remove_front() {
					if (size == 0) return;
					element* tmp = head;
					head = head->next;
					tmp->prev = nullptr;
					delete tmp;
					tmp = nullptr;
					size--;
				}
				void delete_front() {
					if (size == 0) return;
					element* tmp = head;
					head = head->next;
					tmp->prev = nullptr;
					delete tmp;
					tmp = nullptr;
					size--;
				}
				void remove_back() {
					if (size == 0) return;
					element* tmp = tail;
					if (size == 1) {
						delete_front();
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
				void clear() {
					while (size > 0)
						remove_front();
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
	namespace tree {
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

			void insert(int key) {
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

				if (!ptr) 
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
			element* search(element* node, int key) {

				while (node && node->key != key) {
					if (key < node->key) node = node->left;
					else node = node->right;
				}
				return node;
			}
		};

	}
}

using namespace dynamic_memory;

int main()
{

	vector::vector vec1(10);
	vec1.print();

	cout << "\n";

	list::syngle_linked_list::syngle_linked_list sll;
	sll.set(10);
	sll.print();

	cout << "\n";

	stack::stack st;
	st.push(10);
	st.push(20);
	st.print();

	cout << "\n";

	queue::simple_queue::queue sq;
	sq.enqueue(10);
	sq.enqueue(20);
	sq.print();

	cout << "\n";

	queue::circular_queue::queue cq;
	cq.enqueue(10);
	cq.enqueue(20);
	cq.print();

	cout << "\n";

	queue::priority_queue::queue pq;
	pq.enqueue(10, 2);
	pq.enqueue(20, 1);
	pq.print();

	cout << "\n";

	queue::deque::deque dq;
	dq.add_front(10);
	dq.add_back(20);
	dq.print();

	cout << "\n";

	tree::tree tr;
	tr.insert(10);
	tr.insert(5);
	tr.insert(20);
	tr.print(tr.get_root());

	cout << "\n";
	


	return 0;
}
