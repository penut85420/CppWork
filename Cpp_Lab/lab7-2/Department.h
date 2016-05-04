#pragma once
#include "main.h"

class Department {
private:
	string mName;
	int numTeacher, numCourse;
	vector<Teacher*> mTeacher;
	vector<Course*> mCourse;
	
public:
	Department(istream&);
	~Department();
	void print(ostream&);
};
