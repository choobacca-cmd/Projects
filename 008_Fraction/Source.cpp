#include <iostream>
using namespace std;

class fraction {
    int numerator, denominator;
public:

    fraction() {
        numerator = 0;
        denominator = 1;
    }

    fraction(int numerator, int denominator) {
        this->numerator = numerator;
        this->denominator = denominator;
    }

    void set(int numerator, int denominator) {
        this->numerator = numerator;
        this->denominator = denominator;
    }

    void set() {
        cout << "Enter numerator: ";
        cin >> numerator;
        cout << "Enter denominator: ";
        cin >> denominator;
    }

    int get_numerator() const {
        return numerator;
    }

    int get_denominator() const {
        return denominator;
    }


    int get_integer() {
        return numerator / denominator;
    }

    double get_double() {
        return (double)numerator / denominator;
    }

    fraction add(fraction other) {

        int res_numerator =
            this->numerator * other.denominator + this->denominator * other.numerator;

        int res_denominator = this->denominator * other.denominator;

        fraction res;
        res.set(res_numerator, res_denominator);

        return res;
    }



    void print() {
        cout << numerator << "/" << denominator << "\n";
    }

    operator int() {
        return get_integer();
    }
    operator double() {
        return get_double();
    }

    bool operator==(const fraction& other) const {
        return numerator * other.denominator == denominator * other.numerator;
    }

    bool operator!=(const fraction& other) const {
        return !(*this == other);
    }

    bool operator<(const fraction& other) const {
        return numerator * other.denominator < denominator * other.numerator;
    }

    bool operator>(const fraction& other) const {
        return numerator * other.denominator > denominator * other.numerator;
    }

    bool operator<=(const fraction& other) const {
        return numerator * other.denominator <= denominator * other.numerator;
    }

    bool operator>=(const fraction& other) const {
        return numerator * other.denominator >= denominator * other.numerator;
    }

};

fraction operator+(const fraction& first, const fraction& second) {
    int res_numerator =
        first.get_numerator() * second.get_denominator()
        + first.get_denominator() * second.get_numerator();

    int res_denominator = first.get_denominator() * second.get_denominator();

    fraction res(res_numerator, res_denominator);

    return res;
}
fraction operator-(const fraction& first, const fraction& second) {
    int res_numerator = first.get_numerator() * second.get_denominator() - first.get_denominator() * second.get_numerator();
    int res_denominator = first.get_denominator() * second.get_denominator();
    return fraction(res_numerator, res_denominator);
}
fraction operator*(const fraction& first, const fraction& second) {
    int res_numerator = first.get_numerator() * second.get_numerator();
    int res_denominator = first.get_denominator() * second.get_denominator();
    return fraction(res_numerator, res_denominator);
}
fraction operator/(const fraction& first, const fraction& second) {
    if (second.get_numerator() == 0) {
        cout << "Error: Division by zero!" << endl;
        return fraction(0, 1);
    }
    int res_numerator = first.get_numerator() * second.get_denominator();
    int res_denominator = first.get_denominator() * second.get_numerator();
    return fraction(res_numerator, res_denominator);
}

fraction operator+(const fraction& first, int number) {
    return first + fraction(number, 1);
}

fraction operator+(int number, const fraction& first) {
    return first + fraction(number, 1);
}

fraction operator-(const fraction& first, int number) {
    return first - fraction(number, 1);
}

fraction operator-(int number, const fraction& first) {
    return first - fraction(number, 1);
}

fraction operator*(const fraction& first, int number) {
    return first * fraction(number, 1);
}

fraction operator*(int number, const fraction& first) {
    return first * fraction(number, 1);
}

fraction operator/(const fraction& first, int number) {
    return first / fraction(number, 1);
}

fraction operator/(int number, const fraction& first) {
    return first / fraction(number, 1);
}

ostream& operator<<(ostream& os, const fraction& obj) {
    os << obj.get_numerator() << " / " << obj.get_denominator() << "\n";
    return os;
}

istream& operator>>(istream& is, fraction& obj) {
    obj.set();
    return is;
}

int main() {

    fraction f1(3, 4), f2(1, 2);
    /*fraction f3 = f1 + f2;
    f3.print();*/

    fraction f3;

    cin >> f3;
    cout << f3;

    cout << int(f3) << "\n";
    cout << double(f3);

    return 0;
}