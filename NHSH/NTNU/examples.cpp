
#include "ioctrl.h"
#include <stdio.h>

void ColorExample()
{
    setcolor(fgRED, bgWHITE);
    printf("Red font with White background.\n");

    setcolor(fgCYAN, bgYELLOW);
    printf("Cyan font with Yello background.\n");

    setcolor(fgGREEN);
    printf("Green font with Black background.\n");

    setcolor();
    printf("Default.\n");
}
// ---------------------------------------------------------------
void PositionExample()
{
    for (int i=0; i<5; i+=1)
    {
        gotoxy(30+i*10, i*2);
        printf("V(%d, %d)", i, i*10);
    }
}
// ---------------------------------------------------------------
void SleepExample()
{
    for (int i=20; i>0; i-=1)
    {
        putchar('>');
        Sleep(i*50);
    }
}
// ---------------------------------------------------------------
void KeyboardExample()
{
    printf("Only 1, a, and arrow-up get responses. Press Esc to stop.\n");
    char ch;
    do
    {
        ch = getcha();
        switch (ch)
        {
        case '1':
            printf("1");
            break;
        case 'a':
            printf("a");
            break;
        case keyUP:
            printf("up");
            break;
        }
    }
    while (ch != keyESC);
}
// ---------------------------------------------------------------
void AnimationExample()
{
    for (int i=10; i<70; i+=1)
    {
        gotoxy(i, 10); setcolor(); putchar(' ');
        gotoxy(i+1, 10); setcolor(fgYELLOW, bgRED); putchar('O');
        Sleep(50);
    }
    setcolor();
}
// ---------------------------------------------------------------
void HitExample()
{
    printf("Freeze O by pressing [p]!!\n");

    int x=10, offset=1;
    while (true)
    {
        gotoxy(x, 10);
        setcolor();
        putchar(' ');
        x+=offset;
        gotoxy(x, 10);
        setcolor(fgYELLOW, bgRED);
        putchar('O');
        Sleep(50);

        if (x<=10) offset = 1;
        else if (x>=70) offset = -1;

        if (kbhit())
        {
            if (getcha() == 'p')
            {
                gotoxy(30, 12); setcolor(fgCYAN, bgPINK);
                printf("Press ESC to stop or other keys to resume");
                while (!kbhit());
                gotoxy(30, 12); setcolor();
                printf("                                         ");
                char c = getcha();
                if (c == keyESC) break;
            }
        }
    }
    setcolor();
}
// ---------------------------------------------------------------
void MoveExample()
{
    constexpr int MazeSize = 6;
    int maze[MazeSize][MazeSize]=
    {
        {1,1,1,1,1,1},
        {1,0,0,1,0,1},
        {1,1,0,0,0,1},
        {1,0,1,0,0,1},
        {1,0,0,0,0,1},
        {1,1,1,1,1,1}
    };

    constexpr int LEFT = 30, TOP = 5;
    for (int i=0; i<MazeSize; i+=1)
    {
        gotoxy(LEFT, TOP+i);
        for (int j=0; j<MazeSize; j+=1)
        {
            if (maze[i][j]==1) putchar('.');
            else putchar(' ');
        }
    }

    int x=2, y=2;
    bool stop = false;
    while (!stop)
    {
        gotoxy(LEFT+y, TOP+x);
        putchar('@');

        char c = getcha();
        gotoxy(LEFT+y, TOP+x);
        putchar(' ');

        switch (c)
        {
        case keyUP:
            if (maze[x-1][y]==0) x-=1;
            break;
        case keyDOWN:
            if (maze[x+1][y]==0) x+=1;
            break;
        case keyLEFT:
            if (maze[x][y-1]==0) y-=1;
            break;
        case keyRIGHT:
            if (maze[x][y+1]==0) y+=1;
            break;
        case keyESC:
            stop = true;
            break;
        }
    }
}
