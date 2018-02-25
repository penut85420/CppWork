#include "Circle.h"

Circle::Circle(float r, float x, float y, float z)
	: mCenter(x, y, z), mRadius(r), PI((float)3.141159) { }

float Circle::area() const { 
	return PI * mRadius * mRadius; 
}

float Circle::volume() const {
	return 0.0;
}

float Circle::getRadius() const { 
	return mRadius; 
}

void Circle::display(std::ostream &os) const {
	os << "Circle(Radius = " << mRadius << ", Center: "; 
	mCenter.display(os); os << ")";
}

float Circle::perimeter() const {
	return 2 * PI * mRadius;
}