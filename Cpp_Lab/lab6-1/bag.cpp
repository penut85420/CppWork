#include "main.h"

Bag::Bag(Ball::Colors color1, Ball::Colors color2, Ball::Colors color3) {
	m_balls[0] = new Ball(color1);
	m_balls[1] = new Ball(color2);
	m_balls[2] = new Ball(color3);
	m_numberOfBalls = 3;
}

Bag::Bag(Bag &b) {
	m_numberOfBalls = b.m_numberOfBalls;
	m_balls[0] = b.m_balls[0];
	m_balls[1] = b.m_balls[1];
	m_balls[2] = b.m_balls[2];
}

Bag::~Bag() {
	delete m_balls[0];
	delete m_balls[1];
	delete m_balls[2];
}

Ball *Bag::getABall() {
	if (m_numberOfBalls == 0) return 0;
	int iPicked = rand() % m_numberOfBalls;

	Ball *pickedBall = m_balls[iPicked];

	m_balls[iPicked] = m_balls[m_numberOfBalls - 1];

	m_balls[m_numberOfBalls - 1] = pickedBall;

	m_numberOfBalls--;

	return pickedBall;

}

void Bag::putBallsBack() {
	m_numberOfBalls = 3;
}
