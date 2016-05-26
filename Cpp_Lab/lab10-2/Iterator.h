#pragma once
#include "StudentList.h"
#include "Student.h"

class Student;
class Iterator {
public:
	Iterator(void);
	Iterator(StudentList&);
	~Iterator(void);
	void reset();
	void next();
	Student &operator*() const;
    Student *operator->() const;
    bool hasMoreData() const;

private:
	static Student mDummy;
	StudentList::Node *mIterator;
	StudentList *mList;
};