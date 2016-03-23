//==================================
// 00357027 陳威廷
// Homework 1: Prim's Algorithm
//==================================

#include "fileIO.h"
#include "adjMatrix.h"
#include "heap.h"
#include "main.h"
#include "primsMST.h"
#include <conio.h>
#include <iostream>
using namespace std;

int main() {
	adjMatrix *m = new adjMatrix;

	structAdjMatrixInitialize(m);

	m->init(m);
	readFile(m);
	m->show(m);
	cout << "\nMinimal Spanning Tree: \n";
	cout << "\nMinimal Spanning Cost: " << PrimsMST(m) << endl;

 	m->del(m);
	delete m;
	getch();
	return 0;
}
