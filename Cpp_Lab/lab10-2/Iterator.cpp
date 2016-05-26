#include "Iterator.h"

Student Iterator::mDummy;

Iterator::Iterator(void) { }

Iterator::Iterator(StudentList &list) {
	mList = &list;
	mIterator = mList->mHead;
}

Iterator::~Iterator(void) { }

Student* Iterator::operator->() const {
	if (mIterator) return mIterator->mData;
	return &mDummy;
}

Student& Iterator::operator*() const {
	return *mIterator->mData;
}

void Iterator::reset() {
	mIterator = mList->mHead->mNext;
}

void Iterator::next() {
	mIterator = mIterator->mNext;
}

bool Iterator::hasMoreData() const {
	if (mIterator == mList->mTail) return false;
	return true;
}

void Iterator::insert(Student *student) {
	StudentList::Node *p = mIterator->mNext;
	mIterator->mNext = new StudentList::Node(student);
	mIterator->mNext->mNext = p;
}