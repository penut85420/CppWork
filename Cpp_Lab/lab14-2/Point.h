#pragma once
#include "Shape.h"

class Point : public Shape {
public:
    Point(float = 0., float = 0., float = 0.);
    float getX() const { return x; }
    float getY() const { return y; }
    float getZ() const { return z; }
	float area() const;
	float volume() const;
	void display(std::ostream&) const;

private:
    float x, y, z;
};