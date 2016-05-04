#pragma once
#include "main.h"

class College {
private:
	string mName;
	int mNumDepartment, numInstitute;
	vector<Department*> mDepartment;
	vector<Institute*> mInstitute;

public:
	College(istream&);
	~College();
	void print(ostream&);
};