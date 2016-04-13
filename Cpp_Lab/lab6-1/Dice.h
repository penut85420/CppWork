#ifndef DICE_H
#define DICE_H
#include "main.h"

class Dice {
private:
	double *pr;

public:
	Dice(int[]);
	~Dice();
	int randomThrow();
	void unitTest();
};

#endif
