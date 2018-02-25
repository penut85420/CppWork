#include <windows.h>
#include <conio.h>

void setcolor(int fg, int bg)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole,fg+bg);
}
// ---------------------------------------------------------
void gotoxy(int xpos, int ypos)
{
    COORD scrn;
    scrn.X = xpos;
    scrn.Y = ypos;

    HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hOuput,scrn);
}
// ---------------------------------------------------------
int getcha()
{
    char c = getch();
    if (c<0) c = getch();
    return c;
}
// ---------------------------------------------------------
