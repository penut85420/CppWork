#pragma once
#include "yayButton.h"
#include "yayMenu.h"
#include <string>

class AbstractFactory {
public:
	AbstractFactory(void);
	~AbstractFactory(void);
	virtual yayButton* createButton();
	virtual yayMenu* createMenu();
	static AbstractFactory *getInstance(std::string platform);
};

