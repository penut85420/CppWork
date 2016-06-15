#pragma once
#include "StudentList.h"
#include "Iterator.h"
#include <fstream>
using namespace std;

class LoggedStudentList : public StudentList {
public:
	LoggedStudentList(ofstream&);
    void appendEntry(Student *student);
    void insertEntry(StudentListIterator iter, Student *student); 
    bool deleteEntry(char *id);
    void dump();
	LoggedStudentList(void);
	~LoggedStudentList(void);
private:
	ofstream &mOfs;
};

