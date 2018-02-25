#include <stdio.h>
#include <stdlib.h>

#include "ioctrl.h"
#include "examples.h"

int menu()
{
    system("cls");
    const char *ex_names[] = {"Color Example",
                              "Position Example",
                              "Sleep Example",
                              "Animation Example",
                              "Keyboard Example",
                              "Hit Example",
                              "Move Example",
                              "Exit"
                             };

    int NumExamples = sizeof(ex_names)/sizeof(ex_names[0]);

    for (int i=0; i<NumExamples; i+=1)
    {
        printf("(%d) %s\n", i+1, ex_names[i]);
    }

    int choice = 0;
    scanf("%d", &choice);
    return choice<1 ? 1 : (choice>NumExamples?NumExamples:choice);
}
// ---------------------------------------------------------------------------
int main()
{
    int choice = 8;
    do
    {
        choice = menu();
        switch (choice)
        {
        case 1:
            ColorExample();
            break;
        case 2:
            PositionExample();
            break;
        case 3:
            SleepExample();
            break;
        case 4:
            AnimationExample();
            break;
        case 5:
            KeyboardExample();
            break;
        case 6:
            HitExample();
            break;
        case 7:
            MoveExample();
            break;
        }
        system("pause");
    }
    while (choice != 8);
    return 0;
}
