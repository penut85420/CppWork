#pragma once
#include "Student.h"

class StudentList {
public:
    StudentList();
    ~StudentList();
    void appendEntry(Student*);
    bool deleteEntry(char*);
    Student* find(char*);

private:
	class Node {
	public:
		Node(Student *data);
		Node();
		~Node();
		friend class StudentList;
	private:
		Student *mData;
		Node *mNext;
	};
	Node *mHead, *mTail;
};