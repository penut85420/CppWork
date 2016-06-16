#pragma once
#include "DataGroup.h"
#include <fstream>

class TextFileDataGroup : public DataGroup {
public:
	TextFileDataGroup(int, char*[], int, int, double*, const char*);
	~TextFileDataGroup(void);
protected:
	char *mFileName;
	std::fstream mFile;
    void openStream(bool);
    void closeStream(bool);
    void writeByte(unsigned char);
	unsigned char readByte();
};

