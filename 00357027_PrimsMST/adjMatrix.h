#ifndef ADJMATRIX_H_INCLUDED
#define ADJMATRIX_H_INCLUDED

#include "main.h"
#include <fstream>
using namespace std;

typedef struct node nodeData;
typedef struct node* nodePtr;
struct node{
	int value, index;
	int _begin;
	nodePtr next;
};

typedef struct _adjMatrix adjMatrix;
typedef struct _adjMatrix* adjMatrixPtr;
struct _adjMatrix {
	int nodeNum, edge;
	nodeData *head;

	void (*init)(adjMatrixPtr);
	void (*read)(adjMatrixPtr, fp);
	void (*setMatrix)(adjMatrixPtr, fp);
	void (*newHead)(adjMatrixPtr);
	void (*newEdge)(adjMatrixPtr, int, int, int);
	void (*del)(adjMatrixPtr);
	void (*show)(adjMatrixPtr);
};

void structAdjMatrixInitialize(adjMatrixPtr);
void adjMatrixInitialize(adjMatrixPtr);
void adjMatrixRead(adjMatrixPtr, fp);
void adjMatrixSetMatrix(adjMatrixPtr, fp);
void adjMatrixNewHead(adjMatrixPtr);
void adjMatrixNewEdge(adjMatrixPtr, int, int, int);
void adjMatrixDelete(adjMatrixPtr);
void adjMatrixShow(adjMatrixPtr);

void file_ignore(fp);
#endif // ADJMATRIX_H_INCLUDED
