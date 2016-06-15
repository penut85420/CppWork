#include "Iterator.h"

Student StudentListIterator::mDummy;

StudentListIterator::StudentListIterator(void) { }

StudentListIterator::StudentListIterator(StudentList &list) {
	mList = &list;
	mIterator = mList->mHead;
}

StudentListIterator::~StudentListIterator(void) { }

Student* StudentListIterator::operator->() const {
	if (mIterator) return mIterator->mData;
	return &mDummy;
}

Student& StudentListIterator::operator*() const {
	return *mIterator->mData;
}

void StudentListIterator::reset() {
	mIterator = mList->mHead->mNext;
}

void StudentListIterator::next() {
	mIterator = mIterator->mNext;
}

bool StudentListIterator::hasMoreData() const {
	if (mIterator == NULL) return false;
	return true;
}

void StudentListIterator::insert(Student *student) {
	StudentList::Node *p = mIterator->mNext;
	mIterator->mNext = new StudentList::Node(student);
	mIterator->mNext->mNext = p;
}