#include <iostream>
using namespace std;
    
#include "Point.h"
#include "Circle.h"
#include "Cylinder.h"
    
void main()
{
    Point point1(1,2,3), point2(4,5,6);
    Circle circle(5, 2,0,-2);
    Cylinder cylinder1(5, 3, 0,0,0), cylinder2(4, 2, 1,1,1);
    Shape *shapes[] = {&point1, &point2, &circle, &cylinder1, &cylinder2};
        
    for (int i = 0; i < 5; i++) {
        shapes[i]->display(cout);
        cout << endl;
        cout << "   Area: " << shapes[i]->area();
        cout << "   Volume: " << shapes[i]->volume() << endl;
    }
	cin.get();
}