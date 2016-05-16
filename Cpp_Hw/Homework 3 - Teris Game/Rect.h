#pragma once


enum Side {
	Top, Bottom, Right, Left,
	Hor, Ver, nonTouch
};

class Rect {
private:
	int mLeft, mTop, mWidth, mHeight;
public:
	Rect(int, int, int, int);
	void drawBoundary() const;
	int getBoundary(Side);
};
