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
	os << "¾Ç°|¦WºÙ¡G" << mName << endl;
	/*for (int i = 0; i < mNumDepartment; i++)
		mDepartment[i]->print(os);

	for (int i = 0; i < numInstitute; i++)
		mInstitute[i]->print(os);*/
}

void College::viewTeacher(string name, ostream &os) {
	for (auto it = mDepartment.begin();
			it != mDepartment.end(); it++)
		(*it)->viewTeacher(name, os);
	for (auto it = mInstitute.begin();
			it != mInstitute.end(); it++)
		(*it)->viewTeacher(name, os);
}

void College::viewCourse(string name, ostream &os) {
	for (auto it = mDepartment.begin();
			it != mDepartment.end(); it++)
		(*it)->viewCourse(name, os);
	for (auto it = mInstitute.begin();
			it != mInstitute.end(); it++)
		(*it)->viewCourse(name, os);
}