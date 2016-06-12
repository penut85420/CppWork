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
	
	bool isEmpty(EntryIt);
	string getName(bool);

private:
	EntryFolder *mRoot, *mNowFolder;
};

