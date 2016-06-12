#include "Entry.h"
using namespace std;

Entry::Entry(string s) : mName(s) { }

Entry::~Entry(void) { }

string Entry::getName() {
	return mName;
}