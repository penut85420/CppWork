
#ifndef IOCTRL_NTNU_
#define IOCTRL_NTNU_

// Sleep(), setcolor(), gotoxy()
#include <windows.h>

// getch(), getcha(), kbhit()
#include <conio.h>


enum ForegroundColor {fgBLACK = 0, fgNORMAL = 7, fgGRAY, fgBLUE, fgGREEN, fgCYAN, fgRED, fgPINK, fgYELLOW, fgWHITE};
enum BackgroundColor {bgBLACK = 0, bgBLUE = 16, bgGREEN = 32, bgCYAN = 48, bgRED = 64, bgPINK = 80, bgYELLOW = 96, bgWHITE = 112};
enum ArrowKey { keyENTER = 13, keyESC = 27, keyUP = 72, keyDOWN = 80, keyLEFT = 75, keyRIGHT = 77  };


void setcolor(int fg = fgNORMAL, int bg = bgBLACK);
void gotoxy(int xpos, int ypos);
int getcha();


#endif // IOCTRL__
