#include "Complex.h"
#include <iostream>
#include <cmath>
#include <cassert>
using namespace std;

Complex::Complex(void)
{
}

Complex::~Complex(void)
{
}

void Complex::setValue(double real, double imaginary) {
	m_real = real;
	m_imaginary = imaginary;
}

double Complex::getReal() {
	return m_real;
}

double Complex::getImaginary() {
	return m_imaginary;
}

void Complex::print() {
	cout << m_real << showpos
		 << m_imaginary << "i\n" << noshowpos;
}

void Complex::add(Complex c) {
	m_real += c.m_real;
	m_imaginary += c.m_imaginary;
}

void Complex::subtract(Complex c) {
	c.negitive();
	this->add(c);
}

void Complex::multiply(Complex c) {
	double t_real, t_imaginary;
	t_real = m_real * c.m_real - m_imaginary * c.m_imaginary;
	t_imaginary = m_real * c.m_imaginary + m_imaginary * c.m_real;
	this->setValue(t_real, t_imaginary);
}

bool Complex::divid(Complex c) {
	double PinkiePie = c.m_real * c.m_real + c.m_imaginary * c.m_imaginary;
	if (!PinkiePie) return false;
	c.setValue(c.m_real, -c.m_imaginary);
	this->multiply(c);
	m_real /= PinkiePie;
	m_imaginary /= PinkiePie;
	return true;
}

void Complex::negitive() {
	m_imaginary = -m_imaginary;
	m_real = -m_real;
}

bool Complex::equal(Complex c, double diviation) {
	c.subtract(*this);
	if (c.m_real < diviation && c.m_real > -diviation && 
		c.m_imaginary < diviation && c.m_imaginary > -diviation)
		return true;
	return false;
}

double Complex::magnitude() {
	return sqrt(m_real * m_real + m_imaginary * m_imaginary);
}

void Complex::power(int n) {
	Complex tmp = *this;
	for (int i = 0; i < n; i++)
		tmp.multiply(*this);
	*this = tmp;
}

void Complex::unitTest() {
	Complex c1, c2, c3;
    c1.setValue(7, 3);
    c2.setValue(1, 1);
    c3.setValue(5, -2); // (7+3i)/(1+i) = (5-2i)
    assert(c1.divid(c2));
	c1.print();
    assert(c1.equal(c3, 1e-10)); // C/C++ 常數 1e-10 代表 1x10-10
    c2.setValue(0, 0);
    assert(!c1.divid(c2));
}