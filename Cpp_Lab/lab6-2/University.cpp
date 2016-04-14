#include "main.h"

University::University(istream &in) {
	load(in);
}

University::University() {

}

University::~University() {
	for (int i = 0; i < numCollege; i++)
		delete mCollege[i];
}

void University::print(ostream &os) {
	os << "¾Ç®Õ¦WºÙ¡G" << mName << endl;
	for (int i = 0; i < numCollege; i++)
		mCollege[i]->print(os);
	system("PAUSE");
}

void University::unitTest() {
	ifstream fin("ntou1.txt");
	if (!fin) return;
	load(fin);
	print(cout);
}

void University::load(istream &in) {
	in >> mName >> numCollege;
	for (int i = 0; i < numCollege; i++)
		mCollege[i] = new College(in);
}