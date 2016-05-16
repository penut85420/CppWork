#include "main.h"


Order::Order(void) {
	for (int i = 0; i < 7; i++)
		order[i] = i;
	newOrder();
	now = 0;
}


Order::~Order(void) { }

void Order::newOrder() {
	for (int i = 0; i < 7; i++) {
		int r = rand() % 7;
		int t = order[r];
		order[r] = order[i];
		order[i] = t;
	}
}

int Order::next() {
	if (now > 6) {
		now = 0;
		newOrder();
	}

	return order[now++];
}

int Order::pop() {
	return order[now];
}