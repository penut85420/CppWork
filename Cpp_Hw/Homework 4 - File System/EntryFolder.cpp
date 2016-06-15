#include "EntryFolder.h"
#include "EntryFile.h"
#include <iostream>
using namespace std;

EntryFolder::EntryFolder(string name, EntryFolder *last) 
	: Entry(name), mLastFolder(last) { }

EntryFolder::~EntryFolder(void) { }

int EntryFolder::getSize() {
	int sum = 0;
	for (auto i = mEntry.begin();
			i != mEntry.end(); i++)
		sum += (*i)->getSize();
	return sum;
};

bool EntryFolder::isFolder() {
	return true;
}

void EntryFolder::addEntry(Entry *newEntry) {
	mEntry.push_back(newEntry);
}

EntryIt EntryFolder::search(string name, bool isFolder) {
	for (auto i = mEntry.begin();
			i != mEntry.end(); i++) {
		if ((*i)->isFolder() == isFolder)
			if ((*i)->cmpName(name))
				return i;
	}
	return mEntry.end();
}

string EntryFolder::getPath() {
	if (!mLastFolder) return mName;
	return mLastFolder->getPath() + "/" + mName;
}

EntryFolder* EntryFolder::lastFolder() {
	if (mLastFolder) return mLastFolder;
	return this;
}

void EntryFolder::removeEntry(EntryIt target) {
	delete *target;
	mEntry.erase(target);
}

EntryIt EntryFolder::dump() {
	return mEntry.end();
}

void EntryFolder::removeEntry() {
	for (auto i = mEntry.begin();
			i != mEntry.end(); i++) {
		(*i)->removeEntry();
		delete *i;
	}
}

void EntryFolder::printList(int prefix, bool printFolder) {
	for (int i = 0; i < prefix; i++)
		cout << " ";
	cout << mName << endl;

	if (printFolder || (!printFolder && !prefix))
	for (auto i = mEntry.begin();
			i != mEntry.end(); i++)
		(*i)->printList(prefix + 2, printFolder);
}

EntryIt EntryFolder::searchFile(string content) {
	for (auto i = mEntry.begin();
			i != mEntry.end(); i++) {
		if (!(*i)->isFolder()) {
			int result = ((EntryFile*)*i)->getContent().find(content, 0);
			if (result != -1) return i;
		}
	}
	return dump();
}

void EntryFolder::save(ofstream &fout) {
	fout << 1 << " " << mEntry.size() << " " << mName << endl;
	for (auto i = mEntry.begin();
			i != mEntry.end(); i++)
		(*i)->save(fout);
}

EntryFolder::EntryFolder(ifstream &fin, EntryFolder* lastFolder) {
	mLastFolder = lastFolder;
	int size, id;
	EntryFolder *newFolder;
	EntryFile *newFile;
	fin >> size >> mName;
	for (int i = 0; i < size; i++) {
		fin >> id;
		if (id) {
			newFolder = new EntryFolder(fin, this);
			mEntry.push_back(newFolder);
		} else {
			newFile = new EntryFile(fin);
			mEntry.push_back(newFile);
		}
	}
}