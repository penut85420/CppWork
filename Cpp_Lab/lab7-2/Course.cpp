#include "main.h"


Course::Course(istream &in) {
	in >> mName >> mID >> mYear >> mSemester >> mTeacher;
}


Course::~Course(void) { }

void Course::print(ostream &os) {
	os << "      課程名稱：" << mName << endl
		<< "      課程代號：" << mID << endl
		<< "      學年度：" << mYear << endl
		<< "      學期：" << mSemester << endl
		<< "      開課教師：" << mTeacher << endl;
}