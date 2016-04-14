#include "main.h"

College::College(istream &in) {
	in >> mName >> mNumDepartment;
	for (int i = 0; i < mNumDepartment; i++)
		mDepartment[i] = new Department(in);
}

College::~College() {
	for (int i = 0; i < mNumDepartment; i++)
		delete mDepartment[i];
}

void College::print(ostream &os) {
	os << "  ¾Ç°|¦WºÙ¡G" << mName << endl;
	for (int i = 0; i < mNumDepartment; i++)
		mDepartment[i]->print(os);
}