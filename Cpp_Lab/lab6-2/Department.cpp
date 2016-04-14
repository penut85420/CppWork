#include "main.h"

Department::Department(istream &in) {
	in >> mName;
}

Department::~Department() {

}

void Department::print(ostream &os) {
	os << "    ¬ì¨t¦WºÙ¡G" << mName << endl;
}