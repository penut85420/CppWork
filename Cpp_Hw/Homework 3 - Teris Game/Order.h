#pragma once
class Order {
private:
	int order[7];
	int now;
	void newOrder();

public:
	Order(void);
	~Order(void);
	int next();
	int pop();
};

