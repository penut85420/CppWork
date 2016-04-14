#ifndef UNIVERSITY_H
#define UNIVERSITY_H
#include "main.h"

class University {
private:
	string mName;
	int numCollege;
	College *mCollege[5];

public:
	University(istream&);
	University();
	void load(istream&);
	~University();
	void print(ostream&);
	void unitTest();
};

#endif