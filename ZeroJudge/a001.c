#include <stdio.h>

int main() {
	char str[256];

	while (scanf("%s", str) != EOF) {
		printf("hello, ");
		printf("%s", str);
		printf("\n");
	}

	return 0;
}