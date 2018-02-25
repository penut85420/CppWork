#include "Point.h"

Point::Point(float x, float y, float z) {
	this->x = x; this->y = y; this->z = z;
}

float Point::area() const {
	return 0.0;
}

float Point::volume() const {
	return 0.0;
}

void Point::display(std::ostream &os) const {
	os << "Point[" << x << ", " << y << ", " << z << "]";
}