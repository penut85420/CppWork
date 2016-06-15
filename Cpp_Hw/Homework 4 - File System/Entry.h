#pragma once
#include <string>
#include <vector>
#include <fstream>

class Entry;
typedef std::vector<Entry*>::iterator EntryIt;

class Entry {
public:
	Entry();
	Entry(std::string);
	Entry(std::ifstream);
	~Entry(void);
	virtual int getSize() = 0;
	virtual bool isFolder() = 0;
	virtual void removeEntry() = 0;
	virtual void printList(int, bool) = 0;
	virtual void save(std::ofstream&) = 0;
	bool cmpName(std::string);
	std::string getName();

protected:
	std::string mName;
};

typedef std::vector<Entry*>::iterator EntryIt;