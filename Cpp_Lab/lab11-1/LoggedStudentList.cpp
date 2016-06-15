#include "LoggedStudentList.h"


LoggedStudentList::LoggedStudentList(ofstream &ofs) 
	: mOfs(ofs) { }


LoggedStudentList::~LoggedStudentList(void) { }

void LoggedStudentList::appendEntry(Student *student) {
	mOfs << "LoggedStudentList::appendEntry()\n    ";
    student->display(mOfs); 
    mOfs << endl;
    StudentList::appendEntry(student);
}

void LoggedStudentList::insertEntry(StudentListIterator iter, Student *student) {
	mOfs << "LoggedStudentList::insertEntry()\n    ";
    student->display(mOfs);
    mOfs << endl;
	StudentList::insertEntry(iter, student);
}

bool LoggedStudentList::deleteEntry(char *id) {
	mOfs << "LoggedStudentList::deleteEntry()\n    ";
	mOfs << *id << endl;
	return StudentList::deleteEntry(id);
}

void LoggedStudentList::dump() {
	mOfs << "End";
}