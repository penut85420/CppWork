#include "Win32Factory.h"


Win32Factory::Win32Factory(void) { }


Win32Factory::~Win32Factory(void) { }

yayButton* Win32Factory::createButton() {
	return new Win32Button();
}

yayMenu* Win32Factory::createMenu() {
	return new Win32Menu();
}