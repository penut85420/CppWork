#include "Iterator.h"

Student Iterator::mDummy;

Iterator::Iterator(void) { }

Iterator::Iterator(StudentList &list) {
	mList = &list;
	mIterator = mList->mHead;
}

Iterator::~Iterator(void) { }

Student* Iterator::operator->() const {
	return mIterator->mData;
}

Student& Iterator::operator*() const {
	return *mIterator->mData;
}