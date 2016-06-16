#include <iostream>
#include "ScreenDataGroup.h"
#include "TextFileDataGroup.h"
#include "BinaryFileDataGroup.h"
using namespace std;

void main() {
    char *names[] = {"compressor", "o-ring"};
    double darray[] = {1.1, 2.2, 3.3};

    ScreenDataGroup scrobj(2, names, 5, 3, darray);
    TextFileDataGroup tfobj(2, names, 5, 3, darray, "DataGroup.txt");
    BinaryFileDataGroup bfobj(2, names, 5, 3, darray, "DataGroup.dat");
        
    scrobj.serialize();
    tfobj.serialize();
    bfobj.serialize();

	cin.get();
}