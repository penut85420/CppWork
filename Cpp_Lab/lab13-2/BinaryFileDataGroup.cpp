#include "BinaryFileDataGroup.h"
using namespace std;

BinaryFileDataGroup::BinaryFileDataGroup(int numberOfNames, char *names[], 
	int sizeOfArray, int numberOfData, double dataArray[], const char *fileName) 
	: TextFileDataGroup(numberOfNames, names, sizeOfArray, numberOfData, dataArray, fileName) { }


BinaryFileDataGroup::~BinaryFileDataGroup(void) { }

void BinaryFileDataGroup::openStream(bool bOutput) {
	if (bOutput) mFile.open(mFileName, fstream::out | fstream::binary);
	else mFile.open(mFileName, fstream::in | fstream::binary);
}

void BinaryFileDataGroup::closeStream(bool) {
	mFile.close();
}

unsigned char BinaryFileDataGroup::readByte() {
	char x;
	mFile.get(x);
	return x;
}

void BinaryFileDataGroup::writeByte(unsigned char data) {
	mFile.put(data);
}
