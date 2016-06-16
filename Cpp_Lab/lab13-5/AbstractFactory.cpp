#include "AbstractFactory.h"


AbstractFactory::AbstractFactory(void) { }

AbstractFactory::~AbstractFactory(void) { }

AbstractFactory* AbstractFactory::getInstance(std::string platform) {
	if (platform == "Qt")
		return QtFactory::getInstance();
}