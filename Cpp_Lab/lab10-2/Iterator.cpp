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

void Iterator::reset() {
	mIterator = mList->mHead;
}

void Iterator::next() {
	mIterator = mIterator->mNext;
}

bool Iterator::hasMoreData() const {
	if (mIterator == mList->mTail) return false;
	return true;
}