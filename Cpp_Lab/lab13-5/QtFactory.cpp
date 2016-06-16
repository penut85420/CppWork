#include "QtFactory.h"

QtFactory::QtFactory(void) { }

QtFactory::~QtFactory(void) { }

yayButton* QtFactory::createButton() {
	return new QtButton();
}

yayMenu* QtFactory::createMenu() {
	return new QtMenu();
}