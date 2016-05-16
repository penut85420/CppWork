#include "StudentList.h"


StudentList::StudentList(void) { 
	mTail = mHead = new Node();
	mHead->mNext = NULL;
}

StudentList::~StudentList(void) {
	Node *tmp, *n = mHead;
	while (n != NULL) {
		tmp = n;
		n = n->mNext;
		delete tmp;
	}
}

StudentList::Node::Node(Student *data) {
	mData = data;
}

StudentList::Node::Node() : mData(NULL), mNext(NULL) {
}

StudentList::Node::~Node() {
	delete mData;
}

void StudentList::appendEntry(Student *s) {
	mTail->mNext = new Node(s);
	mTail = mTail->mNext;
	mTail->mNext = NULL;
}

bool StudentList::deleteEntry(char *id) {
	Student *result = find(id);
	if (result == NULL) return false;
	for (Node *p = mHead->mNext; p != NULL; p = p->mNext) {
		if (p->mNext->mData == result) {
			Node *t = p->mNext;
			p->mNext = p->mNext->mNext;
			delete t;
			return true;
		}
	}
}

Student* StudentList::find(char *id) {
	for (Node *p = mHead->mNext; p != NULL; p = p->mNext)
		if (p->mData->matchID(id)) return p->mData;
	return NULL;
}