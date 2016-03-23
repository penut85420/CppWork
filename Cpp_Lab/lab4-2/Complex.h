#pragma once
#include <iostream>
using namespace std;
class Complex
{
private:
	double m_real;
	double m_imaginary;
public:
	Complex(void);
	virtual ~Complex(void);
	void setValue(double,double);
	void setValue(Complex&);
	double getReal();
	double getImaginary();
	void print();
	void print(ostream&);
	void add(Complex);
	void subtract(Complex);
	void multiply(Complex);
	bool divid(Complex);
	void negitive();
	void power(int);
	bool equal(Complex, double);
	double magnitude();
	static void unitTest();
};
//ostream &operator<<(ostream&, Complex);
ostream *operator<<(ostream*, Complex);