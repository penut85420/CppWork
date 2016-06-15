#pragma once
#include "Student.h"

class Iterator;
class StudentList {
	friend class StudentListIterator;

public:
    StudentList();
    ~StudentList();
    void appendEntry(Student*);
    bool deleteEntry(char*);
    Student* find(char*);
	int size() const;
	Student*& operator[](int);
	void insertEntry(StudentListIterator, Student*);

private:
	class Node {
		friend class StudentListIterator;
		friend class StudentList;

	public:
		Node(Student *data);
		Node();
		~Node();
		
	private:
		Student *mData;
		Node *mNext;
	};
	Node *mHead, *mTail;
};