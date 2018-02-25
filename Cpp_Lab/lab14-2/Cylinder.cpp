#include "Cylinder.h"

Cylinder::Cylinder(float h, float r, float x, float y, float z):
	mTopCircle(r, x, y, z), mBottomCircle(r, x, y, z + h), mHeight(h) { }

float Cylinder::area() const {
	return 2 * mTopCircle.area() + mHeight * mTopCircle.perimeter();
}

float Cylinder::volume() const {
	return mTopCircle.area() * mHeight;
}

void Cylinder::display(std::ostream &os) const {
	os << "Cylinder<";
	os << "Height = " << mHeight << "\n\t";
	os << "Top Circle: "; mTopCircle.display(os); os << "\n\t";
	os << "Bottom Circle: "; mBottomCircle.display(os); os << ">";
}