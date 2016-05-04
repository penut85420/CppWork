#pragma once
#include "main.h"

class Teacher {
private:
	string mName;

public:
	Teacher(istream&);
	~Teacher(void);
	void print(ostream &os);
};