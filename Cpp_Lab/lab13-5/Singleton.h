#pragma once
#include "AbstractFactory.h"

class Singleton {
public:
	Singleton(void);
	~Singleton(void);
	Singleton* getInstance();

private:
	Singleton(Singleton&);
	void operator=(Singleton&);
	static Singleton mInstance;
};

