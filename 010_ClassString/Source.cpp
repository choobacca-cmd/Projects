#include <iostream>
using namespace std;

class String {
private:
	char* str;
	int length;
	void copy_str(const char* str) {
		this->length = strlen(str);
		this->str = new char[this->length + 1];

		for (int i = 0; i < this->length; i++)
			this->str[i] = str[i];

		this->str[this->length] = '\0';
	}
public:
	String() {
		str = nullptr;
		length = 0;
	}

	String(const char* str) {
		copy_str(str);
	}

	String(const String& other) {
		copy_str(other.str);
	}

	~String() {
		delete[] str;
	}

	char* get_str() const {
		return str;
	}

	int get_length() const {
		return length;
	}

	void set() {
		cout << "Type yout string: ";
		cin >> str;
	}

	void print() const {
		if (str == nullptr)
			cout << "Empty!!" << "\n";
		else
			cout << str << "\n";
	}

};

int main() {
	setlocale(LC_CTYPE, "ukr");
	srand(time(0));

	String str("Hello world!!");
	str.print();

	String str2 = str;
	str2.print();



	return 0;
}
