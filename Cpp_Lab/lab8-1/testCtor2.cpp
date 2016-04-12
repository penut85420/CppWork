// cl -GX testCtor2.cpp

#include <fstream>
#include <iostream>
using namespace std;

void printMessage(ofstream& os)
{
    //cout << "entering function printMessage()..." << endl;
    os << "entering function printMessage()..." << endl;
    //cout << "leaving function printMessage()" << endl;
    os << "leaving function printMessage()" << endl;
}

int main()
{
    ofstream outfile("out.txt");
    cout << "entering function main()..." << endl;
    outfile << "entering function main()..." << endl;
    printMessage(outfile);
    cout << "leaving function main()" << endl;
    outfile << "leaving function main()" << endl;
	system("PAUSE");
	return 0;
}
