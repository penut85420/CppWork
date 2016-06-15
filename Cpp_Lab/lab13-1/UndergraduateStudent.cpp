#include "UndergraduateStudent.h"
using namespace std;

UndergraduateStudent::UndergraduateStudent(const char *name, const char *ID, 
		const char *phone, const char *department,
		const char *academicAdvisor) : Student(name, ID, phone, department) {
	mAcademicAdvisor = new char[strlen(academicAdvisor) + 1];
	strcpy(mAcademicAdvisor, academicAdvisor);
}


UndergraduateStudent::~UndergraduateStudent(void) {
	delete mAcademicAdvisor;
}

void UndergraduateStudent::display(ostream &os) const {
	Student::display(os);
	os << "AcademicAdvisor: " << mAcademicAdvisor << endl;
}