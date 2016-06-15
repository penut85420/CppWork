#pragma once
#include "Entry.h"
#include "EntryFile.h"
#include "EntryFolder.h"

class Command {
public:
	Command(void);
	~Command(void);
	void query();

	void exitFolder();
	void cdFolder();
	void addFile();
	void printFile();
	void addFolder();
	void deleteFile();
	void deleteFolder();
	void searchEntry();
	void printList(bool);
	void searchFile();
	void getSize();
	void save();

	bool isEmpty(EntryIt);
	string getName(bool);
	string reqName(string);

private:
	EntryFolder *mRoot, *mNowFolder;
};

