#include "fileIO.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cassert>
using namespace std;

void readFile(adjMatrix *m) {
	string fileName;
	ifstream fin;

	cout << "File name: ";
	cin >> fileName;
//	fileName = "data1.dat";
	fin.open(fileName.c_str());
	assert(fin != NULL);
	m->read(m, &fin);
	fin.close();
}
