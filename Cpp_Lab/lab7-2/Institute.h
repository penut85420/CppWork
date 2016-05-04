#pragma once
#include "main.h"

class Teacher;
class Course;

class Institute {
private:
	string mName;
	int numTeacher, numCourse;
	vector<Teacher*> mTeacher;
	vector<Course*> mCourse;

public:
	Institute(istream&);
	~Institute(void);
	void print(ostream&);
};

