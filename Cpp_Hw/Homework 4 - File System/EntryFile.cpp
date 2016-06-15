#include "EntryFile.h"
#include <iostream>
using namespace std;

EntryFile::EntryFile(string name, string content)
	: Entry(name), mContent(content) { }

EntryFile::EntryFile(ifstream &fin) {
	fin >> mName >> mContent;
}

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

void EntryFile::removeEntry() { }

void EntryFile::printList(int prefix, bool) {
	for (int i = 0; i < prefix; i++)
		cout << " ";
	cout << mName << endl;
}

string EntryFile::getContent() {
	return mContent;
}

void EntryFile::save(ofstream &fout) {
	fout << 0 << " " << mName << " " << mContent << endl;
}