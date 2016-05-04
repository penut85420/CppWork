#include "main.h"

College::College(istream &in) {
	in >> mName >> mNumDepartment;
	for (int i = 0; i < mNumDepartment; i++)
		mDepartment.push_back(new Department(in));

	in >> numInstitute;
	for (int i = 0; i < numInstitute; i++)
		mInstitute.push_back(new Institute(in));
}

College::~College() {
	for (int i = 0; i < mNumDepartment; i++)
		delete mDepartment[i];
}

void College::print(ostream &os) {
	os << "  ¾Ç°|¦WºÙ¡G" << mName << endl;
	for (int i = 0; i < mNumDepartment; i++)
		mDepartment[i]->print(os);

	for (int i = 0; i < numInstitute; i++)
		mInstitute[i]->print(os);
}