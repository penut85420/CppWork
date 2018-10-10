#include <iostream>
#include <thread>
#include <windows.h>
#include <conio.h>

using namespace std;

char buff[256], top = 0;

void newLine() {
    cout << "\r              \r";
}

void setLine() {
	cout << buff;
}

void foo() {
	Sleep(1000);
	newLine();
	cout << "HI" << endl;
	setLine();
}

void bar() {
	Sleep(2000);
	newLine();
	cout << "Hello" << endl;
	setLine();
}

void Receiver();
void Sender();

int main() {
	thread t1(bar), t2(foo);

	while ((buff[top++] = getche()) != 13) {
		buff[top] = 0;
		if (buff[top - 1] == 8) {
			cout << " \b";
			--top;
			buff[--top] = 0;
		}
	}
	buff[top - 1] = 0;
	cout << "[" << buff << "] Exit\n";

	cout << "End" << endl;
	t1.join(); t2.join();
	return 0;
}
