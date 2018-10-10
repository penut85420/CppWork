#include <pthread.h>
#include <stdio.h>
#include <windows.h>

int f(int);

int main() {
	pthread_t id;

	pthread_create(&id, NULL, (void *) f, 20);
	printf("hello");
	pthread_join(id, NULL);
	return 0;
}

int f(int a) {
	Sleep(1000);
	printf(", %d\n", a);
	return a * 10;
}
