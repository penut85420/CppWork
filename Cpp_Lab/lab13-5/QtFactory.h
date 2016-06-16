#pragma once
#include "AbstractFactory.h"
#include "yayButton.h"
#include "yayMenu.h"
#include "QtButton.h"
#include "QtMenu.h"

class QtFactory : public AbstractFactory {
public:
	QtFactory(void);
	~QtFactory(void);
	yayButton* createButton();
	yayMenu* createMenu();
};

