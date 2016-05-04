#include "main.h"

void clrscr() {
	system("cls");
}

void gotoxy(int x, int y) {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD c = {x, y};
	SetConsoleCursorPosition(h, c);
}

void delay(int militime) {
	Sleep(militime);
}