// ConsoleApplication1.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include <iostream>
#include <Windows.h>
#include <conio.h>
using namespace std;

int main()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD c = { 3, 5 };
	SetConsoleCursorPosition(h, c);
	cout << "hello, vc2015" << endl;
	_getch();
    return 0;
}

