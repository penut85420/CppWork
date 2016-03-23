#include <iostream>
#include <conio.h>
using namespace std;

void modifyParameters(int &p1, double &p2) {
	p1 *= p1;
	cout << "\nInput second parameters: ";
	cin >> p2;
}

int main() {
	int p1 = 25;
	double p2 = -1.3;

	cout << "Befor modify: " << endl
		<< "p1: " << p1 << endl
		<< "p2: " << p2 << endl;

	modifyParameters(p1, p2);
	cout << "\nAfter modify: " << endl
		<< "p1: " << p1 << endl
		<< "p2: " << p2 << endl;

	getch();
	return 0;
}
