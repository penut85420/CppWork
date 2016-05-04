#pragma once
#include "main.h"

class Course {
private:
	string mName, mTeacher;
	int mID, mSemester, mYear;
public:
	Course(istream&);
	~Course(void);
	void print(ostream &os);
};