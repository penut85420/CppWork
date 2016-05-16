//#include "main.h"

Object::Object(const char face, Point position, Point shape[], const int num, bool isRotatable)
	: mFace(face), mPosition(position), mNumShape(num),
	mShape(shape), isRotatable(isRotatable) { }

Object::Object(const Object &rhs) {
	mFace = rhs.mFace;
	mPosition = rhs.mPosition;
	mNumShape = rhs.mNumShape;
	mShape = new Point[mNumShape];
	for (int i = 0; i < mNumShape; i++)
		mShape[i] = rhs.mShape[i];
	isRotatable = rhs.isRotatable;
}

Object::Object() { };

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

bool Object::move(Point &offset, const Rect rect) {
	if (offset.isOrigin()) return true;
	Point newPosition = offset + mPosition;
	
	Object newObject(mFace, newPosition, mShape, mNumShape);
	if (newObject.isInside(rect)) {
		draw(false);
		mPosition = newPosition;
		draw();
		return true;
	} 
	return false;
}

void Object::rotate(const Rect rect) {
	cout << isRotatable;
	if (!isRotatable) return;
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
			move(step[(mShape[i] + mPosition).touchSide(rect)], rect);
			rect.drawBoundary();
		}
	}
	draw();
}

void Object::add(Object obj) {
	Point *newShape = new Point[mNumShape + obj.mNumShape];
	for (int i = 0; i < mNumShape; i++)
		newShape[i] = mShape[i];

	for (int i = 0; i < obj.mNumShape; i++) {
		newShape[mNumShape + i] = obj.mShape[i] + obj.mPosition - mPosition;

	}
	mShape = newShape;
	mNumShape += obj.mNumShape;
}

void Object::changeFace(char c) {
	mFace = c;
	draw();
}

bool Object::touchObject(const Object obj, const Point offset) {
	Point newPosition = mPosition + offset;
	for (int i = 0; i < mNumShape; i++)
		for (int j = 0; j < obj.mNumShape; j++)
			if (newPosition + mShape[i] == obj.mPosition + obj.mShape[j])
				return false;
	return true;
}

void Object::print() {
	cout << mFace
		<< mNumShape << endl;
	for (int i = 0; i < mNumShape; i++)
		mShape[i].print();
}