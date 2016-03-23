#include "adjMatrix.h"
#include <iostream>
#include <cstdlib>
#include <cassert>
using namespace std;

void structAdjMatrixInitialize(adjMatrixPtr m) {
	m->init = adjMatrixInitialize;
	m->read = adjMatrixRead;
	m->setMatrix = adjMatrixSetMatrix;
	m->newHead = adjMatrixNewHead;
	m->newEdge = adjMatrixNewEdge;
	m->del = adjMatrixDelete;
	m->show = adjMatrixShow;
}

void adjMatrixInitialize(adjMatrixPtr self) {
	self->edge = self->nodeNum = 0;
	self->head = NULL;
}

void adjMatrixRead(adjMatrixPtr self, fp fin) {
	*fin >> self->nodeNum; file_ignore(fin);
	*fin >> self->edge; file_ignore(fin);
	assert(self->nodeNum && self->edge);
	adjMatrixSetMatrix(self, fin);
}

void adjMatrixSetMatrix(adjMatrixPtr self, fp fin) {
	self->newHead(self);
	for (int i = 0; i < self->edge; i++) {
		int node1, node2, weight;
		*fin >> node1 >> node2 >> weight;
		file_ignore(fin);
		self->newEdge(self, node1, node2, weight);
		self->newEdge(self, node2, node1, weight);
	}
}

void adjMatrixNewEdge(adjMatrixPtr self, int n1, int n2, int w) {
	nodePtr ptr, tmp = new node;

	tmp->_begin = n1;
	tmp->index = n2;
	tmp->value = w;
	tmp->next = NULL;

	ptr = &self->head[n1];
	while (ptr->next != NULL)
		ptr = ptr->next;
	ptr->next = tmp;
}

void adjMatrixNewHead(adjMatrixPtr self) {
	self->head = new nodeData[self->nodeNum];
	for (int i = 0; i < self->nodeNum; i++)
		self->head[i].next = NULL;
}

void adjMatrixDelete(adjMatrixPtr self) {
	for (int i = 0; i < self->nodeNum; i++) {
		nodePtr t, pt;
		pt = &self->head[i];
		t = pt->next;
		while (t != NULL) {
			delete pt;
			pt = t;
			t = pt->next;
		}
	}
}

void adjMatrixShow(adjMatrixPtr self) {
	cout << "\nAdjacency  Matrix: \n";
	cout << "Node: " << self->nodeNum
		<< ", Edge: " << self->edge << endl;
	for (int i = 0; i < self->nodeNum; i++) {
		cout << "[" << i << "]";
		nodePtr ptr = &self->head[i];
		while (ptr->next != NULL) {
			ptr = ptr->next;
			cout << " -> (" << ptr->index
				<< ", " << ptr->value << ")";
		}
		cout << endl;
	}
}

void file_ignore(fp fin) {
	fin->ignore(IGNORE_SIZE, NEW_LINE);
}
