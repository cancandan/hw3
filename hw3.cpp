//============================================================================
// Name        : hw3.cpp
// Author      : Can Candan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <math.h>
using namespace std;

struct Complex {
	double r;
	double i;

	Complex() {
		r=0;
		i=0;
	}

	Complex(double real, double img) {
		r=real;
		i=img;
	}

	void operator+=(Complex& y) {
		r+=y.r;
		i+=y.i;
	}

	void operator-=(Complex& y) {
		r-=y.r;
		i-=y.i;
	}

	// (a+bi)(c+di)=ac-bd+(ad+bc)i
	void operator*=(Complex& y) {
		double rnew= r*y.r-i*y.i;
		double inew= r*y.i+i*y.r;

		r=rnew;
		i=inew;
	}

	// (a+bi)/(c+di)=(ac+bd)/(c^2+d^2) + (bc-ad)/(c^2+d^2)
	void operator/=(Complex& y) {
		double d=pow(y.r,2)+pow(y.i,2);
		double rnew=(r*y.r+i*y.i)/d;
		double inew=(i*y.r-r*y.i)/d;

		r=rnew;
		i=inew;
	}
};

ostream& operator<<(ostream& out, Complex& z) {
    out << '(' << z.r << ", " << z.i << "i)";
    return out;
}

istream& operator>>(istream& in, Complex& z) {
    cout << "Enter real and imaginary parts: " << endl;
    in >> z.r >> z.i;
    return in;
}

int main() {
	Complex a,b;

	a=Complex(2,3);
	b=Complex(4,5);

	cout << "a =  " << a << endl;
	cout << "b =  " << b << endl;

	a+=b;
	cout << "After a+=b,  a= " << a << endl;

	a-=b;
	cout << "After a-=b,  a= " << a << endl;

	a*=b;
	cout << "After a*=b,  a= " << a << endl;

	a/=b;
	cout << "After a/=b,  a= " << a << endl;

	cin >> a;
	cout << "Your complex number is =  " << a << endl;

	return 0;
}
