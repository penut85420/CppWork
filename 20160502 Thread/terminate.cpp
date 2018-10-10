#include <iostream>
#include <thread>
using namespace std;

void foo() {
	for (int i = 0; i < 10; i++)
		cin >> i;
}

int main() {
	thread t(foo);
	if (cin.get()) terminate();
	t.join();

	cout << "hi";

	return 0;
}
