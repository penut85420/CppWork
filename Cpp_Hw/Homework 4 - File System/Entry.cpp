#include "Entry.h"
#include <iostream>
using namespace std;

Entry::Entry(string s) : mName(s) { }

Entry::Entry() { }

Entry::~Entry(void) { }

bool Entry::cmpName(string name) {
	return name == mName;
}

string Entry::getName() {
	return mName;
}