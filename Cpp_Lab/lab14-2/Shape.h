#pragma once
#include <iostream>

class Shape {
public:
	virtual float area() const = 0;
	virtual float volume() const = 0;
	virtual void display(std::ostream&) const = 0;
};