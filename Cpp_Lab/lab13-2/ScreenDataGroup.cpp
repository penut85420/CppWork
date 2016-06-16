#include "ScreenDataGroup.h"
#include <iostream>
#include <iomanip>
using namespace std;

void ScreenDataGroup::openStream(bool) { }
    
void ScreenDataGroup::closeStream(bool) { }

unsigned char ScreenDataGroup::readByte() {
	int x;
	cin >> hex >> x;
	return x;
}
    
void ScreenDataGroup::writeByte(unsigned char data) {
    static int nBytes = 0;
    
    int lownibble = data & 0x0F;
    int highnibble = data >> 4;
      
    cout << setw(1) << hex << highnibble;
    cout << setw(1) << hex << lownibble << ' ';
    
    nBytes = ++nBytes % 16;
    if (nBytes == 0)
        cout << endl;
}
