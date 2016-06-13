#pragma once
#include <string>
#include "Entry.h"

class EntryFile : public Entry {
public:
	EntryFile(std::string, std::string);
	~EntryFile(void);
	int getSize();
	bool isFolder();
	void print();
	void removeEntry();
	void printList(int, bool);
	std::string getContent();

private:
	std::string mContent;
};

