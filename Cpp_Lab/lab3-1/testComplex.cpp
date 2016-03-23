#include <cstdlib>
#include <iostream>
#include "Complex.h"
using namespace std;
void main()
{
	double a, b, c;
	Complex x1, x2, t1, t2, result;
	cout << "Please enter three real coefficients a x^2 + b x + c"
		<< endl << " > ";
	cin >> a >> b >> c;

	if (b * b - 4 * a * c < 0) {
		x1.setValue(-b / 2 * a, sqrt(-b * b + 4 * a * c) / 2 / a);
		x2.setValue(-b / 2 * a, -sqrt(-b * b + 4 * a * c) / 2 / a);
	} else {
		x1.setValue((-b + sqrt(b * b - 4 * a * c)) / 2 / a, 0);
		x2.setValue((-b - sqrt(b * b - 4 * a * c)) / 2 / a, 0);
	}

	cout << "x1="; x1.print();
	cout << "x2="; x2.print();
	cout << "The result of (x1^5 + x2^5) / (x2^10 - x1^7) is ";

	t1 = x1; t1.power(5);
	t2 = x2; t2.power(5);
	result = t1; result.add(t2);

	t1 = x1; t1.power(7);
	t2 = x2; t2.power(10);
	t2.subtract(t1);

	result.divid(t2);
	result.print();

    system("PAUSE");
}