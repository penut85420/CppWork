#pragma once
#include <iostream>
#include <cstring>

class Student
{
private:
	char *mName, *mID, *mPhone, *mDepartment;

public:
	Student();
	Student(const char*, const char*,
			const char*, const char*);
	virtual ~Student();
	virtual void display(std::ostream&) const;
	bool matchID(const char*);
	bool ofTheSameDepartment(Student&);
};