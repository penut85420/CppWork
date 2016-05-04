#include "main.h"

Object::Object(const char face, Point position, Point shape[], const int num)
	: mFace(face), mPosition(position),
	  mNumShape(num), mShape(shape) { }

bool Object::isInside(const Rect canvas) {
	for (int i = 0; i < mNumShape; i++)
		if (!(mShape[i] + mPosition).isInside(canvas))
			return false;
	return true;
}

Side Object::touchHor(const Rect canvas) {
	for (int i = 0; i < mNumShape; i++)
		if ((mShape[i] + mPosition).touchHor(canvas) != Side::nonTouch) return Side::Hor;
	return Side::nonTouch;
}

Side Object::touchVer(const Rect canvas) {
	for (int i = 0; i < mNumShape; i++)
		if ((mShape[i] + mPosition).touchVer(canvas) != Side::nonTouch) return Side::Ver;
	return Side::nonTouch;
}

void Object::draw(bool type) {
	char face = type? mFace: ' ';
	for (int i = 0; i < mNumShape; i++)
		(mShape[i] + mPosition).draw(face);
}

bool Object::move(Point &offset, const Rect rect, bool isBound) {
	if (offset.isOrigin()) return true;
	Point newPosition = offset + mPosition;
	
	Object newObject(mFace, newPosition, mShape, mNumShape);
	if (newObject.isInside(rect)) {
		draw(false);
		mPosition = newPosition;
		draw();
		return true;
	} 
	if (isBound) {
		offset.reside(newObject.touchHor(rect));
		offset.reside(newObject.touchVer(rect));
		return true;
	}
	return false;
}

void Object::rotate(const Rect rect) {
	Point step[4];
	step[Side::Top] = Point(0, 1);
	step[Side::Bottom] = Point(0, -1);
	step[Side::Left] = Point(1, 0);
	step[Side::Right] = Point(-1, 0);
	draw(false);
	for (int i = 0; i < mNumShape; i++)
		mShape[i].rotate();
	for (int i = 0; i < mNumShape; i++) {
		if ((mShape[i] + mPosition).touchSide(rect) != Side::nonTouch) {
			move(step[(mShape[i] + mPosition).touchSide(rect)], rect, true);
			cout << mShape[i].touchSide(rect);
			system("PAUSE");
		}
	}
	draw();
}