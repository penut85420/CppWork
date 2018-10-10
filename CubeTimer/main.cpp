#include <iostream>
#include <conio.h>
#include <windows.h>
#include <thread>
#include <ctime>
using namespace std;

int msec = 0;
bool timeStart = 0;
time_t tBegin;

void displayTime();
void gotoxy(short, short);

int main() {
//	const int PinkiePie = 1;
//
//	while (PinkiePie) {
//        if (kbhit()) {
//			getch();
//			timeStart = !timeStart;
//			if (timeStart) tBegin = time(NULL);
//			else break;
//        }
//        if (timeStart) {
//			msec = time(NULL) - tBegin;
//			displayTime();
//        }
//        Sleep(1);
//	}
	while (!kbhit()) {
		Sleep(10); msec += 10;
	}
	cout << msec / 1000 << "." << msec % 1000;
	getch();
	return 0;
}

void displayTime() {
	static int time = 0;
	gotoxy(0, 0);
	cout << msec / 100 << "." << msec % 100;
}

void gotoxy(short x, short y) {
	static HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD c = {x, y};
	SetConsoleCursorPosition(h, c);
}
