#include "heap.h"
#include <iostream>
#include <iomanip>
using namespace std;

void structHeapInitialize(heapPtr self) {
	self->init = heapInit;
	self->link = heapLink;
	self->head = heapHead;
	self->show = heapShow;
	self->del  = heapDelete;
}

void heapInit(heapPtr self, int node) {
	self->num = node;
	self->data = new int[node];
	for (int i = 0; i < node; i++)
		self->data[i] = -1;
}

void heapLink(heapPtr self, int head, int child) {
	self->data[self->head(self, child)]
		= self->head(self, head);
}

int heapHead(heapPtr self, int node) {
	if (self->data[node] != -1)
		return self->head(self, self->data[node]);
	return node;
}

void heapShow(heapPtr self) {
	if (self->data != NULL) {
		for (int i = 0; i < self->num; i++)
			cout << setw(3) << i;
		cout << endl;

		for (int i = 0; i < self->num; i++)
			cout << setw(3) << self->data[i];
		cout << endl;
	} else cout << "NULL\n";
}

void heapDelete(heapPtr self) {
	delete[] self->data;
}
