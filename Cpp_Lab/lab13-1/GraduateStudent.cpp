#include "GraduateStudent.h"
using namespace std;

GraduateStudent::GraduateStudent(const char *name, const char *ID, 
	const char *phone, const char *department, const char *advisor)
	: Student(name, ID, phone, department) {
	mAdvisor = new char[strlen(advisor) + 1];
	strcpy(mAdvisor, advisor);
}


GraduateStudent::~GraduateStudent(void) {
	delete mAdvisor;
}

void GraduateStudent::display(ostream &os) const {
	Student::display(os);
	os << "Advisor: " << mAdvisor << endl;
}