#pragma once
#include "Shape.h"
#include "Point.h"

class Point;
class Circle: public Shape {
public:
    Circle(float = 0., float = 0., float = 0., float = 0.);
    float area() const;
	float volume() const;
    float getRadius() const;
	void display(std::ostream&) const;
	float perimeter() const;

private:
    float mRadius;
	Point mCenter;
	const float PI;
};