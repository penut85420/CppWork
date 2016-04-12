#ifndef INTERFACE_H
#define INTERFACE_H
#include "Class.h"
enum Menu {
	Main = 2,
	Operation = 8
};

int displayMenu(Menu, const char[]);

#endif