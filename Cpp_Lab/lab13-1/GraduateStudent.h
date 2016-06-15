#pragma once
#include "Student.h"
#include <iostream>

class GraduateStudent : public Student {
public:
    GraduateStudent(const char*, const char*, const char*,
			const char*, const char*);
    ~GraduateStudent();
    void display(std::ostream &os) const;

private:
    char *mAdvisor;
};