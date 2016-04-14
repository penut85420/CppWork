#ifndef DEPARTMENT_H
#define DEPARTMENT_H
#include "main.h"

class Department {
private:
	string mName;
public:
	Department(istream&);
	~Department();
	void print(ostream&);
};

#endif