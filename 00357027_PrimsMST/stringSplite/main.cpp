#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, char *argv[]) {
	for (int i = 1; i < argc; i++) {
		string s = argv[i];
		s += ".txt";
		ifstream fin(argv[i]);
		ofstream fout(s.c_str());
		while (fin >> s) 
			if (s[0] != 'K')
				fout << s << endl;
	}

	return 0;
}