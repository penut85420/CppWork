#include <stdio.h>

int main() {
	int h;
	int i, j, k;
	
	printf("Height of triangle: ");
	scanf("%d", &h);

	for (i = 1; i <= h; i++) {
		for (j = 0; j < h - i; j++)
			printf(" ");
		for (j = 0; j < i * 2 - 1; j++)
			printf("*");
		printf("\n");
	}

	return 0;
}