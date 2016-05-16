#pragma once
#include <iostream>

class Student
{
private:
	char *mName, *mID, *mPhone, *mDepartment;

public:
	Student(const char*, const char*,
			const char*, const char*);
	~Student();
	void display(std::ostream&) const;
	bool matchID(const char*);
};