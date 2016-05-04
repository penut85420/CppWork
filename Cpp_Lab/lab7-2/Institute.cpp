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
	os << "    ¬ã¨s©Ò¡G" << mName << endl;
}