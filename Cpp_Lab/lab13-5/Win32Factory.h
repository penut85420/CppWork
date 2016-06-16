#pragma once
#include "AbstractFactory.h"
#include "yayButton.h"
#include "yayMenu.h"
#include "Win32Button.h"
#include "Win32Menu.h"

class Win32Factory : public AbstractFactory {
public:
	Win32Factory(void);
	~Win32Factory(void);
	yayButton* createButton();
	yayMenu* createMenu();
};

