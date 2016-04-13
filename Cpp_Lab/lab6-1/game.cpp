#include "main.h"

Game::Game(): m_numberOfBags(4) {
	m_bags[0] = new Bag(Ball::Red, Ball::Red, Ball::Red);
	m_bags[1] = new Bag(Ball::Red, Ball::Red, Ball::White);
	m_bags[2] = new Bag(Ball::Red, Ball::White, Ball::White);
	m_bags[3] = new Bag(Ball::White, Ball::White, Ball::White);
}

Game::~Game() {
	for (int i = 0; i < m_numberOfBags; i++)
		delete m_bags[i];
}

Bag *Game::getABag() {
	int r = rand() % m_numberOfBags;
	Bag* b = m_bags[r];
	return b;
}

void Game::unitTest() {
	Bag  *pickedBag;
	Ball *pickedBall;
	int   totalCount = 0, i,
		  secondIsAlsoRed = 0,
		  thirdIsAlsoRed = 0;

	srand((unsigned int)time(0));

	for (i = 0; i < 10000; i++) {
		pickedBag = getABag();
		pickedBall = pickedBag->getABall();
		if (pickedBall->isRed()) {
			totalCount++;
			if (pickedBag->getABall()->isRed()) {
				secondIsAlsoRed++;
				if (pickedBag->getABall()->isRed()) {
					thirdIsAlsoRed++;
				}
			}
		}
		pickedBag->putBallsBack();
	}

	cout << "The probability that the ball is white at step 4 = "
		 << ((double)thirdIsAlsoRed / secondIsAlsoRed) << endl;
	cout << thirdIsAlsoRed << endl;
	system("pause");
}

void Game::test2() {
	Bag *pickedBag;
	Ball *pickedBall;
	int total = 0, 
		dm1[] = {6, 6, 6, 6, 6, 6},
		dm2[] = {4, 6, 6, 6, 6, 12};
	Dice dice[2] = {dm1, dm2};

	srand((unsigned int)time(0));

	for (int i = 0; i < 100000; i++) {
		do {
			pickedBag = getABag();
			pickedBag->putBallsBack();
			pickedBall = pickedBag->getABall();
		} while (pickedBall->isRed());
		while (dice[rand() % 2].randomThrow() % 2);
		pickedBag->getABall();
		if (!pickedBag->getABall()->isRed()) 
			total++;
	}
	cout << "The probability that the ball is white at step 4 = "
		 << (double)total / 100000 << endl;
	system("PAUSE");
}