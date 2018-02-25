#include <stdio.h>
#include "ioctrl.h"

int main() {
    char sym[32] = "¢z¢{¢}¢|";
    int pipe[] = {0, 1, 2, 3};

    for (int i = 0; i < 4; i++)
        printf("%c%c", sym[pipe[i] * 2], sym[pipe[i] * 2 + 1]);

    int px = 0;
//  penut85420@gmail.com
    char ch = getcha();
    while (ch != keyESC) {
        gotoxy(px, 1);
        if (ch == keyENTER)
            pipe[px] = (pipe[px] + 1) % 4;
        else if (ch == keyRIGHT)
            px++;
        else if (ch == keyLEFT)
            px--;

        gotoxy(0, 0);
        for (int i = 0; i < 4; i++)
            printf("%c%c", sym[pipe[i] * 2], sym[pipe[i] * 2 + 1]);
        ch = getcha();
    }

    return 0;
}
