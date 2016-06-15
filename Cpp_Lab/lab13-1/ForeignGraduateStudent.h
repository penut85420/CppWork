#pragma once
#include "GraduateStudent.h"
#include <iostream>

class ForeignGraduateStudent : public GraduateStudent {
public:
    ForeignGraduateStudent(const char*, const char*, const char*,
			const char*, const char*, const char*);
    ~ForeignGraduateStudent();
    void display(std::ostream &os) const;

private:
    char *mNationality ;
};