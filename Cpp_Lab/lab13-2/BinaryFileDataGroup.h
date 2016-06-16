#pragma once
#include "TextFileDataGroup.h"

class BinaryFileDataGroup : public TextFileDataGroup {
public:
	BinaryFileDataGroup(int, char*[], int, int, double*, const char*);
	~BinaryFileDataGroup(void);
protected:
	void openStream(bool);
	void closeStream(bool);
    void writeByte(unsigned char);
	unsigned char readByte();
};

