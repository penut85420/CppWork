#pragma once
#include <string>
#include <vector>
#include "Entry.h"
using namespace std;

class EntryFolder : public Entry {
public:
	EntryFolder(string, EntryFolder*);
	~EntryFolder(void);
	void addEntry(Entry*);
	void removeEntry(EntryIt);
	void removeEntry();
	int getSize();
	bool isFolder();
	EntryIt search(string, bool);
	string getPath();
	EntryFolder* lastFolder();
	EntryIt dump();
	void printList(int);

private:
	vector<Entry*> mEntry;
	EntryFolder *mLastFolder;
};

