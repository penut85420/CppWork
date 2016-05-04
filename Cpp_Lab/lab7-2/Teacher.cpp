#include "main.h"


Teacher::Teacher(istream &in) {
	in >> mName;
}

Teacher::~Teacher(void) { }

void Teacher::print(ostream &os) {
	os << "      ¦Ñ®v¦WºÙ¡G" << mName << endl;
}