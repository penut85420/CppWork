#pragma once
#include "main.h"

class University {
private:
	string mName;
	int numCollege;
	vector<College*> mCollege;

public:
	University(istream&);
	University();
	~University();
	void print(ostream&);
	void unitTest();
	void query();
	string getName(string);
	void viewTeacher(string, ostream&);
	bool checkString(string);
	void viewCourse(string, ostream&);
};