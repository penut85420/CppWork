#include <stdio.h>
#include <string.h>
#include <io.h>
#include "ioctrl.h"

void drawTitle(int, int, char[]);

int main() {
    FILE *f = fopen("title.txt", "r");

    char title[64];

    fgets(title, 64, f);

    drawTitle(10, 5, title);

    return 0;
}

void drawTitle(int x, int y, char title[]) {
    int len = strlen(title);

    gotoxy(x, y);
    for (int i = 0; i < len + 10; i++)
        putchar('=');

    gotoxy(x + 5, y + 1);
    printf("%s", title);

    gotoxy(x, y + 2);
    for (int i = 0; i < len + 10; i++)
        putchar('=');

}
