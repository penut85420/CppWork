#ifndef game_h
#define game_h
#include "Bag.h"
#include "main.h"

class Game {
public:
	Bag *getABag();
	Game();
	~Game();
	void unitTest();
	void test2();
private:
	Bag *m_bags[4];
	const int m_numberOfBags;
};

#endif
