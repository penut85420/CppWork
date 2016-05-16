#include "main.h"


Institute::Institute(istream &in) {
	in >> mName >> numTeacher;
	for (int i = 0; i < numTeacher; i++)
		mTeacher.push_back(new Teacher(in));

	in >> numCourse;
	for (int i = 0; i < numCourse; i++)
		mCourse.push_back(new Course(in));
}


Institute::~Institute(void) { }

void Institute::print(ostream &os) {
	os << "研究所：" << mName << endl;
}

void Institute::viewTeacher(string name, ostream &os) {
	for (auto it = mTeacher.begin();
			it != mTeacher.end(); it++) {
		if ((*it)->getName() == name) {
			os << "教師名稱：" << name << endl;
			os << "學系名稱：" << mName << endl;
		}
	}
}

void Institute::viewCourse(string name, ostream &os) {
	for (auto it = mCourse.begin();
			it != mCourse.end(); it++) {
		if ((*it)->getName() == name) {
			(*it)->print(os);
			print(os);
		}
	}
}