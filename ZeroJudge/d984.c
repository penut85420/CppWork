#include <stdio.h>

int main() {
	int n[3], i, max, sum;

	while (scanf("%d %d %d", &n[0], &n[1], &n[2]) != EOF) {
		max = 0;
		sum = n[0];
		for (i = 1; i < 3; i++) {
			sum += n[i];
			if (n[i] > n[max]) max = i;
		}
		if (n[max] > sum / 2) printf("%c", max + 'A')
	}
}