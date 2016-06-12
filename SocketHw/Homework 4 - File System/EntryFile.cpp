#include "EntryFile.h"
#include <iostream>
using namespace std;

EntryFile::EntryFile(string name, string content)
	: Entry(name), mContent(content) { }

EntryFile::~EntryFile(void) { }

int EntryFile::getSize() {
	return mContent.size();
}

bool EntryFile::isFolder() {
	return false;
}

void EntryFile::print() {
	cout << "ÀÉ®×¤º®e¡G" << mContent << endl;
}

void EntryFile::removeEntry() { };