#pragma once
class Complex
{
private:
	double m_real;
	double m_imaginary;
public:
	Complex(void);
	Complex(double, double);
	operator double();
	virtual ~Complex(void);
	double getReal();
	double getImaginary();
	void print();
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

