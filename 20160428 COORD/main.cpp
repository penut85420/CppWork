#include <iostream>
#include <windows.h>
using namespace std;

int main() {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD c;

	for (int i = 0; i < 10; i++) {
		c.X = i; c.Y = 0;
		SetConsoleCursorPosition(h, c);
		cout << i;
		c.Y = i; c.X = 0;
		SetConsoleCursorPosition(h, c);
		cout << i;
		c.X = i, c.Y = i;
		SetConsoleCursorPosition(h, c);
		cout << i;
	}

	return 0;
}
