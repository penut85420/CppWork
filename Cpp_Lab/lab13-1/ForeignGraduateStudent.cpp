#include "ForeignGraduateStudent.h"
using namespace std;

ForeignGraduateStudent::ForeignGraduateStudent(const char *name, const char *ID, 
	const char *phone, const char *department, const char *advisor, const char *nationality)
	: GraduateStudent(name, ID, phone, department, advisor) {
	mNationality = new char[strlen(nationality) + 1];
	strcpy(mNationality, nationality);
}


ForeignGraduateStudent::~ForeignGraduateStudent(void) {
	delete mNationality;
}

void ForeignGraduateStudent::display(ostream &os) const {
	GraduateStudent::display(os);
	os << "Nationality: " << mNationality << endl;
}