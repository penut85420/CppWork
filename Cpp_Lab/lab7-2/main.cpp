#include "main.h"

void main() {
	ifstream fin("ntou2.txt");
	University university(fin);
	university.query();
}