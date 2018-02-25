#include <stdio.h>
#include "ioctrl.h"
#include "demo.h"

int main() {
    hideCursor();
    char title[] = "Simple Game Demo";
    setTitle(title);

    int opt = displayMainMenu();
    while (opt != 3) {
        clrscr();
        if (opt == 0) {
            char msg[] = "Let's play a game\nEat the # to win the game";
            displayMsg(0, 0, msg);
            Sleep(1000);
            clrscr();
            playGame();
        } else if (opt == 1) {
            printf("This is load");
        } else if (opt == 2) {
            printf("This is setting");
        }
        clrscr();
        opt = displayMainMenu();
    }

    return 0;
}
