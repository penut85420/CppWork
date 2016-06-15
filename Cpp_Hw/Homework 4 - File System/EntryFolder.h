#pragma once
#include <string>
#include <vector>
#include <fstream>
#include "Entry.h"
using namespace std;

class EntryFolder : public Entry {
public:
	EntryFolder(string, EntryFolder*);
	EntryFolder(ifstream&, EntryFolder*);
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
	void printList(int, bool);
	EntryIt searchFile(string);
	void save(ofstream&);

private:
	vector<Entry*> mEntry;
	EntryFolder *mLastFolder;
};

