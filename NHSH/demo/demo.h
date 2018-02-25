#ifndef DEMO_H_INCLUDED
#define DEMO_H_INCLUDED

#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include "ioctrl.h"

void hideCursor();
void setTitle(char*);
int displayMainMenu();
void clrscr();
void displayMsg(int x, int y, char*);
void playGame();
void printMaze(int[64][64], int, int);
int getRnd(int);

#endif // DEMO_H_INCLUDED
