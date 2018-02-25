#include "demo.h"
#include "ioctrl.h"

void hideCursor() {
    CONSOLE_CURSOR_INFO cci;
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    cci.dwSize = 1;
    cci.bVisible = 0;
    SetConsoleCursorInfo(h, &cci);
}

void setTitle(char title[]) {
    char cmd[64];
    sprintf(cmd, "title %s", title);
    system(cmd);
}

int displayMainMenu() {
    const int numItem = 4;
    char menuItem[numItem][32] = {"Start", "Load", "Setting", "Exit"};
    int itemEnable[numItem] = {1, 0, 1, 1};

    gotoxy(0, 0);
    for (int i = 0; i < numItem; i++) {
        if (itemEnable[i])
            setcolor(fgWHITE, bgBLACK);
        else setcolor(fgGRAY, bgBLACK);
        printf("    %s\n", menuItem[i]);
    }

    gotoxy(0, 0);
    printf(" > ");

    int nx, ny;
    nx = ny = 0;

    while (true) {
        char ch = getch();

        gotoxy(nx, ny);
        printf("   ");

        if (ch == keyDOWN) {
            ny = (ny + 1) % numItem;
            while (!itemEnable[ny])
                ny = (ny + 1) % numItem;
        } else if (ch == keyUP) {
            ny = (ny - 1 + numItem) % numItem;
            while (!itemEnable[ny])
                ny = (ny - 1 + numItem) % numItem;
        } else if (ch == keyENTER) return ny;

        gotoxy(nx, ny);
        printf(" > ");
    }
}

void clrscr() {
    gotoxy(0, 0);
    for (int i = 0; i < 64; i++) {
        for (int j = 0; j < 64; j++)
            putchar(' ');
        putchar('\n');
    }
    gotoxy(0, 0);
}

void displayMsg(int x, int y, char msg[]) {
    int len = strlen(msg);
    gotoxy(x, y);
    for (int i = 0; i < len; i++) {
        putchar(msg[i]);
        Sleep(50);
    }
}

void playGame() {
    int numObt = 5;
    int h = getRnd(5) + 3, w = getRnd(5) + 3;
    int maze[64][64];
//    UP 72 0 0
//    DW 80 8 4
//    LE 75 3 1
//    RI 77 5 2
    int step[5][2] = {
        {-1, 0}, // UP
        {0, -1}, // LEFT
        {0, 1},  // RIGHT
        {0, 0},  // NULL
        {1, 0}   // DOWN
    };

    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            maze[i][j] = 0;

    while (numObt--)
        maze[getRnd(h)][getRnd(w)] = 1;

    int playerX = getRnd(w), playerY = getRnd(h);
    maze[playerY][playerX] = 2;

    int endX = getRnd(w), endY = getRnd(h);
    while (maze[endY][endX] != 0)
        endX = getRnd(w), endY = getRnd(h);

    maze[endY][endX] = 3;

    printMaze(maze, h, w);

    char ch = getcha();
    while (ch != keyESC) {
        ch = (ch - 72) / 2;
        // If ch is a arrow key
//        gotoxy(20, 0);
//        printf("%d", ch);
        if (ch >= 0 && ch <= 5) {
            int tX, tY;
            tY = (playerY + step[ch][0] + h) % h;
            tX = (playerX + step[ch][1] + w) % w;
            if (maze[tY][tX] != 1) {
                maze[playerY][playerX] = 0;
                playerX = tX;
                playerY = tY;
                maze[playerY][playerX] = 2;
            }
        }

        printMaze(maze, h, w);
        if (playerX == endX && playerY == endY) {
            gotoxy(0, h + 1);
            printf("You find it!");
            Sleep(1000);
            return ;
        }

        ch = getcha();
    }
}

void printMaze(int maze[64][64], int h, int w) {
    char symbol[] = " X$#";

    gotoxy(0, 0);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++)
            putchar(symbol[maze[i][j]]);
        putchar('\n');
    }
}

int getRnd(int atMax) {
    return rand() % atMax;
}
