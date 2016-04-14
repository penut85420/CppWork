#ifndef COLLEGE_H
#define COLLEGE_H
#include "main.h"

class College {
private:
	string mName;
	int mNumDepartment;
	Department *mDepartment[5];
public:
	College(istream&);
	~College();
	void print(ostream&);
};

#endif