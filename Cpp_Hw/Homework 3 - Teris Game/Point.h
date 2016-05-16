#pragma once

#include "main.h"

class Point {
private:
	int mX, mY;
public:
	Point();
	Point(int, int);
	Point operator+(const Point&) const;
	Point operator-(const Point&) const;
	bool operator==(const Point&) const;
	bool isInside(Rect) const;
	Side touchHor(Rect) const;
	Side touchVer(Rect) const;
	Side touchSide(Rect);
	void print();
	void draw(const char);
	bool isOrigin() const;
	void reside(Side);
	void rotate();
};