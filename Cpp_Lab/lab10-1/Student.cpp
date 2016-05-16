#include "Student.h"
#include <cstring>

Student::Student(const char *name, const char *id, 
	const char *phone, const char *department) {
	
	mName = new char[strlen(name) + 1];
	mID = new char[strlen(id) + 1];
	mPhone = new char[strlen(phone) + 1];
	mDepartment = new char[strlen(department) + 1];

	strcpy(mName, name);
	strcpy(mID, id);
	strcpy(mPhone, phone);
	strcpy(mDepartment, department);
}

Student::~Student(void) { 
	delete [] mName;
	delete [] mID;
	delete [] mPhone;
	delete [] mDepartment;
}

void Student::display(std::ostream &os) const {
	os << "Name: " << mName << std::endl
		<< "ID: " << mID << std::endl
		<< "Phone: " << mPhone << std::endl
		<< "Department: " << mDepartment << std::endl;
}

bool Student::matchID(const char *s) {
	if (!strcmp(mID, s)) return true;
	return false;
}