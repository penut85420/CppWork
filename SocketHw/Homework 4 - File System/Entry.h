#pragma once
#include <string>
#include <vector>

class Entry {
public:
	Entry(std::string);
	~Entry(void);
	virtual int getSize() = 0;
	virtual bool isFolder() = 0;
	virtual void removeEntry() = 0;
	std::string getName();

private:
	std::string mName;
};

typedef std::vector<Entry*>::iterator EntryIt;