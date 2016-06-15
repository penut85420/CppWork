#pragma once
#include "Student.h"
#include <iostream>

class UndergraduateStudent : public Student {
public:
    UndergraduateStudent(const char *name, const char *ID, 
		const char *phone, const char *department,
		const char *academicAdvisor);
    ~UndergraduateStudent();
    void display(std::ostream &os) const;

private:
    char *mAcademicAdvisor;
	
};

