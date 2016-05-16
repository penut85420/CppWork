#include "main.h"

Department::Department(istream &in) {
	in >> mName >> numTeacher;
	for (int i = 0; i < numTeacher; i++)
		mTeacher.push_back(new Teacher(in));

	in >> numCourse;
	for (int i = 0; i < numCourse; i++)
		mCourse.push_back(new Course(in));
}

Department::~Department() {
	for (int i = 0; i < numTeacher; i++)
		delete mTeacher[i];
}

void Department::print(ostream &os) {
	os << "¬ì¨t¦WºÙ¡G" << mName << endl;
	/*for (int i = 0; i < numTeacher; i++)
		mTeacher[i]->print(os);
	for (int i = 0; i < numCourse; i++)
		mCourse[i]->print(os);*/
}

void Department::viewTeacher(string name, ostream &os) {
	for (auto it = mTeacher.begin();
			it != mTeacher.end(); it++) {
		if ((*it)->getName() == name) {
			(*it)->print(os);
			print(os);
		}
	}
}

void Department::viewCourse(string name, ostream &os) {
	for (auto it = mCourse.begin();
			it != mCourse.end(); it++) {
		if ((*it)->getName() == name) {
			(*it)->print(os);
			print(os);
		}
	}
}