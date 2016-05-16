#include "main.h"

Point::Point(int x, int y)
	: mX(x), mY(y) { }

Point::Point() { };

Point Point::operator+(const Point &rhs) const {
	return Point (mX + rhs.mX, mY + rhs.mY);
}

Point Point::operator-(const Point &rhs) const {
	return Point (mX - rhs.mX, mY - rhs.mY);
}

bool Point::isInside(Rect rect) const {
	if (mX <= rect.getBoundary(Side::Left)) return false;
	if (mX >= rect.getBoundary(Side::Right)) return false;
	if (mY <= rect.getBoundary(Side::Top)) return false;
	if (mY >= rect.getBoundary(Side::Bottom)) return false;
	return true;
}

Side Point::touchSide(Rect rect) {
	if (mX <= rect.getBoundary(Side::Left)) return Side::Left;
	if (mX >= rect.getBoundary(Side::Right)) return Side::Right;
	if (mY <= rect.getBoundary(Side::Top)) return Side::Top;
	if (mY >= rect.getBoundary(Side::Bottom)) return Side::Bottom;
	return Side::nonTouch;
}

Side Point::touchHor(Rect rect) const {
	if (mX <= rect.getBoundary(Side::Left) + 1) return Side::Hor;
	if (mX >= rect.getBoundary(Side::Right) - 1) return Side::Hor;
	return Side::nonTouch;
}

Side Point::touchVer(Rect rect) const {
	if (mY <= rect.getBoundary(Side::Top) + 1) return Side::Ver;
	if (mY >= rect.getBoundary(Side::Bottom) - 1) return Side::Ver;
	return Side::nonTouch;
}

void Point::print() {
	std::cout << mX <<  " " << mY;
}

void Point::draw(const char face) {
	gotoxy(mX, mY);
	std::cout << face;
}

bool Point::isOrigin() const {
	if (!mX && !mY) return true;
	return false;
}

void Point::reside(Side s) {
	if (s == Side::Hor) mX = -mX;
	if (s == Side::Ver) mY = -mY;
}

void Point::rotate() {
	int newX = -mY, newY = mX;
	mX = newX;
	mY = newY;
}

bool Point::operator==(const Point &rhs) const {
	if (rhs.mX != mX) return false;
	if (rhs.mY != mY) return false;
	return true;
}