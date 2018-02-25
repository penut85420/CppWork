#pragma once
#include "Shape.h"
#include "Circle.h"

class Cylinder: public Shape {
public:
    Cylinder(float = 0., float = 0., float = 0., float = 0., float = 0.);
    float area() const;
    float volume() const;
	void display(std::ostream&) const;

private:
    float mHeight;
	Circle mTopCircle, mBottomCircle;
};