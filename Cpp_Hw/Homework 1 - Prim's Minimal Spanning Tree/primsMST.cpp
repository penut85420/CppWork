#include "primsMST.h"
#include "adjMatrix.h"
#include <iostream>
using namespace std;

int PrimsMST(adjMatrixPtr m) {
	heapPtr h = new heap;
	int sum = 0;
	structHeapInitialize(h);

	h->init(h, m->nodeNum);

	for (int i = 0; i < m->nodeNum; i++) {
		nodePtr _min = getMin(m, h);
		if (_min != NULL) {
			h->link(h, _min->_begin, _min->index);
			showEdge(_min);
			sum += _min->value;
		}
	}
	h->del(h);
	delete h;
	return sum;
}

nodePtr getMin(adjMatrixPtr m, heapPtr h) {
	nodePtr _min = NULL;
	for (int j = 0; j < m->nodeNum; j++) {
		if (!h->head(h, j)) {
			nodePtr ptr = &m->head[j];
			while (ptr->next != NULL) {
				ptr = ptr->next;
				if (h->head(h, ptr->index)) {
					if (_min == NULL) _min = ptr;
					else if (_min->value > ptr->value) _min = ptr;
				}
			}
		}
	}
	return _min;
}

void showEdge(nodePtr _min) {
	cout << "(" << _min->_begin << ", "
		<<  _min->index << ") - "
		<< _min->value << endl;
}
