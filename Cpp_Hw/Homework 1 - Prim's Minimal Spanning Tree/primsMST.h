#ifndef PRIMSMST_H_INCLUDED
#define PRIMSMST_H_INCLUDED

#include "adjMatrix.h"
#include "heap.h"
int PrimsMST(adjMatrixPtr);
nodePtr getMin(adjMatrixPtr, heapPtr);
void showEdge(nodePtr)
#endif // PRIMSMST_H_INCLUDED
