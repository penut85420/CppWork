#include "main.h"

Rect::Rect(int left, int top, int width, int height)
	: mLeft(left), mTop(top),
	  mWidth(width), mHeight(height) { }

void Rect::drawBoundary() const {
	const char CR = 'O', RL = 'O', TD = 'O';

	gotoxy(mLeft, mTop);
	cout << CR;
	for (int i = 1; i < mWidth; i++)
		cout << TD;
	cout << CR;

	gotoxy(mLeft, mTop + mHeight);
	cout << CR;
	for (int i = 1; i < mWidth; i++)
		cout << TD;
	cout << CR;

	for (int i = 1; i < mHeight; i++) {
		gotoxy(mLeft, mTop + i);
		cout << RL;
		gotoxy(mLeft + mWidth, mTop + i);
		cout << RL;
	}
}


int Rect::getBoundary(Side side) {
	if (side == Side::Top) return mTop;
	if (side == Side::Bottom) return mTop + mHeight;
	if (side == Side::Right) return mLeft + mWidth;
	if (side == Side::Left) return mLeft;
}
