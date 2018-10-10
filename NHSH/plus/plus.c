#include <stdio.h>

int main() {
	int i, j;
	int N, M, m, s;
	int sum, best;

	scanf("%d", &N);

	for (i = 0; i < N; i++) {
		scanf("%d", &M);
		sum = 0; best = -1;
		for (j = 0; j < M; j++) {
			scanf("%d %d", &m, &s);
			int now = m * 60 + s;
			sum += now;
			if (best == -1 || now < best) best = now;
		}
		int avg = sum / M;
		printf("Track %d:\n", i + 1);
		printf("Best Lap: %d minute(s) %d second(s).\n", best / 60, best % 60);
		printf("Average: %d minute(s) %d second(s).\n", avg / 60, avg % 60);
	}

	return 0;
}