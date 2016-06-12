#include "EntryFolder.h"
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
			if ((*i)->getName() == name)
				return i;
	}
	return mEntry.end();
}

string EntryFolder::getPath() {
	if (!mLastFolder) return getName();
	return mLastFolder->getPath() + "/" + getName();
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

void removeEntry(EntryIt it) {

}