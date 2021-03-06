#pragma once
#include "StudentList.h"
#include "Student.h"
class StudentListIterator {
public:
	StudentListIterator(void);
	StudentListIterator(StudentList&);
	~StudentListIterator(void);
	void reset();
	void next();
	Student &operator*() const;
    Student *operator->() const;
    bool hasMoreData() const;
	void insert(Student*);

private:
	static Student mDummy;
	StudentList::Node *mIterator;
	StudentList *mList;
};