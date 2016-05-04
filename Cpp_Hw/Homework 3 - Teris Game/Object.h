#pragma once

#include "main.h"

class Object {
private:
	const char mFace;
	Point mPosition;
	Point *mShape;
	const int mNumShape;
public:
	Object(const char, Point, Point[], const int);
	Side touchHor(const Rect);
	Side touchVer(const Rect);
	bool isInside(const Rect);
	void draw(bool = true);
	bool move(Point&, const Rect, bool = false);
	void rotate(const Rect);
};
