#include <iostream>
#include "Complex.h"
using namespace std;

int main() {
	Complex *c = new Complex[10], sum;
	int i;

	sum.setValue(0, 0);

	for (i = 1; i < 11; i++)
		c[i - 1].setValue(i, i);

	for (i = 0; i < 10; i++)
		sum.add(c[i]);

	&cout << sum;

	getchar();
	return 0;
}