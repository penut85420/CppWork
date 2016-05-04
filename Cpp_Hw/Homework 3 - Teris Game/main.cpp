#include "main.h"

void main()
{
    const int orgX = 5, orgY = 5, width = 25, height = 16;
    const Rect canvas(orgX, orgY, width, height);
	bool pause = false;
	Point offset(0, 1);
    clrscr();
    canvas.drawBoundary();
    Point shape[4] = { Point(0, 0), Point(0, 1),
                             Point(1, 0), Point(2, 0) };
    Object obj('T', Point(orgX + width / 2 - 1, orgY + 1), shape, 4);
    assert(obj.isInside(canvas));

    obj.draw();
    while (obj.move(pause? Point(0, 0): offset, canvas, true)){
		if (kbhit()) {
			int cmd = getch();
			if (cmd == 0xE0 || !cmd)
				cmd = getch();
			if (cmd == 112) pause = !pause;
			else if (cmd == 75 && !pause) obj.move(Point(-1, 0), canvas);
			else if (cmd == 77 && !pause) obj.move(Point(1, 0), canvas);
			else if (cmd == 72 && !pause) obj.rotate(canvas);
			else if (cmd == 27) break;
		}
		delay(100);
	}

    gotoxy(1, 23);
	system("PAUSE");
}

