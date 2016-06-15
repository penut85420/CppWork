#pragma once
#include <string>
#include <fstream>
#include "Entry.h"

class EntryFile : public Entry {
public:
	EntryFile(std::string, std::string);
	EntryFile(std::ifstream&);
	~EntryFile(void);
	int getSize();
	bool isFolder();
	void print();
	void removeEntry();
	void printList(int, bool);
	std::string getContent();
	void save(std::ofstream&);

private:
	std::string mContent;
};

