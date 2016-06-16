#include "TextFileDataGroup.h"
#include <cstring>
#include <iomanip>
using namespace std;

TextFileDataGroup::TextFileDataGroup(int numberOfNames, char *names[], 
	int sizeOfArray, int numberOfData, double dataArray[], const char *fileName) 
	: DataGroup(numberOfNames, names, sizeOfArray, numberOfData, dataArray) {
	mFileName = new char[strlen(fileName) + 1];
	strcpy(mFileName, fileName);
}


TextFileDataGroup::~TextFileDataGroup(void) { }

void TextFileDataGroup::openStream(bool bOutput) {
	if (bOutput) mFile.open(mFileName, fstream::out);
	else mFile.open(mFileName, fstream::in);
}

void TextFileDataGroup::closeStream(bool) {
	mFile.close();
}

unsigned char TextFileDataGroup::readByte() {
	int x;
	mFile >> hex >> x;
	return x;
}
    
void TextFileDataGroup::writeByte(unsigned char data) {
    static int nBytes = 0;
    
    int lownibble = data & 0x0F;
    int highnibble = data >> 4;
      
    mFile << hex << highnibble;
    mFile << hex << lownibble << ' ';
    
    nBytes = ++nBytes % 16;
    if (nBytes == 0)
        mFile << endl;
}
