#include <iostream>
#include <ostream>
#include <math.h>
#include <iomanip> 
// Ta Quoc Tuan 20225110
using namespace std;

struct Complex {
    double real;
    double imag;
};

Complex operator + (Complex a, Complex b) {
    Complex z;
    z.real = a.real + b.real;
    z.imag = a.imag + b.imag;
    return z;
}

Complex operator - (Complex a, Complex b) {
    Complex z;
    z.real = a.real - b.real;
    z.imag = a.imag - b.imag;
    return z;
}

Complex operator * (Complex a, Complex b) {
    Complex z;
    z.real = a.real*b.real - a.imag*b.imag;
    z.imag = a.real*b.imag + a.imag*b.real;
    return z;
}

Complex operator / (Complex a, Complex b) {
    /*****************
    # YOUR CODE HERE #
    *****************/
    Complex z;
    Complex b1;
    b1.real = b.real;
    b1.imag = -b.imag;
    z = a*b1;
    z.real /= (pow(b.real,2)+pow(b.imag,2));
    z.imag /= (pow(b.real,2)+pow(b.imag,2));
    return z;
}

ostream& operator << (ostream& out, const Complex &a) {
    out << '(' << std::setprecision(2) << a.real << (a.imag >= 0 ? '+' : '-') << std::setprecision(2) << fabs(a.imag) << 'i' << ')';
    return out;
}

int main() {
    double real_a, real_b, img_a, img_b;
    cin >> real_a >> img_a;
    cin >> real_b >> img_b;
    
    Complex a{real_a, img_a};
    Complex b{real_b, img_b};
    
    cout << a << " + " << b << " = " << a + b << endl;
    cout << a << " - " << b << " = " << a - b << endl;
    cout << a << " * " << b << " = " << a * b << endl;
    cout << a << " / " << b << " = " << a / b << endl;
    
    return 0;
}
// Ta Quoc Tuan 20225110
