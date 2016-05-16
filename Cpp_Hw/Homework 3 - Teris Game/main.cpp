#include "main.h"

void main()
{
    const int orgX = 5, orgY = 0, width = 25, height = 20;
    const Rect canvas(orgX, orgY, width, height);
	bool pause = false;
	Point offset(0, 1), 
		orgin[2] = {Point(orgX + width / 2 - 1, orgY + 1), 
					Point(orgX + width / 2 - 1, orgY + 2)},
		shape[7][4] = {
			{Point(0, 0), Point(0, 1), Point(1, 0), Point(1, 1)},    // Square
			{Point(0, 0), Point(0, 1), Point(0, 2), Point(0, -1)},   // Stick
			{Point(0, 0), Point(1, 0), Point(0, 1), Point(0, 2)},    // Twist L
			{Point(0, 0), Point(-1, 0), Point(0, 1), Point(0, 2)},   // L 
			{Point(0, 0), Point(0, 1), Point(1, -1), Point(1, 0)},   // S
			{Point(0, 0), Point(0, 1), Point(-1, -1), Point(-1, 0)}, // Twist S
			{Point(0, 0), Point(0, 1), Point(1, 0), Point(0, -1)}    // T
		};
	Object **ObjList = new Object*[7], *stuck = NULL, *obj = NULL;
	Order order;
	int orginFix[] = {0, 1, 0, 0, 1, 1, 1};
	char face[] = "QILJSMT";
	bool rotatable[7];

	rotatable[0] = false;
	for (int i = 1; i < 7; i++)
		rotatable[i] = true;

	for (int i = 0; i < 7; i++)
		ObjList[i] = new Object(face[i], orgin[orginFix[i]], shape[i], 4, rotatable[i]);

	clrscr();
    canvas.drawBoundary();
	obj = new Object(*ObjList[order.next()]);
	obj->draw();

    while (1) {
		if (stuck != NULL) {
			if (!obj->touchObject(*stuck, offset)) {
				stuck->add(*obj);
				delete obj;
				obj = new Object(*ObjList[order.next()]);
				obj->draw();
				if (!obj->touchObject(*stuck, offset)) break;
			}
			if (stuck->touchVer(canvas) == Side::Top) {
				break;
			}
		} 
		if (!obj->move(pause? Point(0, 0): offset, canvas)) {
			if (stuck == NULL) stuck = new Object(*obj);
			else stuck->add(*obj);
			stuck->changeFace('A' + rand() % 26);
			delete obj;
			obj = new Object(*ObjList[order.next()]);
			obj->draw();
			if (!obj->touchObject(*stuck, offset)) break;
		}

		obj->draw();
		canvas.drawBoundary();

		if (kbhit()) {
			int cmd = getch();
			if (cmd == 0xE0 || !cmd)
				cmd = getch();
			if (cmd == 112) pause = !pause;
			else if (cmd == 75 && !pause) obj->move(Point(-1, 0), canvas);
			else if (cmd == 77 && !pause) obj->move(Point(1, 0), canvas);
			else if (cmd == 72 && !pause) obj->rotate(canvas);
			else if (cmd == 80 && !pause) 
				while (obj->move(offset, canvas))
					if (stuck != NULL)
						if (!obj->touchObject(*stuck, offset)) 
							break;
			else if (cmd == 27) break;
		}
		delay(200);
	}

    gotoxy(1, 23);
	system("PAUSE");
}