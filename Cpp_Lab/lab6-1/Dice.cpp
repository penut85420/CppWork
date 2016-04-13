#include "main.h"


Dice::Dice(int dm[]) {
	pr = new double[6];
	for (int i = 0; i < 6; i++)
		pr[i] = 1.0 / dm[i];
}

Dice::~Dice() {
	delete [] pr;
}

int Dice::randomThrow() {
	double sum = 0, r = rand() % 100;;
	for (int i = 0; i < 6; i++) {
		sum += pr[i] * 100; 
		if (sum > r) return i + 1;
	}
	return -1;
}

void Dice::unitTest() {
	int result[6] = {0};
	
	for (int i = 0; i < 100000; i++)
		result[randomThrow() - 1]++;
	
	for (int i = 0; i < 6; i++)
		cout << (double)result[i] / 100000 << endl;

	system("PAUSE");
}