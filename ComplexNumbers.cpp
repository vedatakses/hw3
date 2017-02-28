#include <iostream>

using namespace std;

// representation of Complex Numbers with user defined structure
struct Complex {
    double i;
    double j;

    Complex() {
        i = 0;
        j = 0;
    }

    Complex(double a, double b) {
        i = a;
        j = b;
    }

    ~Complex() {
        cout << "Complex number destructed.."<< endl;
    }

    void operator*=(Complex& z) {
        int i_new = (i * z.i - (j * z.j));
        int j_new = (i * z.j + (j * z.i));
        i = i_new;
        j = j_new;
    }

    void operator+=(Complex& z) {
        i += z.i;
        j += z.j;
    }

    void operator-=(Complex& z) {
        i -= z.i;
        j -= z.j;
    }

};

// left shift operator overloading for Complex Numbers
ostream& operator<<(ostream& out, Complex& z) {
    out << '(' << z.i << ", " << z.j << "j)";
    return out;
}

// right shift operator overloading Complex Numbers
istream& operator>>(istream& in, Complex& z) {
    cout << "Enter reel and imaginer numbers: " << endl;
    in >> z.i >> z.j;
    return in;
}

/**
 *
 * Mathematical operations on user entered two complex numbers.
 *
 * */
int main() {
    Complex c1;
    cin >> c1;

    Complex c2;
    cin >> c2;

    cout << "c1 =  " << c1 << endl;
    cout << "c2 =  " << c2 << endl;

    c1+=c2;
    cout << "c1 = c1 + c2 = " << c1 << endl;

    c1-=c2;
    cout << "c1 = c1 - c2 = " << c1 << endl;

    c1*=c2;
    cout << "c1 = c1 * c2 = " << c1 << endl;

    return 0;
}
