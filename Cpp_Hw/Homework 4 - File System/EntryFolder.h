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
	int getSize();
	bool isFolder();
	//Entry* search(string, bool);
	EntryIt search(string, bool);
	string getPath();
	EntryFolder* lastFolder();
	EntryIt dump();

private:
	vector<Entry*> mEntry;
	EntryFolder *mLastFolder;
};

