#pragma once
#include "Student.h"

class StudentList {
	friend class Iterator;

public:
    StudentList();
    ~StudentList();
    void appendEntry(Student*);
    bool deleteEntry(char*);
    Student* find(char*);
	int size() const;
	Student*& operator[](int);

private:
	class Node {
		friend class Iterator;
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