#pragma once

#include "main.h"

class Object {
private:
	char mFace;
	Point mPosition;
	Point *mShape;
	int mNumShape;
	bool isRotatable;
public:
	_Object(const char, Point, Point[], const int, bool = true);
	_Object(const Object&);
	_Object();
	_Side touchHor(const Rect);
	_Side touchVer(const Rect);
	_bool isInside(const Rect);
	_void draw(bool = true);
	bool move(Point&, const Rect);
	void rotate(const Rect);
	void add(Object);
	void changeFace(char);
	bool touchObject(const Object, const Point);
	void print();
};
